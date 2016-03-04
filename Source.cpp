#include <iostream>
#include <string>

using namespace std;

int main()
{

	//Input -> delimiter: " " or space 
	int n[100];
	int Length;
	cout << "Insert length: ";
	cin >> Length;
	cout << "please insert array values:";
	for (int i = 1; i < Length; i++)
	{
		cin >> n[i];
	}

	//Min of values : 
	int min = n[1];


	//Quartiles of values:
	double q1, q2, q3;

	int half = (Length / 2);
	//if length is even
	if (Length % 2 == 0)
	{
		double sum = (n[half] + n[half + 1]);
		q2 = sum / 2;

		if ((Length / 2) % 2 == 0)
		{
			double sum1 = (n[half / 2] + n[(half / 2) + 1]);
			double sum3 = (n[((Length + half) / 2)] + n[((Length + half) / 2) + 1]);
			q1 = sum1 / 2;
			q3 = sum3 / 2;
		}
		else
		{
			q1 = n[(half / 2) + 1];
			q3 = n[((Length + half) / 2) + 1];
		}
	}
	//if length is odd
	if (Length % 2 == 1)
	{
		q2 = n[half + 1];
		if ((Length / 2) % 2 == 0)
		{
			double sum1 = (n[half / 2] + n[(half / 2) + 1]);
			double sum3 = (n[((Length + half + 1) / 2)] + n[((Length + half + 1) / 2) + 1]);
			q1 = sum1 / 2;
			q3 = sum3 / 2;
		}
		else
		{
			q1 = n[(half / 2) + 1];
			q3 = n[((Length + half) / 2) + 1];
		}

	}





	//max of values :
	int max = 0;
	for (int i = 0; i < Length; i++)
	{
		if (n[i] > max)
			max = n[i];
	}
	//outliers:
	double IQR, out1, out2;
	IQR = q3 - q1;
	out1 = q1 - 1.5*IQR;
	out2 = q3 + 1.5*IQR;

	cout << "min:" << min << endl;
	cout << "q1:" << q1 << endl;
	cout << "q2:" << q2 << endl;
	cout << "q3:" << q3 << endl;
	cout << "max:" << max << endl;
	cout << "IQR:" << IQR << endl;
	cout << "outlier: ";
	for (int i = 0; i < Length; i++)
	{
		if (n[i]<out1 || n[i]>out2)
			cout << n[i] << " , ";
		else {
			cout << "no outlier";
			break;
		}
	}




	return 0;

}

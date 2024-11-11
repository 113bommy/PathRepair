#include<iostream>
#include<string>
#include<vector>
#include<math.h>
using namespace std;

int main()
{
	string line;
	while (cin >> line)
	{
		if (line.compare("#") == 0)break;
		int index = line.size() - 1;
		vector<char> v;
		while (index >= 0)
		{
			if (line.at(index) == 'h')
			{
				index -= 5;
				v.push_back('h');
			}
			else if (line.at(index) == 't')
			{
				index -= 4;
				v.push_back('t');
			}
		}

			int angle = 0;
			int l = pow(2, v.size() - 1);
			if (v.at(0) == 't')
			{
				angle = 90 * l;
			}
			for (int i = 1; i < v.size(); i++)
			{
				if (v.at(i) == 'h')
				{
					angle -= 90 * l / pow(2, i);
				}
				else
				{
					angle += 90 * l / pow(2, i);
				}
			}

			while (l != 1 && angle % 2 == 0)
			{
				angle /= 2;
				l /= 2;
			}

			if (l > 1)
			{
				cout << angle << "/" << l << endl;
			}
			else
			{
				cout << angle << endl;
			}
		}
	return 0;
}
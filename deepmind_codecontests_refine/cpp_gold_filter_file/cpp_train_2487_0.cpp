#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	long long n, t, v[65000], sum;

	while (true)
	{
		cin >> n;

		if (n == 0) { break; }

		sum = 0;

		for (int i = 0; i < n; i++)
		{
			cin >> t;

			sum += t;
		}
		
		for (int j = 0; j < n - 1; j++)
		{
			cin >> v[j];

			sum += v[j];
		}

		sort(v, v + n - 1);

		int ptr = 0;

		while(ptr++ < n - 1)
		{
			if (ptr * sum < (ptr + 1) * (sum - v[ptr - 1]))
			{
				sum -= v[ptr - 1];
			}
			else
			{
				break;
			}
		}
		
		cout << ptr * sum << endl;
	}

	return 0;
}
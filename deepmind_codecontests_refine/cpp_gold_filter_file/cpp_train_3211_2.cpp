#include <iostream>

using namespace std;

int main()
{
	int  i, n, w, a, b;
	cin >> n >> w >> w;
	if (n > 1)
	{
		for (i = 0; i < n - 1; i++)
			scanf("%d",&a);
		cin >> b;
		n = (abs(b - w) < abs(a - b)) ? abs(a - b) : abs(b - w);
		cout << n;
	}
	else
	{
		cin >> a;
		cout << abs(a - w);
	}
}
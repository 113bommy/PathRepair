#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define N 100010
int n;
int a[N];

void end(int x)
{
	if (x == 1) puts ("First");
	else puts ("Second");
	exit(0);
}

int gcd(int x, int y)
{
	while(x)
	{
		int z = x;
		x = y % x;
		y = z;
	}
	return y;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i ++)
        cin >> a[i];
	int x = 1;
	while (1)
	{
		ll S = 0;
		int odd = 0, F1 = 0;
		for (int i = 0; i < n; i ++)
		{
			if (a[i] & 1) odd ++;
			S += a[i];
			if (a[i] == 1) F1 ++;
		}
		if ((S - n) % 2 == 1) end(x);
		if (odd >= 2 || F1 > 0) end(3 - x);
		int g = 0;
		for (int i = 0; i < n; i ++)
			if (a[i] & 1) g = gcd(g, a[i]-1);
			else g = gcd(g, a[i]);
		for (int i = 0; i < n; i ++) a[i] /= g;
		x = 3 - x;
	}
	return 0;
}

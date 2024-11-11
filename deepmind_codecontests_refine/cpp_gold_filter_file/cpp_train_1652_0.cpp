#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

inline int gi()
{
	char c = getchar();
	while (c < '0' || c > '9') c = getchar();
	int sum = 0;
	while ('0' <= c && c <= '9') sum = sum * 10 + c - 48, c = getchar();
	return sum;
}

int n;

int main()
{
	double d, x;
	n = gi();
	scanf("%lf%lf", &d, &x);
	double ans = 0;
	++n;
	while ((n--) > 1) {
		ans += d + (n - 0.5) * x;
		d = (5 * x + (2 * n + 2) * d) / (2 * n);
		x = (2 * n + 4) * x / 2 / n;
	}
	printf("%.10lf\n", ans);
	
	return 0;
}

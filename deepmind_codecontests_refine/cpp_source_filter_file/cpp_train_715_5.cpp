#include <bits/stdc++.h>

using namespace std;

int n, m;
int d[1000];
int c[1000];

int memo[1000][1000];

int rec(int day, int now)
{
	if (now == n) return 0;

	if (memo[day][now] >= 0) return memo[day][now];

	lli res;

	if (n - now < m - day) {
		res = min(rec(day + 1, now + 1) + d[now] * c[day], rec(day + 1, now));
	} else {
		res = rec(day + 1, now + 1) + d[now] * c[day];
	}

	return memo[day][now] = res;
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		cin >> d[i];
	}

	for (int i = 0; i < m; ++i) {
		cin >> c[i];
	}

	memset(memo, -1, sizeof(memo));

	printf("%d\n", rec(0, 0));
}
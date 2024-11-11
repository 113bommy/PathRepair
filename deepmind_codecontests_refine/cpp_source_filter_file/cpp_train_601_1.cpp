#include <stdio.h>
#include <iostream>

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)

using namespace std;

typedef int64_t ll;

const ll MOD = 1000000007;
const int MAX_N = 2010;

int ns, nt;
int s[MAX_N], t[MAX_N];
ll cum[MAX_N][MAX_N];

int main()
{
	cin >> ns >> nt;
	REP(i, ns) scanf_s("%d", s + i);
	REP(j, nt) scanf_s("%d", t + j);

	REP(i, MAX_N)
		cum[1][i] = cum[i][1] = 1;

	REP(i, ns)
		REP(j, nt)
	{
		ll dp = 0;
		if (s[i] == t[j])
			dp = cum[i + 1][j + 1];

		cum[i + 2][j + 2] = dp + cum[i + 1][j + 2] + cum[i + 2][j + 1] - cum[i + 1][j + 1];
		cum[i + 2][j + 2] = (cum[i + 2][j + 2] + MOD) % MOD;
	}

	cout << cum[ns + 1][nt + 1] << endl;
}

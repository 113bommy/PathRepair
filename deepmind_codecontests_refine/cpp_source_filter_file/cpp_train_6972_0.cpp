#include "bits/stdc++.h"
using namespace std;
#define mod 1000000007
#define all(c) begin(c),end(c)
template <typename T> T &chmin(T &a, const T &b) { return a = min(a, b); }
template <typename T> T &chmax(T &a, const T &b) { return a = max(a, b); }
using ll = long long;
using vi = vector<int>; using vs = vector<string>;
int dd[] = { 0, 1, 0, -1, 0 }; //→↓←↑

void solve()
{
	int N;
	while (cin >> N, N)
	{
		vi Bi(N + 1100, -1);
		vi A(N);
		vs S(N);
		for (int i = 0; i < N; i++)
		{
			cin >> S[i];
			for (int j = 0; j < S[i].size(); j++)
			{
				if (S[i][j] != '.')
				{
					A[i] = j;
					if (j > 0)S[i][j - 1] = '+';
					break;
				}
				else
				{
					S[i][j] = ' ';
				}
			}
			if (B[A[i]] >= 1)
			{
				bool flag = true;
				for (int j = B[A[i]] + 1; j < i; j++)
				{
					if (A[j] < A[i])flag = false;
				}
				if (flag)
				{
					for (int j = B[A[i]] + 1; j < i; j++)
					{
						S[j][A[i] - 1] = '|';
					}
				}
			}
			B[A[i]] = i;
		}
		for (int i = 0; i < N; i++)
		{
			cout << S[i] << endl;
		}
	}
}


int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	solve();
	return 0;
}

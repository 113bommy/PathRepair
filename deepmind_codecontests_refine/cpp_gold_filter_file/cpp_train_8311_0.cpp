#include<bits/stdc++.h>
using namespace std;

#define int long long
const int MAX_N = 100000;

int N, A[MAX_N];
vector<int> e[MAX_N];

int Solve(int n)
{
	vector<int> depths;
	for (int i = 0; i < e[n].size(); i++)
	{
		depths.push_back(Solve(e[n][i]));
	}
	sort(depths.begin(), depths.end());
	int res = 0;
	for (int i = 0; i < e[n].size(); i++)
	{
		res = max(res, depths[i] + (int)e[n].size() - i);
	}
	return res;
}

signed main()
{
	A[0] = -1;
	cin >> N;
	for (int i = 1; i < N; i++)
	{
		cin >> A[i]; A[i]--;
		e[A[i]].push_back(i);
	}
	printf("%lld\n", Solve(0));
	return 0;
}
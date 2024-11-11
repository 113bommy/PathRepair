#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(n) for ( int i =0; i < n ; i ++)
int N, M;
int P[100000], Y[100000];
vector < int > yd[100001];
int main()
{
	scanf("%d %d ", &N, &M);
	rep(M) scanf("%d %d", &P[i], &Y[i]), yd[P[i]].push_back(Y[i]);
	rep(N) sort(yd[i + 1].begin(), yd[i + 1].end());
	rep(M) printf("%012lld\n", ll(P[i]) * 1000000 + int(lower_bound(yd[P[i]].
		begin(), yd[P[i]].end(), Y[i]) - yd[P[i]].begin()) + 1);
}
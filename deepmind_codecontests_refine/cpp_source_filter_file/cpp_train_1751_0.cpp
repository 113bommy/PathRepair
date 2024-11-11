#include <cstdio>
#include <iostream>

struct range {
	int left;
	int right;
	long long left_mult;
	long long right_mult;
};
int N;
long long as[200008];
long long bs[200008];
using namespace std;
int comp(long long va, long long a_mult, long long vb, long long b_mult) {
	if(a_mult < b_mult) return -comp(vb, b_mult, va, a_mult);
	long long diff = a_mult - b_mult;
	for(int i=0;i<diff;i++) {
		va *= 2;
		if(va > vb) return 1;
	}
	if(va == vb) return 0;
	if(va > vb) return 1;
	return -1;
}
range ranges[200002];
long long update(int cur, long long *values) {
	if(ranges[cur].right == N) return 0;
	long long ret = 0;
	int next = ranges[cur].right + 1;
	if(comp(values[ranges[cur].right], ranges[cur].right_mult, values[ranges[next].left], ranges[next].left_mult) <= 0) return 0;
	while(comp(values[ranges[cur].right], ranges[cur].right_mult, values[ranges[next].left], ranges[next].left_mult) == 1) {
		ret += 2 * (ranges[next].right - ranges[next].left + 1);
		ranges[next].left_mult += 2;
		ranges[next].right_mult += 2;
	}
	ranges[cur].right = ranges[next].right;
	ranges[cur].right_mult = ranges[next].right_mult;
	return ret + update(cur, values);
}
void calc(int *dp, long long *values) {
	for(int i=1;i<=N;i++) {
		ranges[i].left = i;
		ranges[i].right = i;
		ranges[i].left_mult = 0;
		ranges[i].right_mult = 0;
	}
	for(int i = N - 1;i>0;i--) dp[i] = dp[i+1] + update(i, values); 
}
long long dp1[200008];
long long dp2[200008];
int main() {
	scanf("%d", &N);
	for(int i=1;i<=N;i++) {
		scanf("%lld", &as[i]);
		bs[N - i + 1] = as[i] * 2;
	}
	calc(dp1, as);
	calc(dp2, bs);
	for(int i=1;i<=N;i++) dp2[i] += N - i + 1;
	long long sol = dp1[1];
	for(int i=2;i<=N;i++) {
		if(sol > dp1[i] + dp2[N - i + 2]) sol = dp1[i] + dp2[N - i + 2];
	}
	printf("%lld\n", sol);
	return 0;
}
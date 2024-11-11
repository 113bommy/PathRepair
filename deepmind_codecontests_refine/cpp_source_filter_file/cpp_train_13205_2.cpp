#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[100], dp[100][100];
int calc(int l, int r, int n){
	int ans = 0;
	for(int i = l;i <= r;i++)ans += dp[n][i];
	return ans;
}

void init(){
	dp[0][0] = 1;
	for(int i = 1;i <= 51;i++){
		dp[i][0] = 1;
		for(int j = 1;j <= 51;j++)
		dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
	}
}

signed main(){
	init();
	int n, l, r;
	scanf("%lld%lld%lld", &n, &l, &r);
	for(int i = 1;i <= n;i++)scanf("%lld", &a[i]);
	sort(a+1, a+n+1, greater<int>());
	
	int sum = 0, s1 = 0, s2 = 0;
	for(int i = 1;i <= n;i++){
		if(i <= l)sum += a[i];
		if(a[i] > a[l])s1++;
		if(a[i] == a[l])s2++;
	}
	
	printf("%lf\n", (double)sum/l);
	if(s1 == 0)printf("%lld\n", calc(l, r, s2));
	elseprintf("%lld\n", dp[s2][l-s1]);
	return 0;
}
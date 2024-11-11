#include <bits/stdc++.h>
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 100000005
#define MAX 5001
using namespace std;
//__gcd(a,b), __builtin_popcount(a);

int dp[4001][4001];
int main(){
	string s1, s2;
	while(cin >> s1 >> s2){
	s1 = " " + s1;s2 = " " + s2;
	fill((int*)dp, (int*)(dp+4001), 0);
	int ans = 0;
	for(int i = 1;i < s1.size();i++){
		for(int j = 1;j < s2.size();j++){
			if(s1[i] == s2[j])dp[i][j] = dp[i-1][j-1]+1;
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans << endl;
	}
	return 0;
}
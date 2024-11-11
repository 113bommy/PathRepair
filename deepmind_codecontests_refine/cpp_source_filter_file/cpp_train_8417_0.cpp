#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int mod = 1e9+7;
int add(int a, int b) { return (a+b)%mod; }
int sub(int a, int b) { return (a-b+mod)%mod; }
int mult(int a, int b) { return (long long) a*b%mod; }
int n;
string s;
int dp[5005][5005];
int main() {
cin >> n >> s;
dp[0][s.length()] = 1;
for (int i=0;i<n;i++) {
for (int j=0;j<5004;j++) {
if (j==0) {
dp[i+1][0] = add(dp[i+1][0],dp[i][j]);
} else {
dp[i+1][j-1] = add(dp[i+1][j-1],dp[i][j]);
}
dp[i+1][1] = add(dp[i+1][1],mult(dp[i][j],2));
}
cout << dp[n][0];
}
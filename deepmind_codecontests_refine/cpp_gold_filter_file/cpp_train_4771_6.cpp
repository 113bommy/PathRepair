#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> w(1,1), dp(131072,n);
  for(int i = 1; i <= n; i *= 6) w.push_back(i);
  for(int i = 1; i <= n; i *= 9) w.push_back(i);
  dp[0]=0;
  for(auto x: w) for(int i = 0; i <= n-x; ++i) dp[i+x] = min(dp[i+x], dp[i]+1);
  cout << dp[n] << endl;
  return 0;
}
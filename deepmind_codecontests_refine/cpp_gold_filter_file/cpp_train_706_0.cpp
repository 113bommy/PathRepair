#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int main(){
  int n, k;
  cin >> n >> k;
  vector<int> pref(k+1), dp(k+1);
  dp[0] = 1;
  for(int kid = 1;kid<=n;kid++){
    int c;
    cin >> c;
    pref[0] = dp[0];
    for(int i=1; i<=k; ++i) {
      pref[i] = (pref[i-1] + dp[i]) % MOD;
      dp[i] = (pref[i] - (i-c>=0 ? pref[i-c-1] : 0)) % MOD;
    }
  }

  int ans = dp[k];
  if(ans < 0) ans += MOD; 
  printf("%d\n",ans);

  return 0;
}
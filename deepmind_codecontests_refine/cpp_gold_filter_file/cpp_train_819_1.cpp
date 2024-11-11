#include <bits/stdc++.h>
using namespace std;
#define Rep(i,N) for(int i = 0; i < N; i++)

int main()
{
  string S, W;
  while(cin >> S >> W) {
    int dp[4005] = {0};
    int maxv = 0;
    Rep(i,W.size()) {
      for(int j = S.size(); j > 0; j--) {
	if(S[j - 1] == W[i]) {
	  dp[j] = dp[j - 1] + 1;
	  maxv = max(maxv, dp[j]);
	} else dp[j] = 0;
      }
    }
    cout << maxv << endl;
  }
  return 0;
}
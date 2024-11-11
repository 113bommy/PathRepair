#include<std/c++.h>
using namespace std;

long long int dp[110][1<<16];

int main(int argc, char *argv[]){
  int n;
  while(cin >> n, n){
    int m, l[n], t[n];
    memset(t, 0, sizeof(t));
    for (int i = 0; i < n; i++) {
      cin >> m >> l[i];
      int s, e;
      for (int j = 0; j < m; j++) {
        cin >> s >> e;
        for (int k = s - 6; k < e - 6; k++)
          t[i] |= 1<<k;
      }
    }
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j < (1<<16); j++) {
        dp[i][j] = -1;
      }      
    }
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < (1<<16); j++) {
        if(dp[i][j] < 0)continue;
        dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
        if((t[i]&j) > 0)continue;
        dp[i + 1][j | t[i]] = max(dp[i + 1][j | t[i]],
                                  dp[i][j] + l[i]);
      }
    }
    long long int ans = 0;
    for (int i = 0; i < (1<<16); i++) {
      ans = max(ans, dp[n][i]);
    }
    std::cout << ans << std::endl;
  }
  return 0;
}
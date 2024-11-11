#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int a[6][N];
int pos[6][N];
int dp[N];
int main() {
  int n, k;
  scanf("%d", &n);
  ;
  scanf("%d", &k);
  ;
  for (int j = 1; j < k + 1; j++) {
    for (int i = 1; i < n + 1; i++) {
      scanf("%d", &a[j][i]);
      ;
      pos[j][a[j][i]] = i;
    }
  }
  for (int i = 1; i <= n; i++) {
    int mx = 0;
    for (int j = 1; j < i; j++) {
      bool flag = true;
      for (int p = 2; p <= k; p++) {
        if (pos[p][a[1][j]] < pos[1][a[1][i]]) {
        } else {
          flag = false;
          break;
        }
      }
      if (flag) {
        mx = max(mx, dp[j]);
      }
    }
    dp[i] = 1 + mx;
  }
  cout << *max_element(dp + 1, dp + n + 1) << endl;
}

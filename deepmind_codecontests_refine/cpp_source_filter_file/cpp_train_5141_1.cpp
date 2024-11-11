#include <bits/stdc++.h>
using namespace std;
const int N = 23;
bool dp[2][1 << N];
int num[N], n;
bool work(int len) {
  memset(dp, 0, sizeof(dp));
  dp[0][1] = 1;
  for (int j = 0; j < n; j++) {
    int m = j + 1;
    memset(dp[j + 1 & 1], 0, sizeof(dp[0]));
    if (j == n - 1) {
      for (int msk = 0; msk < (1 << n); msk++)
        if (dp[j & 1][msk]) return 1;
      return 0;
    }
    for (int msk = 0; msk < (1 << m); msk++)
      if (dp[j & 1][msk]) {
        for (int p = 0; p < m; p++)
          if (1 << p & msk)
            for (int q = p; q < m; q++)
              if (1 << q & msk)
                if (num[p] + num[q] == num[m]) {
                  int nmsk = 1 << m | msk;
                  if (j == len - 1) {
                    for (int k = 0; k < m; k++)
                      if (1 << k & msk) {
                        dp[j + 1 & 1][1 << k ^ nmsk] = 1;
                      }
                  } else
                    dp[j + 1 & 1][nmsk] = 1;
                }
      }
  }
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> num[i];
  for (int i = 1; i < n; i++) {
    bool flag = 0;
    for (int j = 0; j < i; j++)
      for (int k = j; k < i; k++)
        if (num[j] + num[k] == num[i]) flag = 1;
    if (!flag) {
      cout << -1 << endl;
      return 0;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (work(i)) {
      cout << i << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}

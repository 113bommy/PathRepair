#include <bits/stdc++.h>
using namespace std;
int t[50005][8], time1[50005][8];
int state[50005];
int curr[8];
int main() {
  int n, m;
  cin >> m >> n;
  for (int i = 0; i < m; ++i)
    for (int j = 0; j < n; ++j) cin >> t[i][j];
  for (int i = 0; i < m; ++i) {
    time1[i][0] = t[i][0];
    for (int j = 1; j < n; ++j) time1[i][j] = time1[i][j - 1] + t[i][j];
  }
  for (int t = 1;; ++t) {
    int all[5];
    for (int i = 0; i < 5; ++i) all[i] = -1;
    for (int j = 0; j < n; ++j)
      if (curr[j] != -1) {
        bool f = true;
        for (int k = 0; k < j; ++k)
          if (all[k] == curr[j]) f = false;
        if (!f) continue;
        all[j] = curr[j];
        state[curr[j]]++;
        if (state[curr[j]] == time1[curr[j]][j]) {
          if (j == (n - 1)) {
            cout << t << " ";
          }
          curr[j]++;
          if (curr[j] >= m) {
            curr[j] = -1;
            if (j == n - 1) return 0;
          }
        }
      }
  }
  return 0;
}

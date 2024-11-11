#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int OO = 1e9 + 10;
int n, k[3], a[3][N];
int id[N];
int pre[3][N], suf[3][N];
int suf1[N];
int main() {
  for (int i = 0; i < 3; i++) cin >> k[i], n += k[i];
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < k[i]; j++) {
      scanf("%d", &a[i][j]);
      id[a[i][j]] = i;
    }
  }
  int ans = min({n - k[0], n - k[1], n - k[2]});
  for (int i = 0; i < 3; i++) {
    for (int j = 1; j <= n; j++) {
      pre[i][j] = pre[i][j - 1];
      if (id[j] == i) pre[i][j]++;
    }
    for (int j = n; j >= 0; j--) {
      suf[i][j] = suf[i][j + 1];
      if (id[j] == i) suf[i][j]++;
    }
  }
  for (int i = 1; i + 1 <= n; i++) {
    for (int j = 0; j < 3; j++) {
      for (int d = j + 1; d < 3; d++) {
        ans = min(ans, n - (pre[j][i] + suf[d][i + 1]));
      }
    }
  }
  for (int i = n; i >= 0; i--) {
    suf1[i] = suf[2][i] - suf[1][i];
    suf1[i] = max(suf1[i], suf1[i + 1]);
  }
  for (int i = 1; i + 2 <= n; i++) {
    ans = min(ans, n - (pre[0][i] + suf[1][i + 1] + suf1[i + 2]));
  }
  cout << ans << endl;
}

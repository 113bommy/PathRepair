#include <bits/stdc++.h>
using namespace std;
int len[101];
int in[101], x[101], y[101], val[101][101], ans[10001];
int main() {
  int i, j, k, n, m, sum;
  while (cin >> n >> m) {
    memset(val, 0, sizeof(val));
    memset(ans, 0, sizeof(ans));
    for (i = 0; i < n; ++i) {
      scanf("%d", &len[i]);
      for (j = 0; j < len[i]; ++j) scanf("%d", &in[j]);
      x[0] = y[0] = 0;
      for (j = 1, k = len[i] - 1; j <= len[i]; j++, k--) {
        x[j] = x[j - 1] + in[j - 1];
        y[j] = y[j - 1] + in[k];
      }
      for (j = 0; j <= len[i]; j++) {
        int &maxn = val[i][j];
        for (k = 0; k <= j; k++) {
          maxn = max(maxn, x[k] + y[j - k]);
        }
      }
    }
    sum = 0;
    for (i = 0; i < n; ++i) {
      sum = min(sum + len[i], m);
      for (j = sum; j >= 0; j--) {
        int &w = ans[j];
        for (k = 1; k <= val[i][j] && k <= j; k++) {
          w = max(w, ans[j - k] + val[i][k]);
        }
      }
    }
    cout << ans[m] << endl;
  }
}

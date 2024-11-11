#include <bits/stdc++.h>
using namespace std;
const int N = 15;
const int M = 1e4 + 5;
int t, n, m, a[N], sum, f, ans[M], res;
char s[N][M];
pair<int, int> c[M];
int main() {
  ios::sync_with_stdio(false);
  cin >> t;
  while (t--) {
    cin >> n >> m;
    res = -1;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> (s[i] + 1);
    for (int i = 0; i < (1 << n); i++) {
      sum = 0;
      for (int j = 1; j <= m; j++) c[j] = {0, j};
      for (int j = 1; j <= n; j++) {
        if ((i >> (j - 1)) & 1)
          f = 1;
        else
          f = -1;
        sum += f * a[j];
        for (int k = 1; k <= m; k++)
          if (s[j][k] == '1') c[k].first -= f;
      }
      sort(c + 1, c + m + 1);
      for (int j = 1; j <= m; j++) sum += j * c[j].first;
      if (sum > res) {
        res = sum;
        for (int j = 1; j <= m; j++) ans[c[j].second] = j;
      }
    }
    for (int i = 1; i <= m; i++) cout << ans[i] << ' ';
    cout << endl;
  }
  return 0;
}

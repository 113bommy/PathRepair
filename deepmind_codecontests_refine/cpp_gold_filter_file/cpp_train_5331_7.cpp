#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
inline int read() {
  register int x;
  register char c(getchar());
  register bool k;
  while ((c < '0' || c > '9') && c ^ '-')
    if ((c = getchar()) == EOF) exit(0);
  if (c ^ '-')
    x = c & 15, k = 1;
  else
    x = 0, k = 0;
  while (c = getchar(), c >= '0' && c <= '9')
    x = (x << 1) + (x << 3) + (c & 15);
  return k ? x : -x;
}
const int maxn = 100 + 5;
int a[maxn][maxn], sum[maxn];
pair<int, int> ps[maxn];
vector<int> ans, tmp;
int main() {
  int n = read(), m = read();
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++) a[i][j] = read(), sum[j] += a[i][j];
  int p = 1;
  for (int i = 2; i <= n; i++)
    if (sum[i] > sum[p]) p = i;
  if (p != n) {
    cout << 0 << '\n';
    return 0;
  }
  for (int i = 1; i < n; i++) {
    for (int j = 1; j <= m; j++) {
      ps[j] = pair<int, int>(a[j][i] - a[j][n], j);
    }
    sort(ps + 1, ps + m + 1);
    int dis = sum[i] - sum[n], i_ = 1;
    tmp.clear();
    while (dis < 0 && i_ <= m) {
      dis -= ps[i_].first;
      tmp.push_back(ps[i_].second);
      i_++;
    }
    if (dis >= 0 && (tmp.size() < ans.size() || ans.size() == 0)) ans = tmp;
  }
  cout << ans.size() << '\n';
  for (int i = 0; i < ans.size(); i++) {
    if (i) cout << ' ';
    cout << ans[i];
  }
  cout << '\n';
  return 0;
}

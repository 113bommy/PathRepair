#include <bits/stdc++.h>
using namespace std;
const int m = 500;
const int M = 510;
int n, p, x[110000], y[110000];
vector<int> route[110000];
long long a[110000], ans[110000];
long long f[500][500], pos;
inline int prepos(const int &pos, const int &k) {
  return ((pos - k) % M + M) % M;
}
inline void nexpos() { pos = (pos + 1) % M; }
void work() {
  for (int i = 1; i <= n; i++) scanf("%I64d", &a[i]);
  for (int i = 1; i <= n; i++) route[i].clear();
  scanf("%d", &p);
  for (int i = 1; i <= p; i++) {
    scanf("%d%d", &x[i], &y[i]);
    if (y[i] > m) {
      ans[i] = 0LL;
      for (int k = x[i]; k <= n; k += y[i]) ans[i] += a[k];
    } else
      route[x[i]].push_back(i);
  }
  pos = 0;
  for (int i = n; i >= 1; i--) {
    for (int j = 1; j <= m; j++) {
      f[pos][j] = a[i];
      if (i + j > n) continue;
      f[pos][j] += f[prepos(pos, j)][j];
    }
    if (!route[i].empty()) {
      int size = route[i].size();
      for (int k = 0; k < size; k++) ans[route[i][k]] = f[pos][y[route[i][k]]];
    }
    nexpos();
  }
  for (int i = 1; i <= p; i++) printf("%I64d\n", ans[i]);
}
int main() {
  while (scanf("%d", &n) != EOF) work();
  return 0;
}

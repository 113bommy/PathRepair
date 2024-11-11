#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int T = 1 << 19;
bool u[N], w[N];
vector<int> g[N];
int deg[N], deg2[N];
double ta[N];
int t[T], d;
void upd(int i, double x) {
  ta[i] = x;
  i += d;
  for (i >>= 1; i; i >>= 1) {
    t[i] = ta[t[i * 2]] < ta[t[i * 2 + 1]] ? t[i * 2] : t[i * 2 + 1];
  }
}
int main() {
  int n, m, b;
  scanf("%d%d%d", &n, &m, &b);
  for (int k = 0; k < b; ++k) {
    int i;
    scanf("%d", &i);
    --i;
    u[i] = 1;
  }
  for (int k = 0; k < m; ++k) {
    int i, j;
    scanf("%d%d", &i, &j);
    --i;
    --j;
    g[i].push_back(j);
    g[j].push_back(i);
  }
  double l = -1, r = 1e5 + 5;
  vector<int> ans;
  for (d = 2; d < n; d <<= 1)
    ;
  for (int it = 50; it; --it) {
    double x = (l + r) / 2.0;
    for (int i = 0; i < n; ++i) w[i] = u[i], deg[i] = g[i].size(), deg2[i] = 0;
    for (int i = 0; i < n; ++i) t[i + d] = i;
    for (int i = n; i < d; ++i) t[i + d] = n;
    ta[n] = 1e9;
    int cnt = 0;
    for (int i = 0; i < n; ++i)
      if (!w[i]) {
        for (int j : g[i]) {
          if (!w[j]) ++deg2[i];
        }
        ta[i] = 1.0 * deg2[i] / deg[i];
        ++cnt;
      } else
        ta[i] = 1e9;
    for (int i = d - 1; i; --i)
      t[i] = ta[t[i * 2]] < ta[t[i * 2 + 1]] ? t[i * 2] : t[i * 2 + 1];
    while (cnt > 0) {
      int i = t[1];
      if (ta[i] >= x) break;
      upd(i, 1e9);
      --cnt;
      w[i] = 1;
      for (int j : g[i])
        if (!w[j]) {
          deg2[j]--;
          upd(j, 1.0 * deg2[j] / deg[j]);
        }
    }
    if (cnt == 0)
      r = x;
    else {
      ans.clear();
      for (int i = 0; i < n; ++i)
        if (!w[i]) ans.push_back(i);
      l = x;
    }
  }
  printf("%d\n", ans.size());
  for (int i : ans) printf("%d ", i + 1);
  printf("\n");
  return 0;
}

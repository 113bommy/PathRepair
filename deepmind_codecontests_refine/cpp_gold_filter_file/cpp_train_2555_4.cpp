#include <bits/stdc++.h>
using namespace std;
const int64_t maxn = 522, sigma = 26;
int64_t a[maxn];
int64_t to[maxn][sigma];
int64_t link[maxn], cost[maxn];
int64_t sz = 1;
void add_str(string s, int64_t n) {
  int64_t v = 0;
  for (auto c : s) {
    c -= 'a';
    if (!to[v][c]) to[v][c] = sz++;
    v = to[v][c];
  }
  cost[v] += a[n];
}
void push_links() {
  int64_t que[sz];
  int64_t st = 0, fi = 1;
  que[0] = 0;
  while (st < fi) {
    int64_t v = que[st++];
    int64_t u = link[v];
    cost[v] += cost[u];
    for (int64_t c = 0; c < sigma; c++) {
      if (to[v][c]) {
        link[to[v][c]] = v ? to[u][c] : 0;
        que[fi++] = to[v][c];
      } else {
        to[v][c] = to[u][c];
      }
    }
  }
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int64_t n, l;
  cin >> n >> l;
  for (int64_t i = 0; i < n; i++) cin >> a[i];
  for (int64_t i = 0; i < n; i++) {
    string s;
    cin >> s;
    add_str(s, i);
  }
  push_links();
  const int64_t logn = 50;
  int64_t best[logn][sz][sz];
  memset(best, -1, sizeof(best));
  for (int64_t i = 0; i < sz; i++)
    for (int64_t c = 0; c < sigma; c++) best[0][i][to[i][c]] = cost[to[i][c]];
  for (int64_t z = 1; z < logn; z++)
    for (int64_t k = 0; k < sz; k++)
      for (int64_t i = 0; i < sz; i++)
        for (int64_t j = 0; j < sz; j++)
          if (best[z - 1][i][k] != -1 && best[z - 1][k][j] != -1)
            best[z][i][j] =
                max(best[z][i][j], best[z - 1][i][k] + best[z - 1][k][j]);
  int64_t ans[sz][sz];
  memset(ans, -1, sizeof(ans));
  for (int64_t i = 0; i < sz; i++) ans[i][i] = 0;
  for (int64_t z = 0; z < logn; z++) {
    if ((l >> z) & 1) {
      int64_t tmp[sz][sz];
      memset(tmp, -1, sizeof(tmp));
      for (int64_t k = 0; k < sz; k++)
        for (int64_t i = 0; i < sz; i++)
          for (int64_t j = 0; j < sz; j++)
            if (ans[i][k] != -1 && best[z][k][j] != -1)
              tmp[i][j] = max(tmp[i][j], ans[i][k] + best[z][k][j]);
      memcpy(ans, tmp, sizeof(ans));
    }
  }
  int64_t out = 0;
  for (int64_t i = 0; i < sz; i++) out = max(out, ans[0][i]);
  cout << out << "\n";
  return 0;
}

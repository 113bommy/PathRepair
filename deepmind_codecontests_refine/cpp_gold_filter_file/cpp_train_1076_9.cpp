#include <bits/stdc++.h>
using namespace std;
const int V = 200005;
int r[V], sa[V], X[V], Y[V], h[V], a[V], b[V];
void calh(int n) {
  int i, j, k = 0;
  for (i = 1; i <= n; i++) r[sa[i]] = i;
  for (i = 0; i < n; h[r[i++]] = k)
    for (k ? k-- : 0, j = sa[r[i] - 1]; a[i + k] == a[j + k]; k++)
      ;
}
bool cmp(int *r, int a, int b, int l) {
  return (r[a] == r[b] && r[a + l] == r[b + l]);
}
void suffix(int n, int m = 128) {
  int i, j, p, *x = X, *y = Y, *t;
  for (i = 0; i < m; i++) b[i] = 0;
  for (i = 0; i < n; i++) b[x[i] = a[i]]++;
  for (i = 1; i < m; i++) b[i] += b[i - 1];
  for (i = n - 1; i >= 0; i--) sa[--b[x[i]]] = i;
  for (j = 1, p = 1; p < n; m = p, j <<= 1) {
    p = 0;
    for (i = n - j; i < n; i++) y[p++] = i;
    for (i = 0; i < n; i++)
      if (sa[i] >= j) y[p++] = sa[i] - j;
    for (i = 0; i < m; i++) b[i] = 0;
    for (i = 0; i < n; i++) b[x[y[i]]]++;
    for (i = 1; i < m; i++) b[i] += b[i - 1];
    for (i = n - 1; i >= 0; i--) sa[--b[x[y[i]]]] = y[i];
    for (t = x, x = y, y = t, x[sa[0]] = 0, i = 1, p = 1; i < n; i++)
      x[sa[i]] = cmp(y, sa[i - 1], sa[i], j) ? p - 1 : p++;
  }
  calh(n - 1);
}
const int POW = 20;
int Log[V], best[POW][V];
int min(int a, int b) { return a < b ? a : b; }
void initrmq(int n) {
  int i, j, m;
  for (i = 1; i <= n; i++) best[0][i] = h[i];
  for (i = 1; i <= Log[n]; i++) {
    m = n - (1 << i) + 1;
    for (j = 1; j <= m; j++)
      best[i][j] = min(best[i - 1][j], best[i - 1][j + (1 << i >> 1)]);
  }
}
int lcp(int a, int b) {
  a = r[a];
  b = r[b];
  if (a > b) a ^= b, b ^= a, a ^= b;
  a++;
  int t = Log[b - a + 1];
  return min(best[t][a], best[t][b - (1 << t) + 1]);
}
int in[V];
vector<int> num[V];
map<int, int> MAP;
struct PP {
  int p;
  int len;
  PP(int p = 0, int len = 0) : p(p), len(len) {}
  bool operator<(const PP &t) const {
    if (len != t.len) return len > t.len;
    return p > t.p;
  }
};
int main() {
  int i, j, k, n, t;
  int x, y, len;
  Log[0] = -1;
  for (i = 1; i < V; i++) Log[i] = Log[i >> 1] + 1;
  while (scanf("%d", &n) != -1) {
    MAP.clear();
    int tot = 0;
    for (i = 1; i <= n; i++) num[i].clear();
    for (i = 0; i < n; i++) {
      scanf("%d", &in[i]);
      if (!(t = MAP[in[i]])) t = MAP[in[i]] = ++tot;
      a[i] = t;
      num[t].push_back(i);
    }
    a[n] = 0;
    suffix(n + 1, tot + 1);
    initrmq(n);
    priority_queue<PP> q;
    for (i = 1; i <= tot; i++) {
      for (j = 0; j < num[i].size(); j++) {
        for (k = j + 1; k < num[i].size(); k++) {
          x = num[i][j];
          y = num[i][k];
          len = y - x;
          y = x + 1;
          x = x - len + 1;
          if (x < 0) break;
          int ll = lcp(x, y);
          if (ll >= len) {
            q.push(PP(num[i][j], len));
            break;
          }
        }
      }
    }
    int ans = 0;
    while (!q.empty()) {
      PP s = q.top();
      q.pop();
      if (s.p - s.len + 1 < ans) continue;
      ans = s.p + 1;
    }
    printf("%d\n", n - ans);
    for (i = ans; i < n; i++) printf("%d ", in[i]);
    puts("");
  }
  return 0;
}

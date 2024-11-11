#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005;
const double eps = 1e-9;
int n, b[maxn], c[maxn], stak[maxn], top, ans[maxn], cnt;
pair<int, int> p[maxn];
vector<int> G[maxn];
struct node {
  double fir, sec;
  node() {}
  node(double x, double y) {
    fir = x;
    sec = y;
  }
} a[maxn];
node operator-(node x, node y) { return node(x.fir - y.fir, x.sec - y.sec); }
double slop(node x) { return x.sec / x.fir; }
bool cmp(int x, int y) { return a[x].fir < a[y].fir; }
bool cmp1(int x, int y) {
  return p[x].first != p[y].first ? p[x].first < p[y].first
                                  : p[x].second < p[y].second;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d", &p[i].first, &p[i].second);
    b[i] = i;
  }
  sort(b + 1, b + n + 1, cmp1);
  int m = 0;
  for (int l = 1, r; l <= n; l = r + 1) {
    r = l;
    while (r < n && p[b[l]] == p[b[r + 1]]) ++r;
    if (r < n && p[b[r]].first == p[b[r + 1]].first) continue;
    ++m;
    c[m] = m;
    a[m] = node(1.0 / p[b[l]].first, 1.0 / p[b[l]].second);
    for (int j = l; j <= r; ++j) G[m].push_back(b[j]);
  }
  sort(c + 1, c + m + 1, cmp);
  for (int i = 1; i <= m; ++i) {
    while (top > 1 && slop(a[stak[top]] - a[stak[top - 1]]) >
                          slop(a[c[i]] - a[stak[top - 1]]))
      --top;
    stak[++top] = c[i];
  }
  for (int i = 0; i < G[stak[1]].size(); ++i) ans[++cnt] = G[stak[1]][i];
  for (int i = 2; i <= top; ++i) {
    node u = a[stak[i]] - a[stak[i - 1]];
    if (slop(u) < 0) {
      for (int j = 0; j < G[stak[i]].size(); ++i) ans[++cnt] = G[stak[i]][j];
    } else {
      break;
    }
  }
  sort(ans + 1, ans + cnt + 1);
  for (int i = 1; i <= cnt; ++i) printf("%d ", ans[i]);
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef struct node_t {
  int x, id;
  friend bool operator<(const node_t& a, const node_t& b) { return a.x < b.x; }
} node_t;
const int maxn = 1e5 + 5;
int ti[maxn], xi[maxn];
node_t nd[maxn];
int ans[maxn];
int main() {
  ios::sync_with_stdio(false);
  int n, m;
  int t = 1, tt;
  int px, x;
  scanf("%d %d", &n, &m);
  for (int i = 1; i < n + 1; ++i) {
    scanf("%d %d", &ti[i], &xi[i]);
    nd[i].x = xi[i];
    nd[i].id = i;
  }
  int i, j, k;
  int ii, jj;
  i = 1;
  while (i <= n) {
    k = min(n, i + m - 1);
    t = max(t, ti[k]);
    j = i;
    k = 0;
    while (i <= n && k < m && ti[i] <= t) {
      ++k;
      ++i;
    }
    sort(nd + j, nd + i);
    tt = t;
    px = 0;
    while (j < i) {
      jj = j;
      x = nd[j].x;
      tt += x - px;
      while (j < i && nd[j].x == x) {
        ans[nd[j].id] = tt;
        ++j;
      }
      tt += (j - jj) / 2 + 1;
      px = x;
    }
    tt += px;
    t = tt;
  }
  for (i = 1; i <= n; ++i) printf("%d ", ans[i]);
  putchar('\n');
  return 0;
}

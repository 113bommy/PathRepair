#include <bits/stdc++.h>
using namespace std;
struct node {
  long x, y;
  long na;
};
const long maxn = 200000 + 5;
long long a[maxn];
long long f[maxn][2];
long long leave[maxn];
long gr[maxn][3], fa[maxn];
long n, m, mm, k, root;
long mark[maxn];
long long Tsum[maxn], Tg[maxn];
long L[maxn];
long x[maxn], y[maxn];
node b[maxn];
bool cmp(node a, node b) { return (a.x < b.x); }
void bfs() {
  long f = 0, r = 1, u;
  L[r] = root;
  while (f < r) {
    u = L[++f];
    if (gr[u][0] > 0) {
      L[++r] = gr[u][1];
      L[++r] = gr[u][2];
    }
  }
}
void dfs_dtotop() {
  long u;
  for (long i = n; i >= 1; --i) {
    u = L[i];
    if (gr[u][0] == 0) {
      f[u][0] = f[u][1] = a[u];
      x[u] = a[u];
      y[u] = a[u];
    } else {
      f[u][0] = x[gr[u][1]];
      f[u][1] = y[gr[u][2]];
      x[u] = x[gr[u][1]];
      y[u] = y[gr[u][2]];
    }
  }
}
void dfs_toptod() {
  memset(Tsum, 0, sizeof(Tsum));
  memset(Tg, 0, sizeof(Tg));
  long u, pre;
  x[root] = 0;
  y[root] = 2147483647;
  Tsum[root] = 0;
  Tg[root] = 0;
  for (long i = 2; i <= n; ++i) {
    u = L[i];
    pre = fa[u];
    if (a[u] < a[pre]) {
      x[u] = x[pre];
      y[u] = a[pre];
      Tsum[u] = Tsum[pre] + f[gr[pre][2]][0];
      Tg[u] = Tg[pre] + 1;
    } else {
      x[u] = a[pre];
      y[u] = y[pre];
      Tsum[u] = Tsum[pre] + f[gr[pre][1]][1];
      Tg[u] = Tg[pre] + 1;
    }
  }
}
long find(long long w) {
  long l = 0, r = m - 1, mid;
  while (l <= r) {
    mid = (l + r) / 2;
    if (b[mid].x <= w && w <= b[mid].y) return b[mid].na;
    if (b[mid].y <= w)
      l = mid + 1;
    else
      r = mid - 1;
  }
}
int main() {
  memset(gr, 0, sizeof(gr));
  memset(mark, 0, sizeof(mark));
  cin >> n;
  for (long i = 1; i <= n; ++i) {
    cin >> fa[i] >> a[i];
    if (fa[i] == -1) root = i;
  }
  for (long i = 1; i <= n; ++i) {
    if (fa[i] > 0) {
      gr[fa[i]][0] = 1;
      if (a[i] > a[fa[i]])
        gr[fa[i]][2] = i;
      else
        gr[fa[i]][1] = i;
    }
  }
  m = 0;
  bfs();
  dfs_dtotop();
  dfs_toptod();
  for (long i = 1; i <= n; ++i)
    if (gr[i][0] == 0) {
      b[m].x = x[i];
      b[m].y = y[i];
      b[m].na = i;
      ++m;
    }
  sort(b, b + m, cmp);
  long TextN, uu;
  long long w;
  double ans;
  cin >> TextN;
  for (long i = 0; i != TextN; ++i) {
    cin >> w;
    uu = find(w);
    ans = double(Tsum[uu]) / double(Tg[uu]);
    printf("%.10lf\n", ans);
  }
  return 0;
}

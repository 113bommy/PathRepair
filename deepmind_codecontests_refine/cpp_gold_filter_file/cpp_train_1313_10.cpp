#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 2e5 + 5;
int fx[maxn], fy[maxn], n;
int qx[maxn];
long long sd[maxn];
long long ans[maxn];
struct pwp {
  int x, y, id;
};
bool cmp(const pwp &a, const pwp &b) { return a.x < b.x; }
vector<pwp> q[4];
int fw[maxn];
int lowbit(int t) { return t & (-t); }
void add(int x, int d) {
  while (x <= n) {
    fw[x] += d;
    x += lowbit(x);
  }
}
int ff(int x) {
  int s = 0;
  while (x > 0) {
    s += fw[x];
    x -= lowbit(x);
  }
  return s;
}
void solve(int k) {
  sort(q[k].begin(), q[k].end(), cmp);
  memset(fw, 0, sizeof(fw));
  int i, j, m = q[k].size();
  for (i = 1, j = 0; i <= n; i++) {
    add(qx[i], 1);
    while (j < m && q[k][j].x == i) {
      ans[q[k][j].id] += sd[ff(q[k][j].y)];
      j++;
    }
  }
}
int main() {
  int m, i;
  scanf("%d%d", &n, &m);
  for (i = 0; i < n; i++) {
    scanf("%d", &fy[i]);
    fx[i] = i + 1;
  }
  for (i = 1; i <= n; i++) sd[i] = 1LL * i * (i - 1) / 2;
  for (i = 1; i <= m; i++) {
    ans[i] = sd[n];
    int l, d, r, u;
    scanf("%d%d%d%d", &l, &d, &r, &u);
    ans[i] -= sd[d - 1] + sd[l - 1] + sd[n - r] + sd[n - u];
    if (l > 1 && d > 1) q[0].push_back(pwp{l - 1, d - 1, i});
    if (l > 1 && u < n) q[1].push_back(pwp{l - 1, n - u, i});
    if (r < n && d > 1) q[2].push_back(pwp{n - r, d - 1, i});
    if (r < n && u < n) q[3].push_back(pwp{n - r, n - u, i});
  }
  for (i = 0; i < n; i++) qx[fx[i]] = fy[i];
  solve(0);
  for (i = 0; i < n; i++) qx[fx[i]] = n - fy[i] + 1;
  solve(1);
  for (i = 0; i < n; i++) qx[n - fx[i] + 1] = fy[i];
  solve(2);
  for (i = 0; i < n; i++) qx[n - fx[i] + 1] = n - fy[i] + 1;
  solve(3);
  for (i = 1; i <= m; i++) printf("%lld\n", ans[i]);
  return 0;
}

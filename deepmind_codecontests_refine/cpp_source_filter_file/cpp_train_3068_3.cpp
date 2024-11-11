#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int Q = 5005;
const int QQ = Q * 2;
int n, q, a[100005];
int l[Q], r[Q];
double p[Q];
int id[Q], dw, up;
int pa[Q], val[Q];
vector<int> v[100005];
void chkmax(int &a, int b) {
  if (a < b) a = b;
}
void dfs(int k) {
  if (v[k].empty())
    chkmax(val[k], *max_element(a + l[k], a + r[k] + 1));
  else {
    if (l[k] < l[v[k][0]])
      chkmax(val[k], *max_element(a + l[k], a + l[v[k][0]]));
    if (r[v[k].back()] < r[k])
      chkmax(val[k], *max_element(a + r[v[k].back()] + 1, a + r[k] + 1));
  }
  int prv = QQ;
  for (auto x : v[k]) {
    if (prv < l[x]) chkmax(val[k], *max_element(a + prv, a + l[x]));
    dfs(x);
    prv = r[x] + 1;
    chkmax(val[k], val[x]);
  }
  return;
}
using vd = vector<double>;
vd DFS(int k) {
  vd mx(QQ, 1);
  int t = val[k];
  if ((t + q) <= dw) return mx;
  for (int i = 0; i < t - dw + Q; i++) mx[i] = 0;
  for (auto x : v[k]) {
    vd mxp = DFS(x);
    for (int i = t - dw + Q; i < QQ; i++) mx[i] *= mxp[i];
  }
  int tt = t + q - dw + Q;
  for (int i = QQ - 1; i > 0; i--)
    mx[i] = (1 - p[k]) * mx[i] + p[k] * mx[i - 1];
  return mx;
}
int main() {
  scanf("%d %d", &n, &q);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= q; i++)
    scanf("%d %d %lf", &l[i], &r[i], &p[i]), id[i] = i;
  sort(id + 1, id + q + 1,
       [](int x, int y) { return l[x] != l[y] ? l[x] < l[y] : r[x] > r[y]; });
  int cur = 0;
  l[0] = 1, r[0] = n, p[0] = 0;
  for (int ii = 1; ii <= q; ii++) {
    int i = id[ii];
    while (!(l[cur] <= l[i] && r[i] <= r[cur])) cur = pa[cur];
    pa[i] = cur;
    cur = i;
    v[pa[i]].push_back(i);
  }
  dfs(0);
  dw = val[0];
  up = dw + q;
  vd mx = DFS(0);
  double ans = 0;
  for (int i = Q, j = dw; j <= up; i++, j++) ans += (mx[i] - mx[i - 1]) * j;
  cout << fixed << setprecision(10) << ans << endl;
  return 0;
}

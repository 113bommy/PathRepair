#include <bits/stdc++.h>
const int Mod = (int)1e9 + 7;
const int MX = 1073741822;
const long long MXLL = 4611686018427387903;
const int Sz = 1110111;
using namespace std;
inline void Read_rap() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
}
int n, m, q;
bool used[Sz];
int comp, mx1[Sz], mx2[Sz], d[Sz], c[Sz];
long long f[Sz];
map<pair<int, int>, double> Ans;
vector<int> v[Sz];
vector<long long> suff[Sz];
vector<int> g[Sz];
void pre_dfs(int v, int pr) {
  for (auto to : g[v]) {
    if (to != pr) {
      pre_dfs(to, v);
      if (mx1[v] < mx1[to] + 1) {
        mx2[v] = mx1[v];
        mx1[v] = mx1[to] + 1;
      } else
        mx2[v] = max(mx2[v], mx1[to] + 1);
    }
  }
}
void calc(int v, int up) {
  used[v] = 1;
  d[comp] = max(mx1[v] + mx2[v], d[comp]);
  if (mx1[v] < up)
    mx2[v] = mx1[v], mx1[v] = up;
  else
    mx2[v] = max(mx2[v], up);
  f[v] = mx1[v];
  c[v] = comp;
  ::v[comp].push_back(v);
  for (auto to : g[v])
    if (!used[to]) calc(to, (mx1[to] + 1 == mx1[v] ? mx2[v] : mx1[v]) + 1);
}
double calc(vector<int> &a, vector<int> &b, vector<long long> &suff,
            long long d) {
  int l = 0;
  double res = 0;
  for (int i = 0; i < (int)(a.size()); i++) {
    int l = 0, r = (int)(b.size()) - 1, j = (int)(b.size());
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (a[i] + b[mid] + 1 < d)
        l = mid + 1;
      else {
        r = mid - 1;
        j = mid;
      }
    }
    res += d * j + ((int)(b.size()) - j) * (f[a[i]] + 1) + suff[j];
  }
  return res;
}
int main() {
  scanf("%d %d %d", &n, &m, &q);
  for (int i = 1, x, y; i <= m; i++) {
    scanf("%d %d", &x, &y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for (int i = 1; i <= n; i++) {
    if (!used[i]) {
      comp++;
      pre_dfs(i, i);
      calc(i, 0);
    }
  }
  for (int i = 1; i <= comp; i++) {
    sort(v[i].begin(), v[i].end(), [](int a, int b) { return f[a] < f[b]; });
    suff[i].resize((int)(v[i].size()) + 1);
    for (int j = (int)(v[i].size()) - 1; j >= 0; j--)
      suff[i][j] = suff[i][1 + j] + f[v[i][j]];
  }
  for (int x, y; q--;) {
    scanf("%d %d", &x, &y);
    x = c[x], y = c[y];
    if (x != y) {
      double ans;
      if ((int)(v[x].size()) > (int)(v[y].size())) swap(x, y);
      if (Ans.count(make_pair(x, y))) {
        ans = Ans[make_pair(x, y)];
      } else {
        ans = calc(v[x], v[y], suff[y], max(d[x], d[y])) /
              ((int)(v[x].size()) * 1.0 * (int)(v[y].size()));
        Ans[make_pair(x, y)] = Ans[make_pair(y, x)] = ans;
      }
      printf("%.6lf\n", ans);
    } else
      printf("-1\n");
  }
  return 0;
}

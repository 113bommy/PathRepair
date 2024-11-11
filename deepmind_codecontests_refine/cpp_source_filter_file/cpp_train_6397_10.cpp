#include <bits/stdc++.h>
using namespace std;
const long long N = 7e5;
const long long LG = 25;
const long long SQ = 320;
const long long INF = 1e16;
const long long MOD = 1e9 + 7;
string s, s1, s2, s3;
int n, n1, n2, n3;
int r[LG][N];
pair<pair<int, int>, int> p[N];
int suf[N];
vector<pair<int, int> > e;
long long par[N], sz[N], a[3][N];
long long ans[N];
long long res[N];
int lcp(int x, int y) {
  if (x == y) return n - x;
  int res = 0;
  for (int i = LG - 1; i >= 0; i--)
    if (r[i][x] == r[i][y]) {
      x += (1 << i);
      y += (1 << i);
      res += (1 << i);
    }
  return res;
}
int get_par(int x) { return (par[x] == x ? x : par[x] = get_par(par[x])); }
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> s1 >> s2 >> s3;
  n1 = s1.size();
  n2 = s2.size();
  n3 = s3.size();
  s = s1 + "/" + s2 + "#" + s3;
  n = n1 + n2 + n3 + 2;
  for (int i = 0; i < n; i++) r[0][i] = s[i];
  for (int i = 1; i < LG; i++) {
    for (int j = 0; j < n; j++)
      if (j + (1 << (i - 1)) >= n)
        p[j] = make_pair(make_pair(r[i - 1][j], -1), j);
      else
        p[j] =
            make_pair(make_pair(r[i - 1][j], r[i - 1][j + (1 << (i - 1))]), j);
    sort(p, p + n);
    r[i][p[0].second] = 1;
    for (int j = 1; j < n; j++)
      if (p[j].first == p[j - 1].first)
        r[i][p[j].second] = r[i][p[j - 1].second];
      else
        r[i][p[j].second] = j + 1;
  }
  for (int i = 0; i < n; i++) {
    suf[i] = p[i].second;
  }
  cout << endl;
  for (int i = 0; i < n - 1; i++)
    e.push_back(make_pair(lcp(suf[i], suf[i + 1]), i));
  sort(e.begin(), e.end());
  reverse(e.begin(), e.end());
  for (int i = 0; i < n; i++) {
    int p = suf[i];
    par[p] = p;
    sz[p] = 1;
    if (p < n1) a[0][i]++;
    if (p > n1 && p <= n1 + n2) a[1][i]++;
    if (p > n1 + n2 + 1) a[2][i]++;
  }
  for (int i = 0; i < e.size(); i++) {
    int v = get_par(e[i].second);
    int u = get_par(e[i].second + 1);
    ans[e[i].first] += a[0][v] * a[1][u] * a[2][u];
    ans[e[i].first] += a[1][v] * a[0][u] * a[2][u];
    ans[e[i].first] += a[2][v] * a[0][u] * a[1][u];
    ans[e[i].first] += a[0][u] * a[1][v] * a[2][v];
    ans[e[i].first] += a[1][u] * a[0][v] * a[2][v];
    ans[e[i].first] += a[2][u] * a[0][v] * a[1][v];
    if (sz[v] > sz[u]) swap(v, u);
    par[v] = u;
    sz[u] += sz[v];
    a[0][u] += a[0][v];
    a[1][u] += a[1][v];
    a[2][u] += a[2][v];
  }
  int mn = min(min(n1, n2), n3);
  for (int i = mn; i >= 1; i--) res[i] = res[i + 1] + ans[i];
  for (int i = 1; i <= mn; i++) cout << res[i] << ' ';
  cout << '\n';
  return 0;
}

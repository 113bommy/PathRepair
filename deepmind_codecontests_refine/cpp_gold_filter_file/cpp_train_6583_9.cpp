#include <bits/stdc++.h>
using namespace std;
const int N = 8000 + 10, mod = 1e9 + 7;
int in[N];
bool g[N][N];
bool mark[N];
pair<int, int> deg[N];
int cnt[N];
bool cmp(int v, int u) { return g[v][u]; }
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  string s;
  getline(cin, s);
  for (int i = 0; i < n; i++) {
    getline(cin, s);
    for (int x = 0; x < n; x += 4) {
      char c = s[x / 4];
      int w = (c >= '0' && c <= '9' ? c - '0' : c - 'A' + 10);
      g[i][x] = (w >> 3) & 1;
      g[i][x + 1] = (w >> 2) & 1;
      g[i][x + 2] = (w >> 1) & 1;
      g[i][x + 3] = w & 1;
    }
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) in[j] += g[i][j];
  for (int i = 0; i < n; i++) deg[i] = {in[i], i};
  sort(deg, deg + n);
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    if (deg[i].first != i) break;
    int x = deg[i].second;
    mark[x] = 1;
    ans += 614ll * n * (n - i - 1) + (n - i - 1);
  }
  int v = deg[n - 1].second;
  if (mark[v]) return cout << ans << endl, 0;
  mark[v] = 1;
  vector<int> p[2];
  for (int i = 0; i < n; i++)
    if (!mark[i]) p[g[i][v]].push_back(i);
  p[1].push_back(v);
  sort(p[0].begin(), p[0].end(), cmp);
  sort(p[1].begin(), p[1].end(), cmp);
  ans += 3 * p[0].size() * p[1].size();
  ans += p[0].size() * (p[0].size() - 1) / 2 * 3;
  ans += p[1].size() * (p[1].size() - 1) / 2 * 3;
  for (int _ = 0; _ < 2; _++) {
    int m = p[_].size();
    memset(cnt, 0, sizeof cnt);
    for (int i = 0; i < m; i++) {
      int w = in[p[_][i]] - i;
      ans += cnt[w];
      cnt[w]++;
    }
  }
  cout << ans << endl;
}

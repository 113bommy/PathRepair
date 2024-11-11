#include <bits/stdc++.h>
using namespace std;
void FMT(long long *f, int n) {
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < (1 << n); ++j)
      if ((j >> i) & 1) f[j] += f[j ^ (1 << i)];
}
long long f[18][1 << 18], g[20][1 << 18], ans[1 << 18], h[1 << 18];
int n, bit[1 << 18];
long long calc(const vector<int> &S) {
  for (int i = 0; i < (1 << n); ++i) h[i] = 1;
  for (int x : S)
    for (int i = 0; i < (1 << n); ++i) h[i] *= g[x][i];
  long long res = 0;
  for (int i = 0; i < (1 << n); ++i)
    if ((n - bit[i]) & 1)
      res -= h[i];
    else
      res += h[i];
  return res;
}
char e[18][18];
map<vector<int>, vector<int>> P;
signed main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) cin >> e[i][j];
  for (int i = 0; i < n; ++i) f[i][1 << i] = 1;
  for (int i = 1; i < (1 << n); ++i) bit[i] = bit[i - (i & -i)] + 1;
  for (int i = 0; i < (1 << n); ++i)
    for (int j = 0; j < n; ++j) {
      if (i >> j & 1) {
        for (int k = 0; k < n; ++k)
          if (!(i >> k & 1) && e[j][k] == '1') f[k][i | (1 << k)] += f[j][i];
      }
      g[bit[i]][i] += f[j][i];
    }
  for (int i = 1; i <= n; ++i) FMT(g[i], n);
  for (int i = 0; i < (1 << n - 1); ++i) {
    vector<int> S;
    int cnt = 1;
    for (int j = 0; j < n; ++j)
      if (i >> j & 1)
        ++cnt;
      else
        S.push_back(cnt), cnt = 1;
    sort(S.begin(), S.end());
    P[S].push_back(i);
  }
  for (auto x : P) {
    long long tmp = calc(x.first);
    for (int id : (x.second)) ans[id] = tmp;
  }
  for (int i = 0; i < n - 1; ++i)
    for (int j = (1 << (n - 1)) - 1; j >= 0; --j)
      if (!(j >> i & 1)) ans[j] -= ans[j ^ (1 << i)];
  for (int i = 0; i < (1 << n - 1); ++i) cout << ans[i] << " ";
}

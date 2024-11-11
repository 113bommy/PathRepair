#include <bits/stdc++.h>
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using namespace std;
const int N = 61;
const ld eps = 1e-9;
int n, m, y[2][N], ans;
bool in[2][N];
vector<ld> po;
vector<int> cl[2];
vector<pair<int, int> > con[N * N];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  for (int i = (1); i <= (n); ++i) cin >> y[0][i];
  for (int i = (1); i <= (m); ++i) cin >> y[1][i];
  for (int i = (1); i <= (n); ++i)
    for (int j = (1); j <= (m); ++j) {
      int C = (-100 * y[1][j] - 100 * y[0][i]);
      ld Y = (ld)(-C) / 200.0;
      po.push_back(Y);
    }
  sort((po).begin(), (po).end());
  po.erase(unique((po).begin(), (po).end()), po.end());
  for (int i = (0); i <= (((int)(po).size()) - 1); ++i) {
    for (int j = (1); j <= (n); ++j)
      for (int k = (1); k <= (m); ++k) {
        int C = (-100 * y[1][k] - 100 * y[0][j]);
        if (abs(200.0 * po[i] + C) < eps) con[i].emplace_back(j, k);
      }
  }
  for (int i = (0); i <= (((int)(po).size()) - 1); ++i) {
    for (int j = (1); j <= (n); ++j) in[0][j] = 0;
    for (int j = (1); j <= (m); ++j) in[1][j] = 0;
    for (pair<int, int> e : con[i]) in[0][e.first] = in[1][e.second] = 1;
    int res = 0;
    for (int j = (1); j <= (n); ++j) res += in[0][j];
    for (int j = (1); j <= (m); ++j) res += in[1][j];
    for (int j = (i + 1); j <= (((int)(po).size()) - 1); ++j) {
      int tmp = 0;
      for (pair<int, int> e : con[j]) {
        if (!in[0][e.first]) tmp++, cl[0].emplace_back(e.first);
        if (!in[1][e.second]) tmp++, cl[1].emplace_back(e.second);
        in[0][e.first] = in[1][e.second] = 1;
      }
      for (int u : cl[0]) in[0][u] = 0;
      for (int u : cl[1]) in[1][u] = 0;
      cl[0].clear();
      cl[1].clear();
      ans = max(ans, res + tmp);
    }
    ans = max(ans, res);
  }
  cout << ans;
  return 0;
}

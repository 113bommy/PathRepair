#include <bits/stdc++.h>
using namespace std;
int n;
uint64_t a[100000];
vector<int> bits[64];
void solution() {
  cin >> n;
  for (int i = 0, _n = (n); i < _n; ++i) cin >> a[i];
  for (int i = 0, _n = (n); i < _n; ++i) {
    if (a[i] == 0) {
      bits[0].push_back(i);
      continue;
    }
    for (int j = 0, _n = (64); j < _n; ++j) {
      uint64_t b = 1ull << (uint64_t)j;
      if (a[i] & b) {
        bits[j].push_back(i);
      }
    }
  }
  vector<int> v;
  for (int i = 1; i < 64; i++) {
    if ((int)((bits[i]).size()) >= 3) {
      cout << 3 << endl;
      return;
    }
    for (int j = 0, _n = ((int)((bits[i]).size())); j < _n; ++j) {
      v.push_back(bits[i][j]);
    }
  }
  sort((v).begin(), (v).end());
  v.erase(unique((v).begin(), (v).end()), v.end());
  int sz = (int)((v).size());
  vector<vector<long long>> g(sz, vector<long long>(sz, 0x7f7f7f7f));
  vector<vector<int>> col(sz, vector<int>(sz, 0));
  int color = 0;
  for (int i = 0, _n = (sz); i < _n; ++i) {
    for (int j = 0, _n = (sz); j < _n; ++j) {
      if (i != j && (a[v[i]] & a[v[j]])) {
        g[i][j] = g[j][i] = 1;
        col[i][j] = col[j][i] = ++color;
      }
    }
  }
  vector<vector<long long>> g0 = g;
  for (int k = 0, _n = (sz); k < _n; ++k) {
    for (int i = 0, _n = (sz); i < _n; ++i) {
      for (int j = 0, _n = (sz); j < _n; ++j) {
        if (g[i][k] == 0x7f7f7f7f || g[k][j] == 0x7f7f7f7f) {
          continue;
        }
        if (g[i][j] > g[i][k] + g[k][j]) {
          g[i][j] = g[i][k] + g[k][j];
          col[i][j] = col[i][k];
        }
      }
    }
  }
  long long ans = 0x7f7f7f7f;
  for (int i = 0; i < sz; i++)
    for (int j = 0; j < sz; j++)
      if (i != j)
        for (int k = 0; k < sz; k++)
          if (k != i && k != j && col[i][j] != col[i][k])
            if (ans > g[i][j] + g[i][k] + g0[j][k])
              ans = g[i][j] + g[i][k] + g0[j][k];
  if (ans == 0x7f7f7f7f) {
    ans = -1;
  }
  cout << ans << endl;
}
int main() {
  solution();
  return 0;
}

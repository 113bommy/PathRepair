#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
int mul(int x, int y) { return (x * 1ll * y) % MOD; }
void add(int &x, int y) {
  x += y;
  while (x >= MOD) x -= MOD;
}
int sum(int x, int y) {
  add(x, y);
  return x;
}
void sub(int &x, int y) {
  x -= y;
  while (x < 0) x += MOD;
}
vector<vector<int> > gr;
vector<int> kol, ans[2], d[2];
vector<int> cs, cs2;
int n;
int main() {
  scanf("%d", &n);
  gr.assign(n, vector<int>());
  for (int i = 1; i < n; ++i) {
    int v;
    scanf("%d", &v);
    gr[v - 1].push_back(i);
  }
  kol.assign(n, 0);
  for (int i = n - 1; i >= 0; --i) {
    kol[i] = 1;
    for (int j = 0; j < (int)gr[i].size(); ++j) kol[i] += kol[gr[i][j]];
  }
  ans[0].assign(n, 0);
  ans[1].assign(n, 0);
  for (int v = n - 1; v >= 0; --v) {
    if (gr[v].empty()) {
      ans[0][v] = 0;
      ans[1][v] = 1;
    } else {
      ans[0][v] = 0;
      ans[1][v] = 0;
      for (int vvv = 0; vvv < 2; ++vvv) {
        d[0].assign(gr[v].size() + 1, 0);
        d[1].assign(gr[v].size() + 1, 0);
        d[0][0] = 1;
        for (size_t i = 0; i < gr[v].size(); ++i) {
          add(d[0][i + 1], mul(d[0][i], ans[0][gr[v][i]] + 1));
          add(d[1][i + 1], mul(d[1][i], ans[0][gr[v][i]] + 1));
          add(d[0][i + 1], mul(d[1][i], ans[1][gr[v][i]]));
          add(d[1][i + 1], mul(d[0][i], ans[1][gr[v][i]]));
        }
        add(ans[1][v], mul(d[0].back(), 1));
        add(ans[0][v], mul(d[1].back(), 1));
        reverse(gr[v].begin(), gr[v].end());
      }
      int dv = 1;
      for (size_t i = 0; i < gr[v].size(); ++i)
        dv = mul(dv, ans[0][gr[v][i]] + 1);
      sub(ans[1][v], dv);
      d[0].assign(gr[v].size() + 1, 0);
      d[1].assign(gr[v].size() + 1, 0);
      d[0][0] = 1;
      for (size_t i = 0; i < gr[v].size(); ++i) {
        add(d[0][i + 1], mul(d[0][i], 1));
        add(d[1][i + 1], mul(d[1][i], 1));
        add(d[0][i + 1], mul(d[1][i], ans[1][gr[v][i]]));
        add(d[1][i + 1], mul(d[0][i], ans[1][gr[v][i]]));
      }
      sub(ans[0][v], d[1].back());
    }
  }
  cout << sum(ans[0][0], ans[1][0]) << "\n";
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-10;
const int inf = 1000000009;
const int MOD = 1000000007;
int i, j, k, m, n, l, C;
vector<int> read() {
  int n;
  cin >> n;
  vector<int> res;
  while (n--) {
    int i;
    cin >> i;
    res.push_back(i);
  }
  return res;
}
vector<int> L, R;
map<vector<int>, int> M;
vector<vector<int> > ps;
int nexti[205][25], ncost[205][25];
int d[205][205][505];
int solve(int i, int left, int k) {
  if (k < 0) return 0;
  if (left == 0) return 1;
  int& ret = d[i][left][k];
  if (ret != -1) return ret;
  ret = 0;
  for (int digit = 0; digit < m; digit++) {
    ret += solve(nexti[i][digit], left - 1, k - ncost[i][digit]);
    if (ret >= MOD) ret -= MOD;
  }
  return ret;
}
int solve(vector<int> a, bool incl) {
  int n = ((int)a.size());
  int ret = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j <= a[i]; j++) {
      if (i == 0 && j == 0) continue;
      if (j == a[i] && (!incl || i != n - 1)) continue;
      int state = M[vector<int>()], cost = k;
      for (int l = 0; l <= i; l++) {
        int digit = (l == i ? j : a[l]);
        cost -= ncost[state][digit];
        state = nexti[state][digit];
      }
      ret += solve(state, n - i - 1, cost);
      if (ret >= MOD) ret -= MOD;
    }
  for (int i = 1; i <= n - 1; i++)
    for (int j = 1; j < m; j++) {
      int state = M[vector<int>()], cost = k;
      cost -= ncost[state][j];
      state = nexti[state][j];
      ret += solve(state, n - i - 1, cost);
      if (ret >= MOD) ret -= MOD;
    }
  return ret;
}
int main() {
  cin >> n >> m >> k;
  L = read();
  R = read();
  vector<vector<int> > patterns;
  vector<int> costs;
  C = 0;
  for (int i = 0; i < n; i++) {
    vector<int> a = read();
    int b;
    cin >> b;
    patterns.push_back(a);
    costs.push_back(b);
    while (1) {
      if (!M.count(a)) {
        ps.push_back(a);
        M[a] = C++;
      }
      if (a.empty()) break;
      a.pop_back();
    }
  }
  for (int i = 0; i < C; i++) {
    for (int j = 0; j < m; j++) {
      ncost[i][j] = 0;
      vector<int> x = ps[i];
      x.push_back(j);
      for (int o = 0; o < n; o++)
        if (((int)x.size()) >= ((int)patterns[o].size())) {
          int start = ((int)x.size()) - ((int)patterns[o].size());
          if (equal(x.begin() + start, x.end(), patterns[o].begin()))
            ncost[i][j] += costs[o];
        }
      while (!M.count(x)) {
        x.erase(x.begin());
      }
      nexti[i][j] = M[x];
    }
  }
  memset(d, -1, sizeof(d));
  int ans = solve(R, true);
  ans -= solve(L, false);
  if (ans < 0) ans += MOD;
  cout << ans << endl;
  return 0;
}

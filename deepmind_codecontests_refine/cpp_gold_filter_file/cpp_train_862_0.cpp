#include <bits/stdc++.h>
using namespace std;
const unsigned long long MOD1 = 1e9 + 7, MOD2 = 1e9 + 9, MMOD1 = MOD1 * MOD1,
                         MMOD2 = MOD2 * MOD2;
const long long INF = 1e18;
const double pi = 3.14159265358979;
const int N = 709, inf = 1e9, mod = 1e9 + 7;
string s;
int nxt[N];
void add(long long &a, long long b) {
  a += b;
  a %= mod;
}
long long my_rand() {
  long long a = rand();
  long long b = rand();
  return a * (RAND_MAX + 1) + b;
}
void init() {}
vector<vector<long long> > cont(vector<vector<long long> > tmp) {
  vector<vector<long long> > res;
  for (int i = 0; i < 3; i++) {
    res.emplace_back(vector<long long>(3));
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 3; k++) {
        for (int d = 0; d < 3; d++) {
          if ((i == k && i != 0) || (j == d && j != 0)) {
          } else if ((i == 0 && j != 0) || (i != 0 && j == 0)) {
            add(res[i][j], tmp[k][d]);
          }
        }
      }
    }
  }
  return res;
}
vector<vector<long long> > merge(vector<vector<long long> > dp,
                                 vector<vector<long long> > tmp) {
  vector<vector<long long> > res;
  for (int i = 0; i < 3; i++) {
    res.emplace_back(vector<long long>(3));
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 3; k++) {
        for (int d = 0; d < 3; d++) {
          if (j != k || (j == 0) || k == 0) {
            add(res[i][d], dp[i][j] * tmp[k][d]);
          }
        }
      }
    }
  }
  return res;
}
vector<vector<long long> > dfs(int l, int r) {
  vector<vector<long long> > dp, res;
  for (int i = 0; i < 3; i++) {
    dp.emplace_back(vector<long long>(3));
  }
  if (l + 1 == r) {
    dp[1][0]++;
    dp[0][1]++;
    dp[2][0]++;
    dp[0][2]++;
    return dp;
  }
  if (nxt[l] < r) {
    dp = merge(dfs(l, nxt[l]), dfs(nxt[l] + 1, r));
  } else
    dp = cont(dfs(l + 1, nxt[l] - 1));
  return dp;
}
int main() {
  srand(chrono::steady_clock::now().time_since_epoch().count());
  ios::sync_with_stdio(false), cin.tie(0);
  init();
  cin >> s;
  vector<int> V;
  for (int i = 0; i < int(s.size()); i++) {
    if (s[i] == '(') {
      V.emplace_back(i + 1);
    } else {
      nxt[V.back()] = i + 1;
      V.pop_back();
    }
  }
  vector<vector<long long> > dp;
  dp = dfs(1, int(s.size()));
  long long ans = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      add(ans, dp[i][j]);
    }
  }
  cout << ans << '\n';
  return 0;
}

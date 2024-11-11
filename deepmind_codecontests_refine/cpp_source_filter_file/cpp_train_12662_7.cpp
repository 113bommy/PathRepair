#include <bits/stdc++.h>
using namespace std;
const long long inf = (long long)1e9 + 10;
const long long linf = (long long)1e18 + 10;
const long long mod = (long long)(1e9 + 7);
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const int ddx[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int ddy[] = {1, 1, 0, -1, -1, -1, 0, 1};
const double eps = 1e-10;
struct oreno_initializer {
  oreno_initializer() {
    cin.tie(0);
    ios::sync_with_stdio(0);
  }
} oreno_initializer;
int n, a, id[77];
long long res, b[77], pw[100100], dp[2][1 << 19];
vector<int> p;
signed main() {
  for (int(i) = (2); (i) < ((70) + 1); ++(i)) {
    bool pr = true;
    for (int(j) = (2); (j) < (i); ++(j))
      if (i % j == 0) pr = false;
    if (pr) p.push_back(i);
  }
  for (int(i) = (1); (i) < ((70) + 1); ++(i)) {
    int t = i;
    for (int(j) = (0); (j) < (19); ++(j)) {
      if (t % p[j] != 0) continue;
      int m = 0;
      while (t % p[j] == 0) t /= p[j], m ^= 1;
      id[i] |= m << j;
    }
  }
  pw[0] = 1;
  for (int(i) = (1); (i) < ((100000) + 1); ++(i)) pw[i] = pw[i - 1] * 2 % mod;
  cin >> n;
  for (int(i) = (0); (i) < (n); ++(i)) {
    cin >> a;
    b[a]++;
  }
  dp[0][0] = 1;
  for (int(i) = (0); (i) < ((70) + 1); ++(i)) {
    for (int(j) = (0); (j) < (1 << 19); ++(j)) {
      if (b[i % 2] == 0) {
        dp[(i + 1) % 2][j] = dp[i % 2][j];
        continue;
      }
      (dp[(i + 1) % 2][j] += dp[i % 2][j] * pw[b[i] - 1]) %= mod;
      (dp[(i + 1) % 2][j ^ id[i]] += dp[i % 2][j] * pw[b[i] - 1]) %= mod;
    }
    fill(dp[i % 2], dp[i % 2] + (1 << 19), 0);
  }
  cout << (dp[71 % 2][0] + mod - 1) % mod << '\n';
}

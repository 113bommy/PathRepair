#include <bits/stdc++.h>
using namespace std;
template <class T1, class T2, class T3 = hash<T1>>
using umap = unordered_map<T1, T2, T3>;
template <class T>
using uset = unordered_set<T>;
template <class T>
using vec = vector<T>;
const long long infll = numeric_limits<long long>::max() >> 1;
const long long inf = numeric_limits<long long>::max() >> 1;
const long long N = 501;
long long n, k;
long long a[N];
long long b[N];
long long dp[N][N];
long long db[N][N];
void input() {
  cin >> n >> k;
  for (long long i = 1; i <= n; ++i) {
    cin >> a[i];
    cin >> b[i];
  }
}
long long mod(long long x) { return x >= k ? x - k : x; }
long long div(long long x) { return x >= k ? 1 : 0; }
long long calc(long long i, long long x, long long y) {
  if (i > n) {
    return 0;
  }
  if (dp[i][x] != -1) {
    return dp[i][x];
  }
  long long res = 0;
  for (long long j = 0; j < min(a[i] + 1, k); ++j) {
    long long l = (a[i] + b[i] - j) % k;
    if (l > b[i]) {
      continue;
    }
    res = max(res, calc(i + 1, mod(x + j), mod(y + l)) + (a[i] + b[i] - j) / k +
                       div(x + j) + div(y + l));
  }
  return dp[i][x] = res;
}
long long calc() {
  long long res = 0;
  dp[1][0] = 0;
  db[1][0] = 0;
  for (int i = 1; i <= n + 1; ++i) {
    for (int x = 0; x < k; ++x) {
      if (dp[i][x] == -1) {
        continue;
      }
      if (i > n) {
        res = max(res, dp[i][x]);
        continue;
      }
      long long y = db[i][x];
      for (long long j = 0; j < min(a[i] + 1, k); ++j) {
        long long l = (a[i] + b[i] - j) % k;
        if (l > b[i]) {
          continue;
        }
        db[i + 1][mod(x + j)] = mod(y + l);
        dp[i + 1][mod(x + j)] =
            max(dp[i + 1][mod(x + j)],
                dp[i][x] + (a[i] + b[i] - j) / k + div(x + j) + div(y + l));
      }
    }
  }
  return res;
}
void solve() {
  memset(dp, -1, sizeof dp);
  cout << calc() << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  input();
  solve();
}

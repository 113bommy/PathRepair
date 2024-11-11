#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using int64 = long long int;
template <typename T>
void chmax(T &a, T b) {
  a = max(a, b);
}
template <typename T>
void chmin(T &a, T b) {
  a = min(a, b);
}
template <typename T>
void chadd(T &a, T b) {
  a = a + b;
}
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
const ll INF = 1001001001001001LL;
const ll MOD = 1000000007LL;
const int SIZE = 1 << 25;
int64 dp[SIZE + 10];
int main() {
  fill(dp, dp + SIZE + 5, INF);
  int N, X, Y;
  cin >> N >> X >> Y;
  dp[1] = X;
  {
    int p = 1;
    while (p * 2 < SIZE) {
      int np = p * 2;
      dp[np] = min({dp[np], dp[p] + Y, dp[p] + (np - p) * X});
      p = np;
    }
  }
  int l = 1, r;
  while (l < SIZE) {
    for (r = l + 1;; r++) {
      bool f = dp[r] == INF;
      chmin(dp[r], dp[r - 1] + X);
      if (f) break;
    }
    int L = l, R = r;
    for (int i = R - 1; i >= L - 1; i--) {
      chmin(dp[i], dp[i + 1] + X);
    }
    for (int i = L; i < R; i++) {
      int p = i;
      while (p * 2 < SIZE) {
        int np = p * 2;
        dp[np] = min({dp[np], dp[p] + Y, dp[p] + (np - p) * X});
        p = np;
      }
    }
    l = R;
  }
  cout << dp[N] << endl;
  return 0;
}

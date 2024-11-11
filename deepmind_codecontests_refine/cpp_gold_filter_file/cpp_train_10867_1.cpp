#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1030;
int a[MAXN];
int x[MAXN];
int y[MAXN];
int d, N;
int dp[MAXN];
int dist(int i, int j) { return abs(x[i] - x[j]) + abs(y[i] - y[j]); }
bool solve(int V) {
  memset(dp, -1, sizeof(dp));
  dp[1] = V;
  for (int t = 0; t < N; ++t) {
    for (int i = 1; i < N; ++i)
      if (dp[i] >= 0) {
        for (int j = 1; j <= N; ++j) {
          if (i != j) {
            dp[j] = max(dp[j], dp[i] + a[i] - dist(i, j) * d);
          }
        }
      }
    if (dp[N] != -1) return 1;
  }
  return 0;
}
int main() {
  cin >> N >> d;
  for (int i = 2; i < N; ++i) {
    cin >> a[i];
  }
  for (int i = 1; i <= N; ++i) {
    cin >> x[i] >> y[i];
  }
  int low = 0, high = 1000000000;
  while (low + 1 < high) {
    int mid = (low + high) >> 1;
    if (solve(mid))
      high = mid;
    else
      low = mid;
  }
  cout << high << endl;
  return 0;
}

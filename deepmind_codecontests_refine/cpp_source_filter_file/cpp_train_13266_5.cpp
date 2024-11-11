#include <bits/stdc++.h>
using namespace std;
const long long INF = 4e18;
long long dp[(1 << 20) + 100];
struct M {
  int cost;
  int nd;
  int mask;
  void read() {
    mask = 0;
    int n;
    cin >> cost >> nd >> n;
    for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      x--;
      mask = mask | (1 << x);
    }
  }
  bool operator<(const M &a) const { return cost < a.cost; }
};
int main() {
  for (int i = 0; i < (1 << 20); i++) dp[i] = INF;
  long long n, m, b;
  cin >> n >> m >> b;
  M mm[n];
  for (int i = 0; i < n; i++) mm[i].read();
  sort(mm, mm + n);
  long long ans = INF;
  dp[0] = 0;
  for (int i = 0; i < n; i++) {
    long long currm = mm[i].mask;
    long long currc = mm[i].cost;
    long long currb = mm[i].nd;
    for (int j = 0; j < (1 << m); j++) {
      dp[j | currm] = min(dp[j | currm], dp[j] + currc);
    }
    ans = min(ans, dp[(1 << m) - 1] + b * currb);
  }
  if (ans == INF) {
    cout << "-1";
  } else {
    cout << ans;
  }
  return 0;
}

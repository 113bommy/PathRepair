#include <bits/stdc++.h>
using namespace std;
const int MAXN = 555;
const long long INF = 0x3f3f3f3f3f3f3f3fLL;
long long n;
vector<vector<long long>> bak;
long long mem[MAXN][MAXN][2];
long long dp(int i, int need, bool b = 0) {
  long long &ans = mem[i][need][b];
  if (ans != -INF) return ans;
  if (i == n && need) return -INF + 1;
  if (i == n && !need) return 0;
  ans = 0;
  ans = max(ans, bak[i][1] - bak[i][0] * bak[i][2] + dp(i + 1, need, b));
  if (need) {
    ans = max(ans, bak[i][1] - bak[i][0] * min(bak[i][2], (long long)need) +
                       dp(i + 1, need - 1, b));
  }
  if (!b) {
    ans = max(ans, bak[i][1] + dp(i + 1, need, 1));
  }
  ans = max(ans, dp(i + 1, need, b));
  return ans;
}
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a, b, k;
    cin >> a >> b >> k;
    bak.push_back({b, a, k});
  }
  sort(bak.begin(), bak.end());
  for (int b = 0; b < 2; b++) {
    for (int i = 0; i < n + 10; i++) {
      for (int j = 0; j < n + 10; j++) {
        mem[i][j][b] = -INF;
      }
    }
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    ans = max(ans, dp(0, i, 0));
  }
  cout << ans << endl;
}

#include <bits/stdc++.h>
using namespace std;
const int N = 200;
typedef long long matrix[N][N];
const long long MOD = 1000000007;
const double EPS = 1e-8;
const double PI = 2 * acos(0);
const int maxn = 1e6 + 6;
int y[3], m[3], c[3];
bool check(int i, int j, int k) {
  int dmp = max(0, j - m[2]);
  int dfs = max(0, m[1] - k);
  if (dmp == 0) return false;
  if (dmp > 0 && dfs == 0) return true;
  if (dmp == 0 && dfs == 0) return false;
  int t1 = (m[0] / dmp) + (m[0] % dmp != 0);
  int t2 = (i / dfs) + (i % dfs != 0);
  if (t1 < t2)
    return true;
  else
    return false;
}
int main() {
  cin.sync_with_stdio(false);
  cin >> y[0] >> y[1] >> y[2];
  cin >> m[0] >> m[1] >> m[2];
  cin >> c[0] >> c[1] >> c[2];
  int ans = 1000000009;
  for (int i = y[0]; i <= 700; i++) {
    for (int j = y[1]; j <= 200; j++) {
      for (int k = y[2]; k <= 200; k++) {
        if (check(i, j, k)) {
          int cost = (i - y[0]) * c[0] + (j - y[1]) * c[1] + (k - y[2]) * c[2];
          if (cost < ans) {
            ans = cost;
          }
        }
      }
    }
  }
  cout << ans;
}

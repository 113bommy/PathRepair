#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
void solve() {
  int n;
  cin >> n;
  long long a[n + 1][n + 1];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) cin >> a[i + 1][j + 1];
  vector<long long> leftsum(2 * n + 1, 0), rightsum(2 * n + 1, 0);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int left = i - j;
      if (left < 0) left += 2 * n;
      leftsum[left] += a[i][j];
      rightsum[i + j] += a[i][j];
    }
  }
  long long x1, y1, x2, y2, sum = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int left = i - j;
      if (left < 0) left += 2 * n;
      if (sum < leftsum[left] + rightsum[i + j] - a[i][j]) {
        sum = leftsum[left] + rightsum[i + j] - a[i][j];
        x1 = i;
        y1 = j;
      }
    }
  }
  long long ans = sum;
  sum = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if ((i + j) % 2 == (x1 + y1) % 2) continue;
      int left = i - j;
      if (left < 0) left += 2 * n;
      if (sum < leftsum[left] + rightsum[i + j] - a[i][j]) {
        sum = leftsum[left] + rightsum[i + j] - a[i][j];
        x2 = i;
        y2 = j;
      }
    }
  }
  ans += sum;
  cout << ans << "\n";
  cout << x1 << " " << y1 << " " << x2 << " " << y2 << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int p[5000001];
int main() {
  ios::sync_with_stdio(false);
  int n, ans = 0;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> p[i];
    p[i] += p[i - 1];
  }
  for (int i = 1; i <= n; ++i) {
    for (int m = 1; m + i - 1 <= n; ++m) {
      if (p[m + i - 1] - p[i - 1] > m * 100) {
        ans = max(ans, m);
      }
    }
  }
  cout << ans;
  return 0;
}

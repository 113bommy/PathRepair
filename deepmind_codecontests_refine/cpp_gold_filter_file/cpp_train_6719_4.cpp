#include <bits/stdc++.h>
const int MAXN = 1e5 * 5;
const int INF = 1e9 + 7;
const int N = 5000;
using namespace std;
int n, a, c[N], ans;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> a;
  for (int i = 1; i <= n; ++i) cin >> c[i];
  if (c[a]) ++ans;
  for (int i = 1; i <= max(a - 1, n - a); ++i) {
    int d1 = 0, d2 = 0;
    if (a - i > 0) {
      ++d1;
      d2 += c[a - i];
    }
    if (a + i <= n) {
      d2 += c[a + i];
      ++d1;
    }
    if (d1 == d2) ans += d2;
  }
  cout << ans;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
using longs = long long;
constexpr int inf = 0x3f3f3f3f;
constexpr double eps = 1e-8;
const int N = 1e5 + 5;
const int off = 1e5;
int a[N], lb[3 * N], rb[3 * N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) cin >> a[i];
  if (n <= 0)
    cout << 0 << endl;
  else {
    for (int i = m; i >= 1; --i) {
      rb[off + a[i] - i] = rb[off + a[i] - i - 1] + 1;
      lb[off + a[i] + i] = lb[off + a[i] + i + 1] + 1;
    }
    longs cnt = 0;
    for (int i = 1; i <= n; ++i)
      cnt += min(n, i + (m + 1) - rb[off + i]) -
             max(1, i - (m + 1) + lb[off + i]) + 1;
    cout << cnt << endl;
  }
  return 0;
}

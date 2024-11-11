#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
const int inf = 1 << 30;
const double eps = 1e-6;
int n, m, k;
long long a[maxn], b[maxn];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= m; i++) cin >> b[i];
  sort(a + 1, a + n + 1);
  sort(b + 1, b + m + 1);
  int ans = 0;
  if (max(a[1] * b[1], a[1] * b[m]) > max(a[n] * b[1], a[n] * b[m])) {
    ans = max(max(a[2] * b[1], a[2] * b[m]), max(a[n] * b[1], a[n] * b[m]));
  } else {
    ans = max(max(a[1] * b[1], a[1] * b[m]),
              max(a[n - 1] * b[1], a[n - 1] * b[m]));
  }
  cout << ans;
  return 0;
}

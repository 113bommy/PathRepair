#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, m;
long long a[N], c[N];
long long check(int x) {
  long long res = 0;
  for (int i = 1; i <= n; i++) {
    a[i] = c[i] - 1ll * n * x * (x - 1) / 2 - 1ll * i * x;
    res -= a[i] - c[i];
    if (a[i] < 0) return 0;
  }
  int lst = m;
  for (int i = x * n; i >= 1; i--) {
    if (i == lst) return res;
    int v = (i - 1) % n + 1, x = min(0ll + lst - i, a[v]);
    a[v] -= x, res += x, lst = i + x - 1;
  }
  return res;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> c[i];
  int dw = 0, up = m / n;
  while (up - dw > 2) {
    int md = (up + dw) >> 1;
    if (check(md) >= check(md + 1))
      up = md;
    else
      dw = md + 1;
  }
  long long ans = 0;
  for (int i = dw; i <= up; i++) ans = max(ans, check(i));
  cout << ans << "\n";
  return 0;
}

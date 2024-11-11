#include <bits/stdc++.h>
using namespace std;
const long long N = 3e5 + 5, mod = 1e9 + 7, MAX = (1 << 18), oo = 1e18;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
long long n, m, k;
long long arr[N];
int main() {
  int n, k;
  cin >> n >> k;
  int l, r;
  cin >> l >> r;
  int fl = l, fr = r;
  double ans = 0;
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    int x = r / k - (l - 1) / k;
    int y = b / k - (a - 1) / k;
    long long d = x * (b - a + 1ll) + y * (r - l + 1ll - x);
    long long tot = (r - l + 1ll) * (b - a + 1ll);
    ans += (double)d * 2000.0 / tot;
    l = a;
    r = b;
  }
  int a = fl, b = fr;
  int x = r / k - (l - 1) / k;
  int y = b / k - (a - 1) / k;
  long long d = x * (b - a + 1ll) + y * (r - l + 1ll - x);
  long long tot = (r - l + 1ll) * (b - a + 1ll);
  ans += (double)d * 2000.0 / tot;
  cout << fixed << setprecision(10) << ans;
  return 0;
}

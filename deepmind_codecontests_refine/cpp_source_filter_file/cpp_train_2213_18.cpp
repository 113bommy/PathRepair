#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 10;
int a[N], b[N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int n, m;
  cin >> n >> m;
  int x, k, y;
  cin >> x >> k >> y;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= m; i++) cin >> b[i];
  a[n + 1] = b[n + 1] = -1;
  long long ans = 0;
  for (int i = 1, j = 0; i <= m + 1; i++) {
    int l = j + 1, r = j + 1, len = 0, maxx = -1;
    while (r <= n + 1 && a[r] != b[i]) maxx = max(maxx, a[r]), r++;
    if (r > n + 1) {
      ans = -1;
      break;
    }
    len = r - l;
    if (len < k) {
      if (maxx > max(a[l - 1], a[r])) {
        ans = -1;
        break;
      } else
        ans += 1ll * y * len;
    } else {
      if (maxx > max(a[l - 1], a[r])) {
        ans += 1ll * x;
        len -= k;
        if (x < 1ll * k * y)
          ans += 1ll * (len / k) * x + 1ll * (len % k) * y;
        else
          ans += 1ll * y * len;
      } else {
        if (x < 1ll * k * y)
          ans += 1ll * (len / k) * x + 1ll * (len % k) * y;
        else
          ans += 1ll * y * len;
      }
    }
    if (a[r] != b[i])
      j = r + 1;
    else
      j = r;
  }
  cout << ans << endl;
  return 0;
}

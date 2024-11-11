#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
long long a[N], b[N], c[N], d[N];
int main() {
  long long n, m, k, x, s;
  cin >> n >> m >> k >> x >> s;
  for (int i = 1; i <= m; i++) cin >> a[i];
  for (int i = 1; i <= m; i++) cin >> b[i];
  for (int i = 1; i <= k; i++) cin >> c[i];
  for (int i = 1; i <= k; i++) cin >> d[i];
  long long mn = n * x;
  for (int i = 1; i <= k; i++) {
    if (d[i] <= s && c[i] >= n) mn = 0;
    if (d[i] <= s && c[i] < n) mn = min(mn, (n - c[i]) * x);
  }
  for (int i = 1; i <= m; i++) {
    int l = 0, r = k + 1, mid;
    if (s - b[i] < 0) continue;
    while (r - l > 1) {
      mid = (l + r) / 2;
      if (d[mid] <= s - b[i])
        l = mid;
      else
        r = mid;
    }
    mn = min(mn, a[i] * (n - c[l]));
  }
  cout << mn;
}

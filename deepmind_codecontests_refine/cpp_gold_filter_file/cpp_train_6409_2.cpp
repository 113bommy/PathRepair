#include <bits/stdc++.h>
using namespace std;
int n, m, k, x, s, a[200010], b[200010], c[200010], d[200010];
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m >> k >> x >> s;
  for (int i = 1; i <= m; i++) cin >> a[i];
  for (int i = 1; i <= m; i++) cin >> b[i];
  for (int i = 1; i <= k; i++) cin >> c[i];
  for (int i = 1; i <= k; i++) cin >> d[i];
  long long res = trunc(1e19);
  a[0] = x;
  for (int i = 0; i <= m; i++) {
    if (s < b[i]) continue;
    int dau = 1;
    int cuoi = k;
    while (dau <= cuoi) {
      int giua = (dau + cuoi) / 2;
      if (d[giua] <= s - b[i])
        dau = giua + 1;
      else
        cuoi = giua - 1;
    }
    res = min(res, 1ll * (max(n - c[dau - 1], 0)) * a[i]);
  }
  cout << res;
}

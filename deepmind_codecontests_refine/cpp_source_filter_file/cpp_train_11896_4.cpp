#include <bits/stdc++.h>
using namespace std;
long long i, j, d, p, q, n, m, k, b[100006], a[100006], br, ans;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> d >> m;
  for (i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  for (i = 1; i <= n; i++) {
    b[i] = b[i - 1] + a[i];
    if (a[i] > m) break;
  }
  j = i - 1;
  for (i = n; i >= 1; i--) {
    p += a[i];
    if (a[i] > m)
      br = (n - i) * (d + 1) + 1;
    else
      break;
    if (br > n) break;
    k = p + b[j] - b[max(j - (n - br), q)];
    ans = max(k, ans);
  }
  cout << ans << '\n';
  return 0;
}

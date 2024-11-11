#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k, M, x, y, z, s = 0, c, ans = 0, i, j;
  cin >> n >> k >> M;
  long long t[k];
  for (i = 0; i < k; i++) {
    cin >> t[i];
    s = s + t[i];
  }
  sort(t, t + k);
  for (i = 0; i <= n; i++) {
    if (M < (i * s)) break;
    x = M - i * s;
    if (i == n) {
      ans = max(ans, (k + 1) * n);
      break;
    }
    if (x == 0) {
      ans = max(ans, (k + 1) * i);
      break;
    }
    c = 0;
    y = x;
    z = 0;
    long long p;
    for (j = 0; j < k; j++) {
      p = y / t[j];
      z = z + min(p, n - i);
      y = y - min(p, n - i) * t[j];
    }
    ans = max(ans, (k + 1) * i + z);
  }
  cout << ans << endl;
  return 0;
}

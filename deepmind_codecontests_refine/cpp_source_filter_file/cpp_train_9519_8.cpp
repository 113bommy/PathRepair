#include <bits/stdc++.h>
using namespace std;
int main() {
  long long i, j, n, x, k, p, t, c, d, m, ans = 1000000;
  cin >> c >> d >> n >> m >> k;
  x = n * m - k;
  for (i = 0; i <= 100; i++) {
    for (j = 0; j <= 100; j++) {
      long long p;
      p = i * n + j * 1;
      if (p >= x) ans = min(ans, i * c + j * d);
    }
  }
  cout << ans;
}

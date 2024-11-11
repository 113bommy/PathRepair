#include <bits/stdc++.h>
using namespace std;
void read_file(bool outToFile = true) {}
int n, m, h, s, sh;
long double prob(int j) {
  long double ret = 1;
  for (int t = s - sh; t >= s - sh - n + j + 1; t--) ret *= t;
  for (int t = s; t >= s - n + 1; t--) ret /= t;
  for (int t = n; t >= n - j + 1; t--) ret *= t;
  for (int t = j; t >= 1; t--) ret /= t;
  for (int t = sh; t >= sh - j + 1; t--) ret *= t;
  return ret;
}
int main() {
  read_file();
  while (cin >> n >> m >> h) {
    s = -1;
    n--;
    h--;
    for (int i = 0; i < m; i++) {
      int x;
      cin >> x;
      if (i == h) sh = x - 1;
      s += x;
    }
    if (s < n) {
      cout << -1 << '\n';
      continue;
    }
    double ans = 0;
    for (int j = 1; j <= sh; j++) {
      if (0 <= n - j && n - j <= s - sh) ans += prob(j);
    }
    printf("%f\n", ans);
  }
}

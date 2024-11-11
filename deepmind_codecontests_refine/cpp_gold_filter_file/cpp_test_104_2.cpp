#include <bits/stdc++.h>
using namespace std;
int T, a[200010], b[200010], l[200010], r[200010];
int main() {
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    long long suma = 0, sumb = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a[i] >> b[i];
      suma += a[i], sumb += b[i];
    }
    long long suml = 0, sumr = 0;
    for (int i = 1; i <= n; i++) {
      l[i] = max(0, m - b[i]);
      r[i] = min(m, a[i]);
      suml += l[i];
      sumr += r[i];
    }
    if (suma - suml <= sumb - ((long long)n * m - suml)) {
      cout << (sumb - ((long long)n * m - suml)) - (suma - suml) << endl;
      for (int i = 1; i <= n; i++) {
        cout << l[i] << " " << m - l[i] << endl;
      }
    } else if (suma - sumr >= sumb - ((long long)n * m - sumr)) {
      cout << (suma - sumr) - (sumb - ((long long)n * m - sumr)) << endl;
      for (int i = 1; i <= n; i++) {
        cout << r[i] << " " << m - r[i] << endl;
      }
    } else {
      long long v = (suma - suml) - (sumb - ((long long)n * m - suml));
      cout << (v & 1) << endl;
      for (int i = 1; i <= n; i++) {
        if (v >= (r[i] - l[i]) * 2) {
          v -= (r[i] - l[i]) * 2;
          cout << r[i] << " " << m - r[i] << endl;
        } else {
          cout << l[i] + v / 2 << " " << m - (l[i] + v / 2) << endl;
          v -= v / 2 * 2;
        }
      }
    }
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long tt = 1;
  cin >> tt;
  while (tt--) {
    long long b, w;
    cin >> b >> w;
    if (min(b, w) * 3 + 1 < max(b, w)) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    if (b < w) {
      long long si = 2;
      long long sj = 2;
      for (long long i = 0; i < 2 * b + 1; i++)
        cout << si << " " << sj << endl, sj++;
      w -= (b + 1);
      si = 3;
      sj = 1;
      for (long long i = 0; i < w; i++) {
        cout << si << " " << sj << endl;
        if (i % 2 == 0)
          sj += 2;
        else
          sj -= 2, si += 2;
      }
    } else if (b > w) {
      long long si = 2;
      long long sj = 3;
      for (long long i = 0; i < 2 * w + 1; i++)
        cout << si << " " << sj << endl, sj++;
      b -= (w + 1);
      si = 3;
      sj = 2;
      for (long long i = 0; i < b; i++) {
        cout << si << " " << sj << endl;
        if (i % 2 == 0)
          sj += 2;
        else
          sj -= 2, si += 2;
      }
    } else {
      long long si = 1;
      long long sj = 1;
      for (long long i = 0; i < 2 * b; i++)
        cout << si << " " << sj << endl, si++;
    }
  }
}

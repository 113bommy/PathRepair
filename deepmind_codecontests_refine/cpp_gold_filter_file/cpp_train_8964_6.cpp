#include <bits/stdc++.h>
using namespace std;
int n;
int f, g, t, vf;
int main() {
  cin.sync_with_stdio(false);
  cout.sync_with_stdio(false);
  cin >> n;
  for (int d = 2; d * d <= n; d++)
    if (n % d == 0) {
      f = d;
      g = n / d;
      for (int h1 = 1; h1 < min(f, 5000); h1++) {
        int h2 = n - 1 - h1 * g;
        if (h2 % f) continue;
        h2 /= f;
        vf = h1 / f + h2 / g;
        if (h1 * g + h2 * f == n - 1) {
          cout << "YES" << '\n';
          cout << 2 << '\n';
          cout << h1 << ' ' << d << '\n';
          cout << h2 << ' ' << n / d << '\n';
          return 0;
        }
      }
      for (int h1 = f - 1; h1 >= max(1, f - 5000); h1--) {
        int h2 = n - 1 - h1 * g;
        if (h2 % f) continue;
        h2 /= f;
        vf = h1 / f + h2 / g;
        if (h1 * g + h2 * f == n - 1) {
          cout << "YES" << '\n';
          cout << 2 << '\n';
          cout << h1 << ' ' << d << '\n';
          cout << h2 << ' ' << n / d << '\n';
          return 0;
        }
      }
    }
  cout << "NO";
}

#include <bits/stdc++.h>
using namespace std;
long long n, m, s, f, t;
int main() {
  while (cin >> n >> m) {
    for (long long i = 0; i < n; ++i) {
      cin >> s >> f >> t;
      s--;
      f--;
      long long r = (t / (2 * (m - 1))) * (2 * (m - 1));
      long long ans;
      if (f > s) {
        if (t % (2 * (m - 1)) > s)
          ans = r + 2 * (m - 1) + f;
        else
          ans = r + f;
      } else if (f < s) {
        if (t % (2 * (m - 1)) <= 2 * m - 1 - s)
          ans = r + 2 * m - 2 - f;
        else
          ans = r + 4 * (m - 1) - f;
      } else
        ans = t;
      cout << ans << endl;
    }
  }
}

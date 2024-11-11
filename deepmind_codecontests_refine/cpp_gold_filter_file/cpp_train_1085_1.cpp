#include <bits/stdc++.h>
using namespace std;
inline long long bs(long long a) { return a > 0 ? a : -a; }
int main() {
  int n, x, m, y;
  while (cin >> n >> x >> m >> y) {
    long long ans = n + 1;
    for (int i = 1; i <= m; i++) {
      long long a = y - i - x;
      long long b = y + i - x;
      if (a * b >= 0) {
        a = bs(a);
        b = bs(b);
        if (a > n) a = n + 1;
        if (b > n) b = n + 1;
        if (a < n || b < n)
          ans += (bs(a - b) - 1) * 2;
        else
          ans += 1;
      } else {
        a = bs(a);
        b = bs(b);
        if (a > n) a = n + 1;
        if (b > n) b = n + 1;
        if (a < n || b < n)
          ans += (bs(a - b)) * 2 - 1;
        else
          ans += 1;
      }
    }
    cout << ans << endl;
  }
}

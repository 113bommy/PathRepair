#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, a, b, ans = 0;
  cin >> n >> m >> a >> b;
  if (a == 1 && b == n || m == 1)
    cout << 1;
  else {
    if (a == b)
      cout << 1;
    else if (a < m && b <= m)
      cout << 1;
    else if (a == 1) {
      if (b % m == 0)
        cout << 1;
      else
        cout << 2;
    } else if (a <= m) {
      ans++;
      if (b % m == 0 || b == n || b <= m * 2 || (b > m * 2 && b % m == a - 1))
        ans++;
      else
        ans += 2;
      cout << ans;
    } else if (a > m) {
      if (a % m != 0 && (a + (m - (a % m))) >= b)
        cout << 1;
      else {
        if (a % m == 1) {
          if (b == n || b % m == 0)
            cout << 1;
          else
            cout << 2;
        } else {
          ans++;
          if (b == n || b % m == 0)
            ans++;
          else if (a % m == 0) {
            if (a + m >= b || b % m == m - 1)
              ans++;
            else
              ans += 2;
          } else if ((a + (m - (a % m))) + m >= b ||
                     (b > m * 2 && b % m == a - 1))
            ans++;
          else
            ans += 2;
          cout << ans;
        }
      }
    }
  }
  return 0;
}

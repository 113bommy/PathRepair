#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int a, b, c, n, d, i;
  cin >> n >> a >> b >> c >> d;
  long long int ans = 0, ans1 = 0, ans2 = 0;
  int x = abs(a - d);
  int y = abs(b - c);
  if (x != 0 && y == 0) {
    for (i = 1; i <= n; i++) {
      if (a > d) {
        if (i + abs(a - d) > 0 && i + abs(a - d) <= n) ans1++;
      } else if (a < d) {
        if (i - abs(a - d) > 0 && i - abs(a - d) <= n) ans1++;
      }
    }
    ans = n * (ans1);
    cout << ans << "\n";
  } else if (y != 0 && x == 0) {
    for (i = 1; i <= n; i++) {
      if (b > c) {
        if (i + abs(b - c) > 0 && i + abs(b - c) <= n) ans2++;
      } else if (c > b) {
        if (i - abs(b - c) > 0 && i - abs(b - c) <= n) ans2++;
      }
    }
    ans = n * (ans2);
    cout << ans << "\n";
  } else if (x == 0 && y == 0) {
    ans = n;
    cout << ans << "\n";
  } else if (x != 0 && y != 0) {
    int flag = 0, ans3 = 0;
    for (i = 1; i <= n; i++) {
      if (a - d > 0) {
        if (i + abs(a - d) > 0 && i + abs(a - d) <= n) {
          if (b > c) {
            if (i + abs(b - c) > 0 && i + abs(b - c) <= n) {
              if (i + abs(a - d) + abs(b - c) <= n) {
                ans3++;
              }
            }
          } else if (c > b) {
            if (i - abs(b - c) > 0 && i - abs(b - c) <= n) {
              if (i - abs(b - c) + abs(a - d) > 0 &&
                  i - abs(b - c) + abs(a - d) <= n) {
                ans3++;
              }
            }
          }
        }
      } else if (a - d < 0) {
        if (i - abs(a - d) > 0 && i - abs(a - d) <= n) {
          if (b > c) {
            if (i + abs(b - c) > 0 && i + abs(b - c) <= n) {
              if (i - abs(a - d) + abs(b - c) <= n &&
                  i - abs(a - d) + abs(b - c) > 0) {
                ans3++;
              }
            }
          } else if (c > b) {
            if (i - abs(b - c) > 0 && i - abs(b - c) <= n) {
              if (i - abs(b - c) - abs(a - d) > 0 &&
                  i - abs(b - c) - abs(a - d) <= n) {
                ans3++;
              }
            }
          }
        }
      }
    }
    ans = ans3 * n;
    cout << ans << "\n";
  }
  return 0;
}

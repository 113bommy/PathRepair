#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, m, a, b, i, j, k, x = 0, y = 0, ans = 0;
  cin >> n >> a >> b;
  if (a >= b) {
    m = n;
    while (x < 4 || y < 2) {
      while (n >= a && x < 4) {
        if (n % a == 0) {
          while (x < 4 && n >= a) {
            x++;
            n = n - a;
          }
          break;
        }
        n = n - a;
        x++;
        if (n % b == 0 && y < 2) break;
      }
      while (n >= b && y < 2) {
        n = n - b;
        y++;
      }
      while (n >= a && x < 4) {
        n = n - a;
        x++;
      }
      n = m;
      ans++;
    }
  } else {
    m = n;
    while (x < 4 || y < 2) {
      while (y < 2 && n >= b) {
        if (n % b == 0) {
          while (n >= b && y < 2) {
            n = n - b;
            y++;
          }
          break;
        }
        n = n - b;
        y++;
        if (n % a == 0 && x < 4) {
          break;
        }
      }
      while (x < 4 && n >= a) {
        n = n - a;
        x++;
      }
      while (y < 2 && n >= b) {
        n = n - b;
        y++;
      }
      n = m;
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}

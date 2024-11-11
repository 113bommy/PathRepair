#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m;
  cin >> n >> m;
  int count = 0;
  if (n == 2 * m)
    cout << n;
  else if (2 * n == m)
    cout << m;
  else {
    while (m > 0 && n > 0) {
      if (n > m && n > 0 && m > 0) {
        while (n > m && n > 0 && m > 0) {
          if (n == 1 && m == 1) break;
          count++;
          n -= 2;
          m -= 1;
        }
      } else if (m >= n && n > 0 && m > 0) {
        while (m >= n && n > 0 && m > 0) {
          if (n == 1 && m == 1) break;
          count++;
          m -= 2;
          n -= 1;
        }
      }
      if (n == 1 && m == 1) break;
    }
    cout << count;
  }
}
int main() {
  ios::sync_with_stdio;
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}

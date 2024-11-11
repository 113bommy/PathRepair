#include <bits/stdc++.h>
using namespace std;
int t;
int n, m, k;
int main(void) {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  cin >> t;
  for (int test_case = 0; test_case < t; test_case++) {
    cin >> n >> m >> k;
    bool flag = false;
    if (n % 2 == 0 && m % 2 == 0) {
      if (k % 2 == 0) {
        flag = true;
      }
    } else if (n % 2 == 0) {
      if (m == 1) {
        if (k == 0) flag = true;
      } else {
        if (k % 2 == 0) {
          if (2 * k <= (m - 1) * n) {
            flag = true;
          }
        }
      }
    } else {
      if (n == 1) {
        if (2 * k == m * n) {
          flag = true;
        }
      } else {
        if (k >= m / 2) {
          k -= m / 2;
          if (k % 2 == 0) {
            flag = true;
          }
        }
      }
    }
    if (flag) {
      cout << "YES"
           << "\n";
    } else {
      cout << "NO"
           << "\n";
    }
  }
}

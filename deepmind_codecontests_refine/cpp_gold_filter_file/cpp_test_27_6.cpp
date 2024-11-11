#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n, m, k;
    cin >> n >> m >> k;
    k--;
    int d = 0;
    bool flag = false;
    long long num = n * (n - 1) / 2;
    if (n > 1) {
      if (m == num) {
        d = 1;
      } else {
        d = 2;
      }
    }
    if (m >= n - 1 && m <= num) {
      if (d < k) {
        flag = true;
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
  return 0;
}

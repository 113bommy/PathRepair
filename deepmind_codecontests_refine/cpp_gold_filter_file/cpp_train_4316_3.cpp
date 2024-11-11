#include <bits/stdc++.h>
using namespace std;
long long t, n, k, d1, d2;
int main() {
  cin >> t;
  for (__typeof(t) i = 0; i < (t); i++) {
    cin >> n >> k >> d1 >> d2;
    if (n % 3 != 0) {
      cout << "no\n";
      continue;
    }
    bool flag = false;
    for (int i = -1; i <= 1; i++) {
      for (int j = -1; j <= 1; j++) {
        if (i == 0 || j == 0) continue;
        long long td1 = d1 * i, td2 = d2 * j;
        long long num = k - td1 + td2;
        if (num % 3 != 0) continue;
        long long n2 = num / 3;
        if (0 <= n2 && n2 <= k) {
          long long n1 = td1 + n2, n3 = n2 - td2;
          if (n1 >= 0 && n1 <= k && n3 >= 0 && n3 <= k && n1 <= n / 3 &&
              n2 <= n / 3 && n3 <= n / 3) {
            flag = 1;
            break;
          }
        }
      }
      if (flag) break;
    }
    if (flag) {
      cout << "yes\n";
    } else
      cout << "no\n";
  }
}

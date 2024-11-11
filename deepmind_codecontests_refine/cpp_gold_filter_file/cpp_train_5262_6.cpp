#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    long long n, k = 0, i, j = 0;
    cin >> n;
    {
      if (n % 400 == 0 || (n % 100 != 0 && n % 4 == 0)) {
        for (i = n + 1;; i++) {
          if (i % 400 == 0 || (i % 100 != 0 && i % 4 == 0))
            k = k + 2;
          else
            k = k + 1;
          if (k % 7 == 0 && (i % 400 == 0 || (i % 100 != 0 && i % 4 == 0)))
            break;
        }
      } else {
        for (i = n + 1;; i++) {
          if (i % 400 == 0 || (i % 100 != 0 && i % 4 == 0))
            k = k + 2;
          else
            k = k + 1;
          if (k % 7 == 0 && !(i % 400 == 0 || (i % 100 != 0 && i % 4 == 0)))
            break;
        }
      }
    }
    cout << i;
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
long long a[200005];
int n, q;
long long k[200005];
int main() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) a[i] = a[i - 1] + a[i];
  for (int i = 1; i <= q; i++) cin >> k[i];
  long long num = 0;
  for (int i = 1; i <= q; i++) {
    num += k[i];
    int x = lower_bound(a + 1, a + n + 1, num) - a;
    if (x > n) {
      cout << n << endl;
      num = 0;
    } else if (x == 0) {
      cout << n << endl;
    } else {
      if (a[x] == num) {
        if (x == n) {
          num = 0;
          cout << n << endl;
        } else
          cout << n - x << endl;
      } else
        cout << n - x + 1 << endl;
    }
  }
}

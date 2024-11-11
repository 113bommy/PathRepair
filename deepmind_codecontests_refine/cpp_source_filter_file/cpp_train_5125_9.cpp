#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, t, d, n, s = 0, c = 0, k;
  cin >> t;
  while (t--) {
    c = 0;
    cin >> n;
    cin >> d;
    int a[n];
    for (i = 0; i < n; i++) cin >> a[i];
    i = 1;
    if (i < n) {
      while (true) {
        if (a[i] > 0) {
          a[i]--;
          if (d - i >= 0)
            d -= i;
          else
            break;
          c += i;
        } else {
          if (i < n)
            i++;
          else
            break;
        }
      }
    }
    cout << a[0] + c << endl;
  }
}

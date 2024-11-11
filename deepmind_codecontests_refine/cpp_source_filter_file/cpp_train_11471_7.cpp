#include <bits/stdc++.h>
using namespace std;
int t, n, i, fr[100005], x, maxim, minim, prod, ok, nr;
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(0);
  cin >> t;
  for (; t > 0; t--) {
    cin >> n;
    n = n * 4;
    for (i = 1; i <= 10000; i++) {
      fr[i] = 0;
    }
    maxim = 0;
    minim = 100000;
    for (i = 1; i <= n; i++) {
      cin >> x;
      fr[x]++;
      if (x > maxim) {
        maxim = x;
      }
      if (x < minim) {
        minim = x;
      }
    }
    prod = maxim * minim;
    ok = 1;
    for (i = 1; i <= 10000; i++) {
      if (fr[i] != 0) {
        if (prod % i != 0) {
          ok = 0;
          break;
        }
        nr = prod / i;
        if (nr == i) {
          if (fr[i] % 4 != 0) {
            ok = 0;
            break;
          }
        } else {
          if (fr[i] != fr[nr]) {
            ok = 0;
            break;
          }
          if (fr[i] % 2 != 0 || fr[nr] != 0) {
            ok = 0;
            break;
          }
        }
      }
    }
    if (ok == 1) {
      cout << "YES" << '\n';
    } else {
      cout << "NO" << '\n';
    }
  }
  return 0;
}

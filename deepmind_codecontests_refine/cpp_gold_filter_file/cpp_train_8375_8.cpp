#include <bits/stdc++.h>
using namespace std;
int num1[100], num2[100];
int main() {
  ios_base::sync_with_stdio(false);
  long long int l, r, d1, d2, tl, tr, n;
  cin >> n;
  while (n--) {
    cin >> l >> r;
    d1 = 0;
    tl = l;
    while (l) {
      num1[d1++] = l % 2;
      l /= 2;
    }
    d2 = 0;
    tr = r;
    while (r) {
      num2[d2++] = r % 2;
      r /= 2;
    }
    if (d1 != d2) {
      if ((1LL << d2) - 1 == tr)
        cout << ((1LL << d2) - 1) << endl;
      else
        cout << ((1LL << (d2 - 1)) - 1) << endl;
    } else {
      int i = d1 - 1;
      long long int ans = 0;
      while (num1[i] == num2[i] && i >= 0) {
        if (num1[i] == 1) ans = (ans | (1LL << i));
        i--;
      }
      while (num2[i] == 0) i--;
      int start = i;
      while (num2[start] == 1 && start >= 0) {
        start--;
      }
      if (start < 0) {
        while (i >= 0) {
          ans = (ans | (1LL << i));
          i--;
        }
        cout << ans << endl;
      } else {
        i--;
        while (i >= 0) {
          ans = (ans | (1LL << i));
          i--;
        }
        cout << ans << endl;
      }
    }
  }
  return 0;
}

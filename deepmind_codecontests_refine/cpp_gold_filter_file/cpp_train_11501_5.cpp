#include <bits/stdc++.h>
using namespace std;
int a[105], b[105];
int main() {
  int m, s, as = 0, l = 0, ad = 0;
  cin >> m >> s;
  if ((9 * m) < s || (s == 0 && m > 1)) {
    cout << "-1"
         << " -1" << endl;
    return 0;
  }
  if (s <= 9) {
    for (int i = 0; i <= 9; i++) {
      if (0 + i == s) {
        ad = i;
        break;
      }
    }
    a[0] = ad;
    b[0] = ad;
    for (int i = 1; i < m; i++) {
      a[i] = 0;
      b[i] = 0;
    }
    reverse(a, a + m);
    if (a[0] == 0) {
      for (int i = 1; i < m; i++) {
        if (a[i] > 0) {
          a[i] -= 1;
          a[0] = 1;
          break;
        }
      }
    }
    for (int i = 0; i < m; i++) {
      cout << a[i];
    }
    cout << " ";
    for (int i = 0; i < m; i++) {
      cout << b[i];
    }
    cout << endl;
    return 0;
  } else if (s > 9) {
    for (int i = 0; i >= 0; i++) {
      if ((l * 9) + 9 < s) {
        l++;
      } else {
        for (int j = 0; j <= 9; j++) {
          if ((l * 9) + j == s) {
            as = j;
            break;
          }
        }
        break;
      }
    }
    for (int i = 0; i <= l; i++) {
      if (i == l) {
        a[i] = as;
        b[i] = as;
      } else {
        a[i] = 9;
        b[i] = 9;
      }
    }
    for (int i = l + 1; i < m; i++) {
      a[i] = 0;
      b[i] = 0;
    }
    reverse(a, a + m);
    if (a[0] == 0) {
      for (int i = 1; i > 0; i++) {
        if (a[i] > 0) {
          a[i] -= 1;
          a[0] = 1;
          break;
        }
      }
    }
    if (a[m - 1] < 9 && a[m - 2] > 0) {
      a[m - 1] += 1;
      a[m - 2] -= 1;
    }
    for (int i = 0; i < m; i++) {
      cout << a[i];
    }
    cout << " ";
    for (int i = 0; i < m; i++) {
      cout << b[i];
    }
    cout << endl;
    return 0;
  }
  return 0;
}

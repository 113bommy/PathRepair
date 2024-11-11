#include <bits/stdc++.h>
using namespace std;
int main() {
  int l, r, a, result = 0, c = 0;
  cin >> l >> r >> a;
  if (l == r) {
    result = l + r;
    if (a % 2 == 0) result = result + a;
    if (a % 2 != 0 && a != 0) result = result + (a - 1);
  }
  if (l > r) {
    r = r + a;
    if (r < l) {
      for (int i = 1; r < l;) {
        l = l - i;
      }
    }
    if (r > l) {
      a = r - l;
      for (int i = 1; r > l;) {
        r = r - i;
      }
      if (a % 2 == 0 && a != 0) result = result + a;
      if (a % 2 != 0 && a != 0) result = result + (a - 1);
    }
    result = result + r + l;
  }
  if (l < r) {
    l = l + a;
    if (r < l) {
      a = l - a;
      for (int i = 1; r < l;) {
        l = l - i;
      }
      if (a % 2 == 0 && a != 0) result = result + a;
      if (a % 2 != 0 && a != 0) result = result + (a - 1);
    }
    if (r > l) {
      for (int i = 1; r > l;) {
        r = r - i;
      }
    }
    result = result + r + l;
  }
  if (result < 0)
    cout << 0;
  else
    cout << result;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int y, a[5];
int k(int e) {
  if (e < 5) return a[e];
  if ((e & 1) == 1) return 0;
  if (!y) return 1;
  int r = 1, c;
  while (1) {
    if (e < 5) {
      c = a[e];
      break;
    }
    if ((e & 1) == 1) {
      c = 0;
      break;
    }
    e >>= 1;
    r ^= 1;
  }
  if (c == 1) {
    r ^= 1;
  }
  return r + 1;
}
int main() {
  int q, w, e, r, t, ans = 0, c;
  cin >> q >> y;
  y %= 2;
  a[0] = 0;
  a[1] = 1;
  if (y) {
    a[2] = 0;
    a[3] = 1;
    a[4] = 2;
  } else {
    a[2] = 2;
    a[3] = 0;
    a[4] = 1;
  }
  for (w = 0; w < q; w++) {
    scanf("%d", &e);
    ans ^= k(e);
  }
  if (ans)
    cout << "Kevin";
  else
    cout << "Nicky";
  return 0;
}

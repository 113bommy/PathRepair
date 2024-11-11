#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0;
  bool f = 0;
  char c = getchar();
  for (; !isdigit(c); c = getchar()) f ^= !(c - 45);
  for (; isdigit(c); c = getchar()) x = x * 10 + c - 48;
  if (f) x = -x;
  return x;
}
int n, m, c;
int a[15005];
int main() {
  cin >> n >> m >> c;
  int tl = 0, tr = n + 1;
  while (true) {
    int x;
    cin >> x;
    if (x <= (c >> 1)) {
      int l = 1;
      while (true) {
        if (a[l] == 0 || a[l] > x) {
          a[l] = x;
          cout << l << "\n";
          fflush(stdout);
          break;
        } else
          l++;
      }
      tl = l;
    } else {
      int r = n;
      while (true) {
        if (a[r] == 0 || a[r] < x) {
          a[r] = x;
          cout << r << "\n";
          fflush(stdout);
          break;
        } else
          r--;
      }
      tr = r;
    }
    if (tl == tr - 1) exit(0);
  }
}

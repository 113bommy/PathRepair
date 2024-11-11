#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, w = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') w = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + c - '0', c = getchar();
  return x * w;
}
struct A {
  int l, r, ans;
} a[1005];
int n;
int main() {
  for (int q = read(); q; --q) {
    n = read();
    for (int i = 1; i <= n; ++i) a[i].l = read(), a[i].r = read();
    int t = 1;
    for (int i = 1; i <= n; ++i) {
      if (t < a[i].l) t = a[i].l;
      if (a[i].r < t)
        printf("0 ");
      else
        printf("%d ", t);
      ++t;
    }
    cout << endl;
  }
  return 0;
}

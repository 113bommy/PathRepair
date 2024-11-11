#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
int n, m;
int a[1000005];
void add(int pos, int v) {
  for (int i = pos; i <= n; i += (i & -i)) a[pos] += v;
}
int ask(int pos) {
  int res = 0;
  for (int i = pos; i; i -= (i & -i)) res += a[pos];
  return res;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    add(x, 1);
  }
  for (int i = 1; i <= m; i++) {
    int x;
    scanf("%d", &x);
    if (x < 0) {
      x = -x;
      int l = 1, r = n + 5, mid = l;
      while (l + 1 < r) {
        mid = (l + r) >> 1;
        if (ask(mid) >= x)
          r = mid;
        else
          l = mid;
      }
      if (ask(l) >= x)
        add(l, -1);
      else
        add(r, -1);
    } else
      add(x, 1);
  }
  bool f = false;
  for (int i = 1; i <= n; i++) {
    if (a[i]) {
      f = true;
      printf("%d\n", i);
      break;
    }
  }
  if (!f) puts("0");
  return 0;
}

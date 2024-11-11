#include <bits/stdc++.h>
using namespace std;
struct ac {
  int l, r;
} a[200001];
int cmp(ac x, ac y) {
  if (x.r == y.r) {
    return x.l < y.l;
  } else
    return x.r < y.r;
}
int main() {
  int n, r1 = -1, r2 = -1;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i].l >> a[i].r;
  sort(a + 1, a + n + 1, cmp);
  for (int i = 1; i <= n; i++) {
    if (r1 < a[i].l)
      r1 = a[i].r;
    else if (r2 < a[i].l)
      r2 = a[i].r;
    else {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES";
  return 0;
}

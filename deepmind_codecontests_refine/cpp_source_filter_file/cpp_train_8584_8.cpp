#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
struct node {
  int d[60];
  node operator+(const node& t) const {
    node tmp;
    for (int i = 0; i < 60; i++)
      tmp.d[i] = this->d[i] + t.d[i + (this->d[i]) % 60];
    return tmp;
  }
} a[maxn * 4];
void up(int k, int l, int r, int p, int val) {
  if (l == r) {
    for (int i = 0; i < 60; i++) {
      if (i % val == 0)
        a[k].d[i] = 2;
      else
        a[k].d[i] = 1;
    }
  } else {
    int m = (l + r) / 2;
    if (p <= m)
      up(k << 1, l, m, p, val);
    else if (p > m)
      up(k << 1 | 1, m + 1, r, p, val);
    a[k] = a[k << 1] + a[k << 1 | 1];
  }
}
node qu(int k, int l, int r, int L, int R) {
  if (l >= L && r <= R) return a[k];
  int m = (l + r) / 2;
  if (R <= m)
    return qu(k << 1, l, m, L, R);
  else if (L > m)
    return qu(k << 1 | 1, m + 1, r, L, R);
  return qu(k << 1, l, m, L, R) + qu(k << 1 | 1, m + 1, r, L, R);
}
int main() {
  int n, q;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    up(1, 1, n, i, x);
  }
  cin >> q;
  while (q--) {
    char aa;
    int bb, cc;
    cin >> aa >> bb >> cc;
    if (aa == 'A') {
      printf("%d\n", qu(1, 1, n, bb, cc - 1).d[0]);
    } else {
      up(1, 1, n, bb, cc);
    }
  }
  return 0;
}

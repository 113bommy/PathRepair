#include <bits/stdc++.h>
using namespace std;
int a[1000008], b[1000008], c[1000008], d[1000008], n, m;
int sum(int x) {
  int s = 0;
  while (x > 0) {
    s += a[x];
    x -= x & -x;
  }
  return s;
}
void add(int x, int q) {
  while (x <= n) {
    a[x] += q;
    x += x & -x;
  }
  return;
}
int main() {
  cin.tie(0);
  while (scanf("%d", &n) != EOF) {
    scanf("%d", &m);
    memset(a, 0, sizeof(a));
    memset(c, 0, sizeof(c));
    int k = 0;
    for (int i(0); i <= (m - 1); ++i) {
      scanf("%d", &b[i]);
    }
    int ttt = n;
    while (ttt--) {
      int x;
      scanf("%d", &x);
      if (x < 0) {
        int zs = 0;
        for (int i(0); i <= (m - 1); ++i) {
          int l = 0, r = k;
          if (sum(k) < b[i]) break;
          while (l + 1 < r) {
            int mid = (l + r) >> 1;
            if (sum(mid) >= b[i]) {
              r = mid;
            } else {
              l = mid;
            }
          }
          d[zs++] = r;
        }
        for (int i(0); i <= (zs - 1); ++i) {
          add(d[i], -1);
        }
      } else {
        c[++k] = x;
        add(k, 1);
      }
    }
    int zz = 0;
    for (int i(1); i <= (k); ++i) {
      if (sum(i) - sum(i - 1) == 1) {
        cout << c[i];
        zz++;
      }
    }
    if (!zz) {
      cout << "Poor stack!";
    }
    cout << endl;
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int n, t;
int m[200010];
int cn[1000010] = {0};
struct _tz {
  int l, r;
  int pos;
} tz[200010];
long long res[200010];
long long rs;
bool cmp(_tz a, _tz b) {
  int w = (int)a.l / sqrt(n);
  int z = (int)b.l / sqrt(n);
  if (w == z) {
    return a.r < b.r;
  }
  return w < z;
}
int main() {
  int i, j;
  scanf("%d%d", &n, &t);
  for (i = 1; i <= n; ++i) {
    scanf("%d", &m[i]);
  }
  for (i = 0; i < t; ++i) {
    scanf("%d%d", &tz[i].l, &tz[i].r);
    tz[i].pos = i;
  }
  sort(tz, tz + t, cmp);
  rs = 0;
  for (i = tz[0].l; i <= tz[0].r; ++i) {
    rs +=
        m[i] * (((cn[m[i]] + 1) * (cn[m[i]] + 1)) - ((cn[m[i]]) * (cn[m[i]])));
    ++cn[m[i]];
  }
  res[tz[0].pos] = rs;
  for (i = 1; i < t; ++i) {
    if (tz[i].l > tz[i - 1].l) {
      for (j = tz[i - 1].l; j < tz[i].l; ++j) {
        rs += m[j] *
              (((cn[m[j]] - 1) * (cn[m[j]] - 1)) - ((cn[m[j]]) * (cn[m[j]])));
        --cn[m[j]];
      }
    } else {
      for (j = tz[i].l; j < tz[i - 1].l; ++j) {
        rs += m[j] *
              (((cn[m[j]] + 1) * (cn[m[j]] + 1)) - ((cn[m[j]]) * (cn[m[j]])));
        ++cn[m[j]];
      }
    }
    if (tz[i].r > tz[i - 1].r) {
      for (j = tz[i - 1].r + 1; j <= tz[i].r; ++j) {
        rs += m[j] *
              (((cn[m[j]] + 1) * (cn[m[j]] + 1)) - ((cn[m[j]]) * (cn[m[j]])));
        ++cn[m[j]];
      }
    } else {
      for (j = tz[i].r + 1; j <= tz[i - 1].r; ++j) {
        rs += m[j] *
              (((cn[m[j]] - 1) * (cn[m[j]] - 1)) - ((cn[m[j]]) * (cn[m[j]])));
        --cn[m[j]];
      }
    }
    res[tz[i].pos] = rs;
  }
  for (i = 0; i < t; ++i) {
    cout << res[i] << '\n';
  }
}

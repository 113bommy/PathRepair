#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, a[N], tmp_a[N], tmp_tot;
int tot, px[N], py[N], pz[N], bc[1 << 20 | 10];
inline void Do(int x, int y, int z) {
  a[x] ^= 1;
  a[y] ^= 1;
  a[z] ^= 1;
  assert(x < y && y < z);
  assert(y - x == z - y);
  ++tot;
  px[tot] = x;
  py[tot] = y;
  pz[tot] = z;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", a + i);
  int l = 1, r = n;
  while (l <= r && !a[l]) ++l;
  while (l <= r && !a[r]) --r;
  while (r - l + 1 >= 7) {
    if (a[l + 1] == 1 && a[l + 2] == 1) {
      Do(l, l + 1, l + 2);
    } else if (a[l + 1] == 0 && a[l + 2] == 1) {
      Do(l, l + 2, l + 4);
    } else if (a[l + 1] == 0 && a[l + 2] == 0) {
      Do(l, l + 3, l + 6);
    } else if (a[l + 1] == 1 && a[l + 2] == 0) {
      if (a[r - 1] == 1 && a[r - 2] == 1) {
        Do(r - 2, r - 1, r);
      } else if (a[r - 1] == 0 && a[r - 2] == 1) {
        Do(r - 4, r - 2, r);
      } else if (a[r - 1] == 0 && a[r - 2] == 0) {
        Do(r - 6, r - 3, r);
      } else if (a[r - 1] == 1 && a[r - 2] == 0) {
        if ((r + l) & 1) {
          Do(l, (l + r - 1) / 2, r - 1);
          Do(l + 1, (l + r + 1) / 2, r);
        } else {
          Do(l, (l + r) / 2, r);
          Do(l + 1, (l + r) / 2, r - 1);
        }
      }
    }
    while (l <= r && !a[l]) ++l;
    while (l <= r && !a[r]) --r;
  }
  l = max(l - 6, 1);
  r = min(r + 6, n);
  for (int i = l; i <= r; ++i) tmp_a[i] = a[i];
  int tmp_tot = tot;
  for (int i = 0; i < 1 << (r - l - 1); ++i) {
    bc[i] = bc[i >> 1] + (i & 1);
    for (int j = 0; l + j + 2 <= r; ++j)
      if (i >> j & 1) {
        a[l + j] ^= 1;
        a[l + j + 1] ^= 1;
        a[l + j + 2] ^= 1;
      }
    for (int j = l; j + 6 <= r; ++j)
      if (a[j]) {
        Do(j, j + 3, j + 6);
      }
    int ans = 0;
    for (int j = l; j <= r; ++j) ans |= a[j];
    if (!ans) {
      if (tot + bc[i] <= n / 3 + 12) {
        for (int j = 0; l + j + 2 <= r; ++j)
          if (i >> j & 1) Do(l + j, l + j + 1, l + j + 2);
        puts("YES");
        printf("%d\n", tot + bc[i]);
        for (int i = 1; i <= tot; ++i)
          printf("%d %d %d\n", px[i], py[i], pz[i]);
        return 0;
      }
    }
    for (int i = l; i <= r; ++i) a[i] = tmp_a[i];
    tot = tmp_tot;
  }
  puts("NO");
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int n, m;
int ans[200010];
int yuan[200010];
struct caozuo {
  int r, mark, id;
  friend bool operator<(const caozuo &a, const caozuo &b) { return a.r > b.r; }
} c[200010];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%d", &yuan[i]);
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &c[i].mark, &c[i].r);
    c[i].id = i;
  }
  sort(c, c + m);
  int ps, l, r;
  for (int i = 0; i < m; i++) {
    if (i != 0 && c[i].id < c[ps].id) continue;
    if (!i) {
      sort(yuan, yuan + c[i].r);
      for (int j = c[i].r; j < n; j++) {
        ans[j] = yuan[j];
      }
      l = 0;
      r = c[i].r - 1;
    } else {
      if (c[ps].mark == 1) {
        for (int j = c[ps].r - 1; j >= c[i].r; j--) {
          ans[j] = yuan[r--];
        }
      } else {
        for (int j = c[ps].r - 1; j >= c[i].r; j--) {
          ans[j] = yuan[l++];
        }
      }
    }
    ps = i;
  }
  if (l < r) {
    if (c[ps].mark == 1) {
      for (int j = c[ps].r - 1; j >= 0; j--) {
        ans[j] = yuan[r--];
      }
    } else {
      for (int j = c[ps].r - 1; j >= 0; j--) {
        ans[j] = yuan[l++];
      }
    }
  }
  for (int i = 0; i < n; i++) {
    printf("%d ", ans[i]);
  }
  return 0;
}

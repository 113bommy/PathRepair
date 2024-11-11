#include <bits/stdc++.h>
using namespace std;
const int g = 10.0, eps = 1e-9;
const int N = 200000 + 10, maxn = 100000 + 10, inf = 0x3f3f3f3f;
struct TV {
  int l, r;
  int id;
  bool operator<(const TV& rhs) const {
    if (l != rhs.l) return l < rhs.l;
    return r > rhs.r;
  }
} p[N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &p[i].l, &p[i].r);
    p[i].id = i + 1;
  }
  sort(p, p + n);
  for (int i = 0; i < n - 1; i++) {
    if (p[i].r >= p[i + 1].r) {
      printf("%d\n", p[i + 1].id);
      return 0;
    } else if (i + 2 < n && p[i + 1].l <= p[i].r + 1 &&
               p[i + 2].l <= p[i].r + 1) {
      if (p[i + 1].r < p[i + 2].r)
        printf("%d\n", p[i + 1].id);
      else
        printf("%d\n", p[i + 2].id);
      return 0;
    }
  }
  puts("-1");
  return 0;
}

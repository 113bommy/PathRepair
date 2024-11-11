#include <bits/stdc++.h>
using namespace std;
int n, l, b, f;
int c[150005], a[150005], p[150005];
inline int lowbit(int x) { return x & (-x); }
void add(int i, int d) {
  for (; i <= n; i += lowbit(i)) c[i] += d;
}
int sum(int i) {
  int s = 0;
  for (; i; i -= lowbit(i)) s += c[i];
  return s;
}
inline bool back(int x) {
  if (x == 0) return 1;
  if (!sum(x)) return 1;
  if (x >= b && sum(x) - sum(x - b) == 0) return 1;
  return 0;
}
inline bool front(int x) {
  if (x == n + 1) return 1;
  if (!(sum(n) - sum(x - 1))) return 1;
  if (x + f - 1 <= n && sum(x + f - 1) - sum(x - 1) == 0) return 1;
  return 0;
}
int main() {
  scanf("%d %d %d", &l, &b, &f);
  n = l + 1;
  memset(c, 0, sizeof(c));
  int m;
  scanf("%d", &m);
  for (int i = 1; i <= m; ++i) {
    int k, x;
    scanf("%d %d", &k, &x);
    if (k == 1) {
      a[i] = x;
      p[i] = 0;
      for (int j = 1; j + x - 1 <= n; ++j)
        if (!(sum(j + x - 1) - sum(j - 1)) && back(j - 1) && front(j + x)) {
          p[i] = j;
          for (int u = j; u < j + x; ++u) add(u, 1);
          break;
        }
      printf("%d\n", p[i] - 1);
    } else {
      for (int j = p[x]; j < p[x] + a[x]; ++j) add(j, -1);
      p[x] = 0;
    }
  }
  return 0;
}

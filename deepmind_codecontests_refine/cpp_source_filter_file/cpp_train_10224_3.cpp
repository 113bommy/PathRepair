#include <bits/stdc++.h>
using namespace std;
int n, q;
int a[300005], p[300005], k[300005], x[300005], p2[300005], ans[300005];
int b[300005];
void add(int i) {
  for (; i <= n; i += i & -i) ++b[i];
}
int bs(int x) {
  --x;
  int i = 0;
  for (int j = 18; j >= 0; --j)
    if ((i | 1 << j) <= n && b[i | 1 << j] <= x) x -= b[i |= 1 << j];
  return i + 1;
}
int main() {
  int tests = 1;
  while (tests--) {
    scanf("%d", &n);
    for (int i = 1; i <= (n); ++i) scanf("%d", a + i), p[i] = i;
    sort(p + 1, p + n + 1,
         [](int i, int j) { return a[i] == a[j] ? i < j : a[i] > a[j]; });
    scanf("%d", &q);
    for (int i = 1; i <= (q); ++i) scanf("%d%d", &k[i], &x[i]), p2[i] = i;
    sort(p2 + 1, p2 + n + 1, [](int i, int j) { return k[i] < k[j]; });
    int lst = 0;
    for (int id = 1; id <= (q); ++id) {
      int i = p2[id];
      int k = ::k[i], x = ::x[i];
      while (lst < k) add(p[++lst]);
      ans[i] = a[bs(x)];
    }
    for (int i = 1; i <= (q); ++i) printf("%d\n", ans[i]);
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
template <class T>
void smax(T &x, T y) {
  if (y > x) x = y;
}
template <class T>
void smin(T &x, T y) {
  if (y < x) x = y;
}
const int maxn = 1e6 + 17, inf = 1717171717;
int n, t, a[maxn], st[maxn], sz, mCna[maxn], MCna;
void clearuntil(int in) {
  if (!sz) return;
  for (int i = sz - 1, x = st[i]; ~i; i--, x = st[i], sz--)
    if (a[x] == in && !MCna)
      return;
    else if (MCna && a[x] == a[mCna[MCna - 1]])
      a[mCna[MCna - 1]] *= -1, MCna--;
    else
      mCna[MCna++] = x;
}
int main() {
  scanf("%d", &n);
  for_each(a, a + n, [](int &x) { scanf("%d", &x); });
  scanf("%d", &t);
  while (t--) {
    int x;
    scanf("%d", &x), a[--x] *= -1;
  }
  for (int i = 0, x = a[0]; i < n; i++, x = a[i])
    if (x < 0) {
      clearuntil(-x);
      if (sz && a[st[sz - 1]] == -x)
        sz--;
      else
        return printf("NO\n"), 0;
    } else
      st[sz++] = i;
  clearuntil(-1717171717);
  if (MCna) return printf("NO\n"), 0;
  printf("YES\n");
  for_each(a, a + n, [](int &x) { printf("%d ", x); });
  putchar('\n');
  return 0;
}

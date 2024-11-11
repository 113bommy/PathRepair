#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 6;
int n, m, b, Ti;
int a[N], f[N], T[N];
int ask(int x) {
  int r(0);
  for (; x; x -= x & (-x)) r = max(r, T[x]);
  return r;
}
void upd(int x, int y) {
  for (; x <= b; x += x & (-x)) T[x] = max(T[x], y);
}
void work() {
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  memset(T, 0, sizeof(N)), memset(f, 0, sizeof(N));
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      int t = ask(a[j] - 1) + 1;
      if (t > f[a[j]]) f[a[j]] = t, upd(a[j], t);
    }
  }
  printf("%d\n", ask(b));
}
int main() {
  scanf("%d%d%d%d", &Ti, &n, &b, &m);
  if (m > b) m = b;
  if (m > n) m = n;
  for (; Ti; Ti--) work();
  return 0;
}

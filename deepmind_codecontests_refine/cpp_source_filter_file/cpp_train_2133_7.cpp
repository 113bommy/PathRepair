#include <bits/stdc++.h>
using namespace std;
void reloc() {
  freopen("cards.in", "r", stdin);
  return;
}
int a, b, l, t, m, n;
void read() {
  scanf("%d%d%d", &a, &b, &n);
  return;
}
long long h(int pos) { return 1ll * a + 1ll * (pos - 1) * b; }
long long sum(int x1, int x2) {
  return 1ll * (2ll * a + (x1 + x2 - 2) * b) * (x2 - x1 + 1) / 2;
}
int ri, mid, le;
bool ok(int pos) {
  int len = pos - l + 1;
  long long ans = 0;
  if (h(pos) > t) return 0;
  ans = sum(l, pos);
  if (ans <= t * m) return 1;
  return 0;
}
void work() {
  for (int i = 1; i <= n; i++) {
    scanf("%d%d%d", &l, &t, &m);
    if (t < h(l)) {
      printf("-1\n");
      continue;
    }
    ri = 1000009;
    le = l;
    while (le != ri) {
      mid = ((le + ri) >> 1) + 1;
      if (ok(mid)) {
        le = mid;
      } else
        ri = mid - 1;
    }
    printf("%d\n", le);
  }
  return;
}
int main() {
  read();
  work();
  return 0;
}

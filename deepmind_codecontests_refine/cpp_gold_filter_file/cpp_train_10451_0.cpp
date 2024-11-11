#include <bits/stdc++.h>
using namespace std;
struct bg {
  int l, r, p;
} a[2005];
int N, s[2005], p[2005], q[2005];
bool b[2005], c[2005][2005];
void init() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) scanf("%d%d", &a[i].l, &a[i].r), a[i].p = i;
  sort(a + 1, a + N + 1, [](bg x, bg y) { return x.r < y.r; });
  for (int i = 1; i <= N; i++)
    for (int j = i + 1; j <= N; j++)
      if (a[j].l <= a[i].r) c[i][j] = c[j][i] = 1;
}
bool check(int x) {
  for (int i = 1; i <= N; i++) p[i] = N, b[i] = 1;
  for (int i = 1, j = 1; i <= N; i++) {
    q[i] = a[j].p, b[j] = 0, p[j] = i;
    for (int k = 1; k <= N; k++)
      if (c[j][k]) p[k] = min(p[k], i + x);
    memset(s, 0, sizeof(s));
    for (int k = 1; k <= N; k++) s[p[k]]++;
    for (int k = 1; k <= N; k++)
      if ((s[k] += s[k - 1]) > k) return 0;
    for (int k = i + 1; k <= N; k++)
      if (s[k] == k) {
        for (j = 1; !b[j] || p[j] > k; j++)
          ;
        break;
      }
  }
  return 1;
}
void doit() {
  int l = 0, r = N;
  for (; l <= r;) {
    int m = (l + r) >> 1;
    if (check(m))
      r = m - 1;
    else
      l = m + 1;
  }
  check(l);
  for (int i = 1; i <= N; i++) printf("%d%c", q[i], i == N ? '\n' : ' ');
}
int main() {
  init();
  doit();
  return 0;
}

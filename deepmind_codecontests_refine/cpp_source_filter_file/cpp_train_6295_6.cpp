#include <bits/stdc++.h>
using namespace std;
int n, i;
int p[200011];
int aib[200011];
int ord[2][200011];
int ans[200011];
int zrs(int x) { return (x & (x - 1)) ^ x; }
void add(int x, int v) {
  while (x <= n) {
    aib[x] += v;
    x += zrs(x);
  }
}
int sum(int x) {
  int ans = 0;
  while (x > 0) {
    ans += aib[x];
    x -= zrs(x);
  }
  return ans;
}
int cb(int x) {
  int ans = 0;
  for (int step = (1 << 16); step > 0; step >>= 1)
    if (ans + step <= n)
      if (aib[ans + step] <= x) x -= aib[ans += step];
  return ans;
}
void get_order(int n, int *p, int *ans) {
  int i;
  for (i = 1; i <= n; i++) aib[i] = zrs(i);
  memset(ans, 0, sizeof(ans));
  for (i = 1; i <= n; i++) {
    ans[n - i] = sum(p[i] - 1);
    add(p[i], -1);
  }
}
void get_perm(int n, int *ord, int *ans) {
  int i, cnt, pos;
  for (i = 1; i <= n; i++) aib[i] = zrs(i);
  memset(ans, 0, sizeof(ans));
  for (i = 1; i <= n; i++) {
    cnt = ord[n - i] + 1;
    pos = cb(cnt - 1) + 1;
    ans[i] = pos;
    add(pos, -1);
  }
}
int main() {
  scanf("%d", &n);
  for (i = 1; i <= n; i++) scanf("%d", &p[i]), p[i]++;
  get_order(n, p, ord[0]);
  for (i = 1; i <= n; i++) scanf("%d", &p[i]), p[i]++;
  get_order(n, p, ord[1]);
  for (i = 1; i <= n; i++) ord[0][i] += ord[1][i];
  for (i = 1; i <= n; i++) {
    ord[0][i + 1] += ord[0][i] / (i + 1);
    ord[0][i] %= i + 1;
  }
  get_perm(n, ord[0], ans);
  for (i = 1; i <= n; i++) printf("%d ", ans[i] - 1);
  return 0;
}

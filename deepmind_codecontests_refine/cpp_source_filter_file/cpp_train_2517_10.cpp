#include <bits/stdc++.h>
struct xxx {
  int x, id;
} a[201000], b[201000];
int A[201000], B[201000];
long long c[201000], d[201000];
long long s[201000];
int Ans[201000];
int m, n;
bool cmp(xxx a, xxx b) { return a.x < b.x; }
void solve(int *a, int *b, long long *c) {
  memset(s, 0, sizeof(s));
  for (int i = 1; i <= n; i++) {
    int v = std::lower_bound(a + 1, a + n + 1, b[i]) - a - 1;
    s[i] -= b[i];
    if (i + n - v <= n) s[i + n - v] += 2 * b[i];
  }
  for (int i = n; i >= 1; i--) {
    int v = std::upper_bound(b + 1, b + n + 1, a[i]) - b;
    s[n - i + 1] += a[i];
    if (n - i + v <= n) s[n - i + v] -= 2 * a[i];
  }
  for (int i = 1; i <= n; i++) s[i] += s[i - 1], c[i] += s[i];
}
int main() {
  scanf("%d%d", &m, &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i].x), a[i].id = i;
  for (int i = 1; i <= n; i++) scanf("%d", &b[i].x), b[i].id = i;
  std::sort(a + 1, a + n + 1, cmp);
  std::sort(b + 1, b + n + 1, cmp);
  for (int i = 1; i <= n; i++) A[i] = a[i].x;
  for (int i = 1; i <= n; i++) B[i] = b[i].x;
  solve(A, B, c);
  for (int i = 1; i <= n; i++) B[i] = a[i].x;
  for (int i = 1; i <= n; i++) A[i] = b[i].x;
  solve(A, B, d);
  long long S = 0;
  for (int i = 1; i <= n; i++) {
    S += a[i].x + m - b[n - i + 1].x;
    d[i] = std::min(d[i], S);
  }
  S = 0;
  for (int i = 1; i <= n; i++) {
    S += b[i].x + m - a[n - i + 1].x;
    c[i] = std::min(c[i], S);
  }
  long long ans = 1e18;
  int id = 0;
  for (int i = 1; i <= n; i++)
    if (c[i] + d[n - i] <= ans) ans = c[i] + d[n - i], id = i;
  printf("%lld\n", ans);
  for (int i = 1; i <= id; i++) Ans[a[n - id + i].id] = b[i].id;
  for (int i = id + 1; i <= n; i++) Ans[a[i - id].id] = b[i].id;
  for (int i = 1; i <= n; i++) printf("%d ", Ans[i]);
}

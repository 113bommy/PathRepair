#include <bits/stdc++.h>
using namespace std;
const int N = 800;
int a[N];
long long b[N];
int n, m;
int solve(long long x) {
  priority_queue<int> q;
  int ret = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] < 0) q.push(-a[i]);
    x += a[i];
    if (x < 0) {
      x += q.top();
      q.pop();
      ret++;
    }
  }
  return ret;
}
long long check(int v) {
  long long l = -1, r = 1e15, mid;
  while (l + 1 < r) {
    mid = (l + r) >> 1;
    int t = solve(mid);
    if (t <= v)
      r = mid;
    else
      l = mid;
  }
  return r;
}
int main() {
  scanf("%d%d", &n, &m);
  int cnt = 0;
  for (int i = 1; i <= n; i++) scanf("%d", a + i), cnt += a[i] < 0;
  for (int i = 0; i <= cnt; i++) b[i] = check(cnt - i);
  while (m--) {
    long long x;
    scanf("%I64d", &x);
    int ans = upper_bound(b, b + cnt + 1, x) - b - 1;
    printf("%d\n", cnt - ans);
  }
  return 0;
}

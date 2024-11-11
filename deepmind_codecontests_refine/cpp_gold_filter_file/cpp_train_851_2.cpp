#include <bits/stdc++.h>
using namespace std;
void _in(long long *a, ...) {
  va_list arg_ptr;
  scanf("%I64d", a);
  long long *temp;
  va_start(arg_ptr, a);
  temp = va_arg(arg_ptr, long long *);
  while (temp) {
    scanf("%I64d", temp);
    temp = va_arg(arg_ptr, long long *);
  }
  va_end(arg_ptr);
}
void _in(int *a, ...) {
  va_list arg_ptr;
  scanf("%d", a);
  int *temp;
  va_start(arg_ptr, a);
  temp = va_arg(arg_ptr, int *);
  while (temp) {
    scanf("%d", temp);
    temp = va_arg(arg_ptr, int *);
  }
  va_end(arg_ptr);
}
void __init() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
const int N = 2e5 + 100;
int a[N], s[N], n, d[N][3], ans, pre[N][3], anss[N], pos[N];
bool cut[N];
struct note {
  int i, v;
};
note t[N];
bool cmp(const note &a, const note &b) { return a.v < b.v; }
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> t[i].v, t[i].i = i;
  sort(t + 1, t + n + 1, cmp);
  for (int i = 1; i <= n; i++) a[i] = t[i].v;
  for (int i = 1; i <= n; i++) pos[t[i].i] = i;
  ans = a[n] - a[1];
  for (int i = 1; i <= n - 1; i++) s[i] = a[i + 1] - a[i];
  for (int i = 3; i <= n - 3; i++) {
    d[i][0] = d[i - 1][2] + s[i];
    pre[i][0] = i - 1 + 2 * n;
    d[i][1] = max(d[i - 1][1], d[i - 1][2]);
    d[i][1] = max(d[i - 1][0], d[i][1]);
    if (d[i][1] == d[i - 1][1])
      pre[i][1] = n + i - 1;
    else if (d[i][1] == d[i - 1][2])
      pre[i][1] = 2 * n + i - 1;
    else if (d[i][1] == d[i - 1][0])
      pre[i][1] = i - 1;
    d[i][2] = max(d[i - 1][2], d[i - 1][1]);
    if (d[i][2] == d[i - 1][2])
      pre[i][2] = i - 1 + 2 * n;
    else if (d[i][2] == d[i - 1][1])
      pre[i][2] = i - 1 + n;
  }
  int md = max(d[n - 3][0], d[n - 3][1]);
  md = max(md, d[n - 3][2]);
  ans -= md;
  cout << ans << ' ';
  int p, cn = 0;
  if (md == d[n - 3][0]) {
    p = n - 3;
  } else if (md == d[n - 3][1]) {
    p = n - 3 + n;
  } else {
    p = n - 3 + 2 * n;
  }
  while (p % n >= 3) {
    int i1 = p % n, i2 = p / n;
    if (!i2) cut[i1] = 1, cn++;
    p = pre[i1][i2];
  }
  cout << cn + 1 << '\n';
  p = 1;
  for (int i = 1; i <= n; i++) {
    anss[i] = p;
    if (cut[i]) p++;
  }
  for (int i = 1; i <= n; i++) cout << anss[pos[i]] << ' ';
  return 0;
}

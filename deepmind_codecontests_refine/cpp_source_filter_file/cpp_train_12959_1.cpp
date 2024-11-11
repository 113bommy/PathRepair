#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
const int N = 500010;
int n, m, a[N], b[N], cnt[N], c[N];
long long ans;
bool f;
void update_ans(long long val) {
  if (ans == -1)
    ans = val;
  else if (ans != val)
    f = false;
}
void check(int s, int d) {
  for (int i = 1; i <= n; i++) cnt[i] = 0;
  for (int i = 1; i <= m; i++) cnt[b[i]]++;
  int st = s, dt = d;
  if (!cnt[s]) return;
  cnt[s]--;
  long long res = 0;
  for (int i = 1; i < m; i++) {
    if ((s == n && d == 1) || (s == 1 && d == -1)) d *= -1;
    long long s1 = s + d;
    if (!cnt[s1]) return;
    cnt[s1]--;
    if (s1 > s)
      res += a[s1] - a[s];
    else
      res += a[s] - a[s1];
    s = s1;
  }
  update_ans(res);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) scanf("%d", &b[i]);
  ans = -1;
  f = true;
  check(1, 1);
  check(n, -1);
  check(2, -1);
  check(2, 1);
  check(n - 1, -1);
  check(n - 1, 1);
  for (int i = 2; i <= n; i++)
    if (a[i] - a[i - 1] != a[2] - a[1]) {
      check(i, 1);
      check(i, -1);
      check(i - 1, 1);
      check(i - 1, -1);
      break;
    }
  for (int i = 1; i <= n; i++) c[b[i]]++;
  for (int i = 3; i < n - 1; i++)
    if (c[i] != c[i - 1] || c[i] != c[i + 1]) {
      check(i, -1);
      check(i, 1);
    }
  if (!f) ans = -1;
  cout << ans;
  return 0;
}

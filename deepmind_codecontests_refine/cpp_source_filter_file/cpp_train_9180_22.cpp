#include <bits/stdc++.h>
using namespace std;
const int N = 300005;
int n, pre[N], stk[N], ptr, l[N], r[N], idx, f[N], cnt[N];
char ss[N], s[N];
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> (ss + 1);
  int sum = 0, cur = 0, mn = INT_MAX;
  for (int i = 1; i <= n; i++) {
    sum += (ss[i] == '(' ? 1 : -1);
    if (sum < mn) mn = sum, cur = i;
  }
  if (sum) {
    cout << "0\n1 1" << endl;
    return 0;
  }
  for (int i = cur + 1; i <= n; i++) s[i - cur] = ss[i];
  for (int i = 1; i <= cur; i++) s[n - cur + i] = ss[i];
  for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + (s[i] == '(' ? 1 : -1);
  for (int i = 1; i <= n; i++)
    if (s[i] == '(')
      stk[++ptr] = ++idx, l[idx] = i;
    else
      r[stk[ptr]] = i, f[stk[ptr]] = stk[ptr - 1], ++cnt[stk[--ptr]];
  int ans = cnt[0], p1 = 1, p2 = 1;
  for (int i = 1; i <= idx; i++)
    if (cnt[i] + 1 > ans && !f[i])
      ans = cnt[i] + 1, p1 = l[i], p2 = r[i];
    else if (cnt[i] + cnt[0] > ans && f[i] && !f[f[i]])
      ans = cnt[i] + cnt[0], p1 = l[i], p2 = r[i];
  p1 = (p1 + cur - 1) % n + 1;
  p2 = (p2 + cur - 1) % n + 1;
  cout << ans << endl << p1 << ' ' << p2 << endl;
  return 0;
}

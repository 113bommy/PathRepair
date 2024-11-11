#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5;
int n;
int a[maxn], b[maxn];
int lst, cur;
int x, m, y, k;
long long ans = 0;
int st[maxn][20], l0g2[maxn];
int query(int l, int r) {
  int tmp = l0g2[r - l + 1];
  return max(st[l][tmp], st[r - (1 << tmp) + 1][tmp]);
}
long long calc(int num) {
  if (y * k < x)
    return (long long)num * (long long)y;
  else
    return (long long)num / (long long)k * (long long)x +
           (long long)(num % k) * (long long)y;
}
int main() {
  std::ios::sync_with_stdio(false);
  l0g2[0] = 1;
  for (int i = 1; i < (maxn); i++) l0g2[i] = l0g2[i / 2] + 1;
  cin >> n >> m;
  cin >> x >> k >> y;
  for (int i = 1; i < (n + 1); i++) cin >> a[i];
  for (int i = 1; i < (m + 1); i++) cin >> b[i];
  for (int i = n; i > 0; i--) {
    st[i][0] = a[i];
    for (int j = 1; i + (1 << j) - 1 <= n; j++)
      st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
  }
  int j = 1;
  cur = 1, lst = 1;
  while (cur <= n) {
    if (a[cur] == b[j]) {
      if (lst < cur && query(lst, cur - 1) > a[lst - 1] &&
          query(lst, cur - 1) > a[cur]) {
        if (cur - lst < k) {
          cout << -1;
          return 0;
        }
        ans += (long long)x + calc(cur - lst - k);
      } else
        ans += calc(cur - lst);
      cur++, j++;
      lst = cur;
    } else
      cur++;
  }
  if (j <= m) {
    cout << -1;
    return 0;
  }
  if (query(lst, n) > a[lst - 1] && query(lst, cur - 1) > a[cur]) {
    if (cur - lst < k) {
      cout << -1;
      return 0;
    }
    ans += (long long)x + calc(cur - lst - k);
  } else
    ans += calc(cur - lst);
  cout << ans << endl;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int a[maxn], b[maxn];
int main() {
  int c1, c2, c3, c4;
  scanf("%d%d%d%d", &c1, &c2, &c3, &c4);
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= m; i++) {
    scanf("%d", &b[i]);
  }
  int ans = c4;
  ans = min(ans, c3 * 2);
  ans = min(ans, c2 * (n + m));
  int res = 0;
  for (int i = 1; i <= n; i++) {
    res += min(c1 * a[i], c2);
  }
  int cnt = min(res, c3);
  res = 0;
  for (int i = 1; i <= m; i++) {
    res += min(c1 * b[i], c2);
  }
  cnt += min(res, c3);
  ans = min(ans, cnt);
  cout << ans << endl;
  return 0;
}

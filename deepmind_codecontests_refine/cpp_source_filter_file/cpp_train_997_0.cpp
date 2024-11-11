#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int n, m, sum;
long long ans, pre[4][N];
vector<int> a[4];
long long check(int mid, int have) {
  int one = have - 2 * mid;
  if (one > a[1].size()) one = a[1].size();
  return pre[3][mid] + pre[1][one];
}
long long del(int have) {
  int l = 0, r = a[3].size();
  r = min(r, have / 3);
  while (l < r - 1) {
    int mid = l + r >> 1, mid2 = r + mid >> 1;
    if (check(mid, have) > check(mid2, have))
      r = mid2;
    else
      l = mid;
  }
  return max(max(check(l, have), check(r, have)),
             max(check(0, have), check(have / 3, have)));
  ;
}
int main() {
  scanf("%d%d", &n, &m);
  a[1].push_back(0), a[2].push_back(0), a[3].push_back(0);
  for (int i = 1; i <= n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    a[x].push_back(y);
    sum += x, ans += y;
  }
  if (m >= sum) {
    printf("%lld\n", ans);
    return 0;
  }
  ans = 0;
  sort(a[1].begin(), a[1].end(), greater<int>());
  sort(a[2].begin(), a[2].end(), greater<int>());
  sort(a[3].begin(), a[3].end(), greater<int>());
  for (int k = 1; k <= 3; k++)
    for (int i = 0; i <= a[k].size() - 1; i++)
      pre[k][i + 1] = pre[k][i] + a[k][i];
  for (int i = 0; i <= a[2].size(); i++)
    if (i * 2 <= m) ans = max(ans, del(m - i * 2) + pre[2][i]);
  printf("%lld\n", ans);
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int tmp, n, d, k;
vector<pair<int, int>> ans;
void tst(int r, int t) {
  if (tmp > n || t <= 0) return;
  int tk;
  if (r <= d)
    tk = k - 2;
  else
    tk = k - 1;
  for (int i = 0; i < tk; ++i) {
    if (tmp > n) return;
    ans.push_back({r, ++tmp});
    tst(tmp, t - 1);
  }
}
int main() {
  scanf("%d%d%d", &n, &d, &k);
  if (d == 1 || k == 1) {
    if (n == 2 && k >= 1 && d == 1) {
      printf("YES\n1 2\n");
    } else
      printf("NO\n");
    return 0;
  }
  if (n < d + 1) {
    printf("NO\n");
    return 0;
  }
  tmp = d + 1;
  for (int i = 1; i <= d; ++i) {
    ans.push_back({i, i + 1});
  }
  for (int i = 2; i <= d; ++i) {
    if (tmp > n) break;
    tst(i, min(i - 1, d + 1 - i));
  }
  if (tmp < n)
    printf("NO\n");
  else {
    printf("YES\n");
    for (int i = 0; i < n - 1; ++i)
      printf("%d %d\n", ans[i].first, ans[i].second);
  }
  return 0;
}

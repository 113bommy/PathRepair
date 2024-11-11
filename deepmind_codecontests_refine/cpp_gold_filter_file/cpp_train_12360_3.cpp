#include <bits/stdc++.h>
using namespace std;
int n, L, W;
vector<int> pos, neg;
int main() {
  scanf("%d%d%d", &n, &L, &W);
  for (int i = 1; i <= n; i++) {
    int x, v;
    scanf("%d%d", &x, &v);
    if (v > 0)
      pos.emplace_back(x);
    else
      neg.emplace_back(x);
  }
  if (W == 1) {
    int pos_cnt = 0, neg_cnt = 0;
    for (int x : pos)
      if (x < 0) pos_cnt++;
    for (int x : neg)
      if (x > -L) neg_cnt++;
    printf("%lld\n", 1LL * pos_cnt * neg_cnt);
    return 0;
  }
  sort(pos.begin(), pos.end());
  long long fans = 0;
  for (int x : neg) {
    int l = 0, r = lower_bound(pos.begin(), pos.end(), x) - pos.begin(), mid,
        ans = -1;
    if (r == pos.size() || pos[r] > x) r--;
    while (l <= r) {
      mid = (l + r) >> 1;
      if (pos[mid] + x + L - 1LL * W * (x - pos[mid] + L) < 0 &&
          pos[mid] + x + L + 1LL * W * (x - pos[mid] + L) > 0)
        l = mid + 1, ans = mid;
      else
        r = mid - 1;
    }
    fans += ans + 1;
  }
  printf("%lld\n", fans);
  return 0;
}

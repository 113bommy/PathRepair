#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<pair<int, int>> vc;
void fun(int l, int r, int x) {
  if (r <= m) {
    int _l = (l ^ n) & (~x);
    int _r = _l + x;
    vc.push_back({_l, _r});
  } else {
    int mid = (l + r) >> 1;
    fun(l, mid, x >> 1);
    if (m > mid) fun(mid + 1, r, x >> 1);
  }
}
void solve() {
  scanf("%d %d", &n, &m);
  vc.clear();
  int x = 1;
  while (x <= m) x <<= 1;
  fun(0, x - 1, x - 1);
  sort(vc.begin(), vc.end());
  int ans = 0;
  for (auto &it : vc) {
    if (it.first != ans) {
      break;
    } else {
      ans = it.second + 1;
    }
  }
  printf("%d\n", ans);
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) solve();
  return 0;
}

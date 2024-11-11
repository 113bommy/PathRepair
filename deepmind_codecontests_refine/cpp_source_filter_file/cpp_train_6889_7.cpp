#include <bits/stdc++.h>
using namespace std;
const int N = 1e6, inf = 1e18, mod = 1e9 + 7, eps = -1e8;
int tc, n, m, w, q, a, b, c, d, i, j, k, l, sum, cnt, tmp, flag, mn;
long long mx, ar[N], ans[N], bit[N];
deque<int> dq;
void update(int id, long long val) {
  while (id <= w) {
    bit[id] += val;
    id += id & -id;
  }
}
long long query(int id) {
  long long ret = 0;
  while (id > 0) {
    ret += bit[id];
    id -= id & -id;
  }
  return ret;
}
int32_t main() {
  scanf("%d%d", &n, &w);
  for (j = 1; j <= n; j++) {
    scanf("%d", &l);
    mx = 0;
    for (i = 1; i <= l; i++) dq.push_back(0);
    for (i = 1; i <= l; i++) {
      scanf("%lld", &ar[i]);
      mx = max(mx, ar[i]);
      while (!dq.empty() && ar[i] > ar[dq.back()]) dq.pop_back();
      dq.push_back(i);
      while (dq.front() == i - w + l - 1) dq.pop_front();
      ans[i] += ar[dq.front()];
    }
    dq.clear();
    for (i = 1; i <= l; i++) dq.push_back(l + 1);
    ar[l + 1] = 0;
    for (i = l, k = w; i > 0 && k > l; i--, k--) {
      while (!dq.empty() && ar[i] > ar[dq.back()]) dq.pop_back();
      dq.push_back(i);
      while (dq.front() == i + w + l - 1) dq.pop_front();
      ans[k] += ar[dq.front()];
    }
    if (w - l + 1 > l + 1) {
      update(l + 1, mx);
      update(w - l + 1, -mx);
    }
    dq.clear();
  }
  for (i = 1; i <= w; i++) printf("%lld ", ans[i] + query(i));
}

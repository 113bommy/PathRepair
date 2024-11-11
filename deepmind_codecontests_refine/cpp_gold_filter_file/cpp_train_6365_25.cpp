#include <bits/stdc++.h>
using namespace std;
struct pii {
  int64_t first, second, id;
  bool operator<(const pii &b) const { return first > b.first; }
};
int64_t in[300005], dd[300005];
int64_t n, k;
int64_t chk(int64_t w) {
  priority_queue<pii> pq;
  for (int64_t i = 0; i < n; i++) pq.push({in[i] / dd[i], in[i], i});
  for (int64_t i = 0; i < k; i++) {
    auto x = pq.top();
    pq.pop();
    if (i > x.first) return false;
    pq.push({(x.second + w) / dd[x.id], x.second + w, x.id});
  }
  return true;
}
int32_t main() {
  {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
  };
  cin >> n >> k;
  for (int64_t i = 0; i < n; i++) cin >> in[i];
  for (int64_t i = 0; i < n; i++) cin >> dd[i];
  int64_t lim = 3e12;
  int64_t l = 0, r = lim;
  while (l != r) {
    int64_t m = l + r >> 1;
    if (chk(m))
      r = m;
    else
      l = m + 1;
  }
  if (l == lim)
    cout << -1 << '\n';
  else
    cout << l << '\n';
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const long long maxn = 3e4 + 55;
struct node {
  long long x, gx;
  bool operator<(const node& rhs) const {
    if (gx != rhs.gx)
      return gx < rhs.gx;
    else
      return x < gx;
  }
} g[maxn];
long long get(long long p, long long q, long long x) {
  return 2 * p * x % (2 * q);
}
long long dis(long long p, long long q, long long x) {
  return abs(get(p, q, x) - q);
}
void update(long long& ans, long long cur, long long p, long long q) {
  if (ans == -1)
    ans = cur;
  else if (dis(p, q, cur) < dis(p, q, ans))
    ans = cur;
  else if (dis(p, q, cur) == dis(p, q, ans))
    ans = min(ans, cur);
}
int main() {
  long long n;
  cin >> n;
  while (n--) {
    long long a, b, p, q;
    cin >> a >> b >> p >> q;
    long long k = 3e4;
    map<int, int> mp;
    for (long long i = k - 1; i >= 0; i--) mp[get(p, q, i)] = i;
    long long sz = 0;
    for (auto x : mp) g[sz++] = node{x.second, x.first};
    long long bg = a, ans = -1;
    while (bg + k - 1 <= b) {
      long long base = get(p, q, bg), idx;
      if (base <= q)
        idx = lower_bound(g, g + sz, node{-1, q - base}) - g;
      else
        idx = lower_bound(g, g + sz, node{-1, 3 * q - base}) - g;
      if (idx < sz) update(ans, bg + g[idx].x, p, q);
      if (idx - 1 >= 0) update(ans, bg + g[idx - 1].x, p, q);
      bg += k;
    }
    if (bg <= b) {
      for (long long i = bg; i <= b; i++) update(ans, i, p, q);
    }
    cout << ans << endl;
  }
}

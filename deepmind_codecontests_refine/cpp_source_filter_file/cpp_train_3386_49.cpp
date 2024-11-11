#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
struct ConvexHull {
  vector<pair<long long, long long> > v;
  void clear() { v.clear(); }
  bool check(pair<long long, long long> a, pair<long long, long long> b,
             pair<long long, long long> c) {
    return (a.second - c.second) * (a.first - b.first) <=
           (b.second - a.second) * (c.first - a.first);
  }
  void add(long long a, long long b) {
    v.push_back({a, b});
    while (v.size() >= 2 &&
           check(v[v.size() - 2], v[v.size() - 3], v[v.size() - 1]))
      swap(v[v.size() - 2], v[v.size() - 1]), v.pop_back();
  }
  long long f(int i, long long first) {
    return v[i].first * first + v[i].second;
  }
  long long query(long long first) {
    int st = -1, dr = v.size() - 1, mid;
    while (st + 1 < dr) {
      mid = (st + dr) >> 1;
      if (f(mid, first) <= f(mid + 1, first))
        st = mid;
      else
        dr = mid;
    }
    return f(dr, first);
  }
};
int n;
long long ans;
long long v[200005];
long long s[200005];
ConvexHull ch;
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> v[i], s[i] = s[i - 1] + v[i];
  ch.clear();
  for (int i = n - 1; i >= 1; i--) {
    ch.add(-i - 1, -s[i + 1]);
    ans = max(ans, ch.query(-v[i]) + s[i] - v[i] * i);
  }
  ch.clear();
  for (int i = 2; i <= n; i++) {
    ch.add(i - 1, -s[i - 2]);
    ans = max(ans, ch.query(v[i]) + s[i - 1] - v[i] * i);
  }
  for (int i = 1; i <= n; i++) ans += v[i] * i;
  cout << ans;
  return 0;
}

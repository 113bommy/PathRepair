#include <bits/stdc++.h>
using namespace std;
const int Nmax = 1e6 + 5;
map<int, int> mp;
int x[Nmax], y[Nmax], c[Nmax];
long long curr;
vector<pair<int, int>> start[Nmax];
int where[Nmax];
int n, l, best;
class SegTree {
  long long a[Nmax << 2];
  long long lazy[Nmax << 2];
  int pos[Nmax << 2];
  inline void cobor(int node) {
    if (!lazy[node]) return;
    lazy[(node << 1)] += lazy[node];
    lazy[((node << 1) | 1)] += lazy[node];
    a[(node << 1)] += lazy[node];
    a[((node << 1) | 1)] += lazy[node];
    lazy[node] = 0;
  }
  inline void refr(int node) {
    if (a[(node << 1)] > a[((node << 1) | 1)])
      a[node] = a[(node << 1)], pos[node] = pos[(node << 1)];
    else
      a[node] = a[((node << 1) | 1)], pos[node] = pos[((node << 1) | 1)];
  }

 public:
  void build(int node, int st, int dr) {
    lazy[node] = 0;
    if (st == dr) {
      pos[node] = st;
      a[node] = -where[st];
      return;
    }
    build((node << 1), st, ((st + dr) >> 1));
    build(((node << 1) | 1), ((st + dr) >> 1) + 1, dr);
    refr(node);
  }
  void update(int node, int st, int dr, int L, int R, int add) {
    if (L <= st && dr <= R) {
      lazy[node] += add;
      a[node] += add;
      return;
    }
    cobor(node);
    if (L <= ((st + dr) >> 1))
      update((node << 1), st, ((st + dr) >> 1), L, R, add);
    if (((st + dr) >> 1) < R)
      update(((node << 1) | 1), ((st + dr) >> 1) + 1, dr, L, R, add);
    refr(node);
  }
  void query(int node, int st, int dr, int L, int R) {
    if (L <= st && dr <= R) {
      if (curr < a[node]) curr = a[node], best = pos[node];
      return;
    }
    cobor(node);
    if (L <= ((st + dr) >> 1)) query((node << 1), st, ((st + dr) >> 1), L, R);
    if (((st + dr) >> 1) < R)
      query(((node << 1) | 1), ((st + dr) >> 1) + 1, dr, L, R);
  }
} aint;
void normalize() {
  int i;
  for (i = 1; i <= n; ++i) {
    mp[x[i]] = 1;
    mp[y[i]] = 1;
  }
  l = 0;
  for (auto &it : mp) it.second = ++l, where[l] = it.first;
  for (i = 1; i <= n; ++i) x[i] = mp[x[i]], y[i] = mp[y[i]];
}
void solve() {
  int i;
  for (i = 1; i <= n; ++i) {
    if (x[i] > y[i]) swap(x[i], y[i]);
    start[x[i]].push_back({y[i], c[i]});
  }
  aint.build(1, 1, l);
  int X = 2e9, Y = 2e9;
  long long ans = 0;
  for (i = l; i; --i) {
    for (auto it : start[i]) aint.update(1, 1, l, it.first, l, it.second);
    curr = LLONG_MIN;
    best = -1;
    aint.query(1, 1, l, i, l);
    curr += where[i];
    if (curr > ans) ans = curr, X = where[i], Y = where[best];
  }
  cout << ans << '\n';
  cout << X << ' ' << X << ' ' << Y << ' ' << Y << '\n';
}
int main() {
  cin.tie(0);
  cin.sync_with_stdio(false);
  cin >> n;
  int i;
  for (i = 1; i <= n; ++i) cin >> x[i] >> y[i] >> c[i];
  normalize();
  solve();
  return 0;
}

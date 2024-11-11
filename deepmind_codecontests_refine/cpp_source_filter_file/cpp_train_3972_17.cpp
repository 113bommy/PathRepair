#include <bits/stdc++.h>
using namespace std;
const int N = 6e5 + 3;
int n;
map<pair<int, int>, int> mp;
map<pair<int, int>, int>::iterator it;
struct hh {
  int fa[N], s1[N], s2[N];
  int find(int x) { return x ^ fa[x] ? fa[x] = find(fa[x]) : x; }
  void set(int n) {
    for (int i = 1; i <= 2 * n; ++i) fa[i] = i;
    for (int i = 1; i <= n; ++i) s1[i] = 1, s2[i + n] = 1;
  }
} f;
struct kk {
  int x, y;
};
struct segment {
  vector<kk> a[N << 2];
  void mdy(int k, int l, int r, int ll, int rr, kk u) {
    if (l >= ll && r <= rr) {
      a[k].push_back(u);
      return;
    }
    int mid = l + r >> 1;
    if (ll <= mid) mdy(k << 1, l, mid, ll, rr, u);
    if (rr > mid) mdy(k << 1 | 1, mid + 1, r, ll, rr, u);
  }
  void solve(int k, int l, int r, long long ans) {
    vector<kk> s;
    for (int i = 0; i < a[k].size(); ++i) {
      int x = f.find(a[k][i].x), y = f.find(a[k][i].y);
      if (x ^ y) {
        ans -= 1ll * f.s1[x] * f.s2[x] + 1ll * f.s1[y] * f.s2[y];
        if (f.s1[x] + f.s2[x] > f.s1[y] + f.s2[y]) swap(x, y);
        f.fa[x] = y, f.s1[y] += f.s1[x], f.s2[y] += f.s2[x];
        ans += 1ll * f.s1[y] * f.s2[y], s.push_back((kk){x, y});
      }
    }
    int mid = l + r >> 1;
    if (l == r)
      printf("%lld ", ans);
    else
      solve(k << 1, l, mid, ans), solve(k << 1 | 1, mid + 1, r, ans);
    for (int i = s.size() - 1; ~i; --i) {
      int x = s[i].x, y = s[i].y;
      ans -= 1ll * f.s1[y] * f.s2[y];
      f.fa[x] = x, f.s1[y] -= f.s1[x], f.s2[y] -= f.s2[x];
      ans += 1ll * f.s1[x] * f.s2[x] + 1ll * f.s1[y] * f.s2[y];
    }
  }
} T;
inline int in() {
  char c;
  int f = 1;
  while ((c = getchar()) < '0' || c > '9')
    if (c == '-') f = -1;
  int x = c - '0';
  while ((c = getchar()) >= '0' && c <= '9') x = x * 10 + c - '0';
  return x * f;
}
int main() {
  int x, y;
  n = in();
  for (int i = 1; i <= n; ++i) {
    x = in(), y = in() + 3e5;
    if (!mp[make_pair(x, y)])
      mp[make_pair(x, y)] = i;
    else
      T.mdy(1, 1, n, mp[make_pair(x, y)], i - 1, (kk){x, y}),
          mp[make_pair(x, y)] = 0;
  }
  for (it = mp.begin(); it != mp.end(); ++it)
    if (it->second)
      T.mdy(1, 1, n, it->second, n, (kk){it->first.first, it->first.second});
  f.set(3e5);
  T.solve(1, 1, n, 0);
  return 0;
}

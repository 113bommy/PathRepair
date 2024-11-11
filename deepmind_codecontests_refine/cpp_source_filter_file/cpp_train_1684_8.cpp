#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 14, sq = 700;
const long double inf = 1e99, eps = 1e-14;
int n, x[maxn], y[maxn], bl[maxn], ans[maxn], cur, cnt[maxn];
vector<int> a[maxn];
struct cmp {
  bool operator()(pair<long double, long double> a,
                  pair<long double, long double> b) const {
    if (abs(a.first - b.first) < eps) return a.second < b.second - eps;
    return a.first < b.first - eps;
  }
};
map<pair<long double, long double>, int, cmp> mp;
struct Q {
  int l, r, id;
} qu[maxn];
int dir(int x, int y) {
  long double len = sqrtl((long long)x * x + (long long)y * y);
  pair<long double, long double> vec = {x / len, y / len};
  static int sz = 0;
  if (!mp.count(vec)) mp[vec] = sz++;
  return mp[vec];
}
void upd(vector<int> &a, int v) {
  for (auto &x : a) {
    cur -= bool(cnt[x]);
    cnt[x] += v;
    cur += bool(cnt[x]);
  }
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) cin >> x[i] >> y[i];
    for (int j = 0; j < k; j++)
      a[i].push_back(dir(x[j] - x[(j + 1) % k], y[j] - y[(j + 1) % k]));
  }
  for (int i = 0, s = 0; i < n; i++) {
    s += a[i].size();
    if (i) bl[i] = bl[i - 1];
    if (s > sq) bl[i] = i, s = a[i].size();
  }
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> qu[i].l >> qu[i].r;
    qu[i].l--;
    qu[i].id = i;
  }
  sort(qu, qu + q,
       [](Q a, Q b) { return bl[a.l] != bl[b.l] ? a.l < b.l : a.r < b.r; });
  int l = 0, r = 0;
  for_each(qu, qu + q, [&](Q x) {
    auto [ql, qr, id] = x;
    while (l > ql) upd(a[--l], +1);
    while (r < qr) upd(a[r++], +1);
    while (l < ql) upd(a[l++], -1);
    while (r > qr) upd(a[--r], -1);
    ans[id] = cur;
  });
  for (int i = 0; i < q; i++) cout << ans[i] << '\n';
}

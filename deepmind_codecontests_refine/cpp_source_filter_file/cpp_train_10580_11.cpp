#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7, N = 110000, INF = 1e9 + 7;
long long seed;
int n, m, vmax;
set<tuple<int, int, long long>> s;
inline long long rnd() {
  long long ret = seed;
  seed = (seed * 7 + 13) % MOD;
  return ret;
}
inline set<tuple<int, int, long long>>::iterator cut(int x) {
  if (x == n + 1) return s.end();
  set<tuple<int, int, long long>>::iterator now =
      s.upper_bound(make_tuple(x, INF, 0));
  now--;
  int l, r;
  long long v;
  tie(l, r, v) = *now;
  if (l == x) return now;
  s.erase(make_tuple(l, r, v));
  s.emplace(l, x - 1, v);
  s.emplace(x, r, v);
  return s.find(make_tuple(x, r, v));
}
inline void type1(set<tuple<int, int, long long>>::iterator L,
                  set<tuple<int, int, long long>>::iterator R, int x) {
  set<tuple<int, int, long long>>::iterator it;
  int l, r;
  long long v;
  for (it = L; it != R;) {
    tie(l, r, v) = *it;
    it++;
    s.erase(make_tuple(l, r, v));
    s.emplace(l, r, v + x);
  }
}
inline void type2(set<tuple<int, int, long long>>::iterator L,
                  set<tuple<int, int, long long>>::iterator R, int x) {
  set<tuple<int, int, long long>>::iterator it = R;
  it--;
  int nl, nr;
  nl = get<0>(*L);
  nr = get<1>(*it);
  s.erase(L, R);
  s.emplace(nl, nr, x);
}
inline int cmp(const tuple<int, int, long long> a,
               const tuple<int, int, long long> b) {
  return get<2>(a) < get<2>(b);
}
inline long long type3(set<tuple<int, int, long long>>::iterator L,
                       set<tuple<int, int, long long>>::iterator R, int x) {
  set<tuple<int, int, long long>>::iterator it;
  vector<tuple<int, int, long long>> num;
  for (it = L; it != R; it++) num.push_back(*it);
  sort(num.begin(), num.end(), cmp);
  int sum = 0;
  for (int i = 0; i < num.size(); i++) {
    sum += get<1>(num[i]) - get<0>(num[i]) + 1;
    if (sum >= x) return get<2>(num[i]);
  }
}
long long pw(long long a, long long p, long long y) {
  if (p == 0) return 1;
  long long ret = pw(a, p / 2, y);
  if (p % 2) return ret * ret % y * a % y;
  return ret * ret % y;
}
inline int type4(set<tuple<int, int, long long>>::iterator L,
                 set<tuple<int, int, long long>>::iterator R, int x, int y) {
  set<tuple<int, int, long long>>::iterator it;
  long long ans = 0;
  for (it = L; it != R; it++) {
    int l, r;
    long long v;
    tie(l, r, v) = *it;
    ans = (ans + pw(v % y, x, y) * (r - l + 1)) % y;
  }
  return ans;
}
int main() {
  int i, o = 0;
  scanf("%d%d%lld%d", &n, &m, &seed, &vmax);
  for (i = 1; i <= n; i++) {
    s.emplace(i, i, rnd() % vmax + 1);
  }
  while (m--) {
    int op = rnd() % 4 + 1, l = rnd() % n + 1, r = rnd() % n + 1, x, y;
    long long ans;
    if (l > r) swap(l, r);
    if (op == 3)
      x = rnd() % (r - l + 1) + 1;
    else
      x = rnd() % vmax + 1;
    if (op == 4) y = rnd() % vmax + 1;
    set<tuple<int, int, long long>>::iterator R = cut(r + 1), L = cut(l), it;
    if (op == 1) type1(L, R, x);
    if (op == 2) type2(L, R, x);
    if (op == 3) printf("%lld\n", type3(L, R, x));
    if (op == 4) printf("%lld\n", type4(L, R, x, y));
  }
  return 0;
}

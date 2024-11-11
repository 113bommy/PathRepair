#include <bits/stdc++.h>
using namespace std;
int abc;
mt19937 rnd((unsigned long long)(new char));
int rd(int l, int r) {
  uniform_int_distribution<> ee(l, r);
  return ee(rnd);
}
const int mxn = 4e5 + 3, mod = 1e9 + 7;
pair<int, int> ee[mxn];
int n, v1[mxn], v2[mxn], px[mxn], m, v0[mxn], xp[mxn];
bool vs[mxn];
bool cmp1(int x, int y) { return v1[x] < v1[y]; }
struct arrrr {
  long long a[mxn];
  void add(int x, int y) {
    for (; x <= n; x += x & -x) a[x] += y;
  }
  long long ask(int x) {
    long long r = 0;
    for (; x; x &= x - 1) r += a[x], r %= mod;
    return r;
  }
} ar;
set<int> st;
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i)
    abc = scanf("%d%d", v1 + i, v2 + i), ee[i].first = v2[i],
    ee[i].second = v1[i];
  sort(ee + 1, ee + n + 1);
  cin >> m;
  for (int i = 1; i <= m; ++i) abc = scanf("%d", v0 + i), v0[i] = v1[v0[i]];
  for (int i = 1; i <= n; ++i)
    v1[i] = ee[i].second, v2[i] = ee[i].first, px[i] = i;
  sort(px + 1, px + n + 1, cmp1);
  for (int i = 1; i <= n; ++i) xp[v1[i]] = i;
  for (int i = 1; i <= m; ++i) st.insert(xp[v0[i]]);
  for (int t = 1; t <= n && st.size(); ++t)
    if (*--st.end() >= px[t]) st.erase(px[t]), vs[px[t]] = 1;
  long long ans = 0;
  for (int t = n; t; --t) {
    int x = px[t];
    long long v = ar.ask(x) + 1;
    if (vs[x]) ans += v;
    ar.add(x, v);
  }
  ans = (ans % mod + mod) % mod;
  printf("%lld\n", ans);
  return 0;
}

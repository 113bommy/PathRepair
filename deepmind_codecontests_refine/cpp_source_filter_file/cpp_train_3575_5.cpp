#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e5 + 5;
const long long INF = 1e18;
const long long MOD = 1e9 + 7;
int n, G, R, P, sz;
int seg[4 * maxN], l[maxN];
long long ps[maxN], dp[maxN], ans;
vector<int> vec;
void put(int p, int x, int id = 1, int s = 0, int e = sz) {
  seg[id] = min(seg[id], x);
  if (e - s <= 1) return;
  int md = (s + e) / 2;
  if (p < md)
    put(p, x, 2 * id, s, md);
  else
    put(p, x, 2 * id + 1, md, e);
  seg[id] = min(seg[2 * id], seg[2 * id + 1]);
  return;
}
long long fetch(int l, int r, int id = 1, int s = 0, int e = sz) {
  if (l <= s && e <= r) return seg[id];
  if (l >= e || s >= r) return MOD;
  int md = (s + e) / 2;
  return min(fetch(l, r, 2 * id, s, md), fetch(l, r, 2 * id + 1, md, e));
}
void ask(long long &res, int x) {
  long long y = 0;
  if (x < 0) {
    y = (P - ((-x) % P)) % P;
  } else
    y = (P + x % P) % P;
  res = MOD;
  int l = lower_bound(vec.begin(), vec.end(), G - y) - vec.begin();
  int r = lower_bound(vec.begin(), vec.end(), P - y) - vec.begin();
  if (l < r) res = min(res, fetch(l, r));
  l = lower_bound(vec.begin(), vec.end(), G + P - y) - vec.begin();
  if (l < sz) res = min(res, fetch(l, sz));
  if (res < MOD) {
    long long dis = ps[res] + x;
    res = dp[res] + 1ll * (dis / P + 1) * P;
  } else
    res = ps[n + 1] + x;
  return;
}
int main() {
  time_t START = clock();
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  scanf("%d%d%d", &n, &G, &R);
  P = G + R;
  for (int i = 0; i <= n; i++) {
    scanf("%d", l + i);
    ps[i + 1] = ps[i] + l[i];
    vec.push_back(ps[i + 1] % P);
  }
  sort(vec.begin(), vec.end());
  vec.resize(sz = unique(vec.begin(), vec.end()) - vec.begin());
  memset(seg, 63, sizeof seg);
  dp[n] = l[n];
  put(lower_bound(vec.begin(), vec.end(), ps[n] % P) - vec.begin(), n);
  for (int i = n - 1; i > -1; i--) {
    ask(dp[i], -ps[i]);
    if (i) put(lower_bound(vec.begin(), vec.end(), ps[i] % P) - vec.begin(), i);
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    int T;
    scanf("%d", &T);
    ask(ans, T);
    printf("%lld\n", ans);
  }
  time_t FINISH = clock();
  cerr << "Execution time: "
       << (long double)(FINISH - START) / CLOCKS_PER_SEC * 1000.0
       << " milliseconds.\n";
  return 0;
}

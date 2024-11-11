#include <bits/stdc++.h>
#pragma GCC optimize("O2,unroll-loops")
using namespace std;
const long double eps = 1e-7;
const int inf = 1000000010;
const long long INF = 10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 600010, SZ = 20 * MAXN;
int n, m, k, u, v, x, y, t, l, r;
int LL[MAXN], RR[MAXN], P[MAXN];
int seg[SZ], L[SZ], R[SZ], ts;
int root[MAXN];
vector<int> vec[MAXN], comp;
int Set(int id, int tl, int tr, int pos, int val) {
  if (pos < tl || tr <= pos) return id;
  int res = ++ts;
  if (tr - tl == 1) {
    seg[res] = max(seg[id], val);
    return res;
  }
  int mid = (tl + tr) >> 1;
  L[res] = Set(L[id], tl, mid, pos, val);
  R[res] = Set(R[id], mid, tr, pos, val);
  seg[res] = min(seg[L[res]], seg[R[res]]);
  return res;
}
int Get(int id, int tl, int tr, int l, int r) {
  if (r <= tl || tr <= l) return inf;
  if (l <= tl && tr <= r) return seg[id];
  int mid = (tl + tr) >> 1;
  return min(Get(L[id], tl, mid, l, r), Get(R[id], mid, tr, l, r));
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> k;
  for (int i = 1; i <= k; i++) {
    cin >> LL[i] >> RR[i] >> P[i];
    comp.push_back(LL[i]);
    comp.push_back(++RR[i]);
  }
  sort(comp.begin(), comp.end());
  comp.resize(unique(comp.begin(), comp.end()) - comp.begin());
  for (int i = 1; i <= k; i++) {
    LL[i] = lower_bound(comp.begin(), comp.end(), LL[i]) - comp.begin() + 1;
    RR[i] = lower_bound(comp.begin(), comp.end(), RR[i]) - comp.begin() + 1;
    vec[RR[i]].push_back(i);
  }
  for (int i = 1; i < MAXN; i++) {
    root[i] = root[i - 1];
    for (int id : vec[i]) root[i] = Set(root[i], 1, n + 1, P[id], LL[id]);
  }
  while (m--) {
    cin >> x >> y >> l >> r;
    r++;
    y++;
    l = lower_bound(comp.begin(), comp.end(), l) - comp.begin() + 1;
    r = lower_bound(comp.begin(), comp.end(), r) - comp.begin() + 1;
    int tmp = Get(root[r], 1, n + 1, x, y);
    if (tmp < l)
      cout << "no" << endl;
    else
      cout << "yes" << endl;
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
constexpr int N = 3e5 + 5;
constexpr int M = 1e9 + 7;
int rev[N], forw[N], pref[N], rpref[N], dop[N];
int mul(ll a, ll b) { return (a * b) % M; }
int sum(ll a, ll b) { return (a + b) % M; }
int bin_pow(int x, int deg) {
  int ans = 1;
  while (deg) {
    if (deg & 1) ans = mul(ans, x);
    deg >>= 1;
    x = mul(x, x);
  }
  return ans;
}
struct seg_tree {
  struct node {
    int sum;
    int val;
    int ans;
    int cnt;
    node *l, *r;
    node(int v = 0)
        : sum(mul(v, forw[0])),
          val(mul(v, rev[1])),
          cnt(1),
          ans(0),
          l(nullptr),
          r(nullptr){};
  };
  node buff[N * 30];
  int st = 0;
  using pn = node*;
  pn root = nullptr;
  pn newn(int v) {
    buff[st] = node(v);
    return &buff[st++];
  }
  int get_sum(pn v) { return v == nullptr ? 0 : v->sum; }
  int get_ans(pn v) { return v == nullptr ? 0 : v->ans; }
  int get_val(pn v) { return v == nullptr ? 0 : v->val; }
  int get_cnt(pn v) { return v == nullptr ? 0 : v->cnt; }
  pn comb(pn& v, pn l, pn r) {
    if (v == nullptr) v = newn(0);
    v->ans = sum(get_ans(l), get_ans(r));
    v->val = mul(get_val(r), rev[get_cnt(l)]);
    v->ans = sum(v->ans, mul(v->val, get_sum(l)));
    v->sum = sum(get_sum(l), mul(get_sum(r), forw[get_cnt(l)]));
    v->val = sum(get_val(l), v->val);
    v->cnt = get_cnt(l) + get_cnt(r);
    v->l = l;
    v->r = r;
    return v;
  }
  pn upd(int pos, int val, pn v, int l = 0, int r = M) {
    if (l + 1 == r) {
      if (v == nullptr)
        return newn(pos);
      else {
        v->cnt += val;
        if (v->cnt == 0)
          v->sum = v->val = v->ans = 0;
        else {
          v->sum = mul(pref[v->cnt - 1], pos);
          v->val = mul(rpref[v->cnt], pos);
          v->ans =
              mul(mul(pos, pos), mul(rev[1], sum(mul(v->cnt, rpref[v->cnt - 1]),
                                                 -dop[v->cnt - 1] + M)));
        }
        return v;
      }
    }
    int mid = l + ((r - l) >> 1);
    pn le = v == nullptr ? nullptr : v->l;
    pn ri = v == nullptr ? nullptr : v->r;
    if (mid > pos)
      le = upd(pos, val, le, l, mid);
    else
      ri = upd(pos, val, ri, mid, r);
    return comb(v, le, ri);
  }
  int get() { return get_ans(root); }
} tr;
int p[N], n, q, qi, qv;
void Solve() {
  forw[0] = pref[0] = 1;
  for (int i = 1; i < N; i++)
    forw[i] = mul(forw[i - 1], 2), pref[i] = sum(pref[i - 1], forw[i]);
  rev[N - 1] = bin_pow(forw[N - 1], M - 2);
  for (int i = N - 2; i >= 0; i--) rev[i] = mul(rev[i + 1], 2);
  for (int i = 1; i < N; i++) rpref[i] = sum(rpref[i - 1], rev[i]);
  for (int i = 1; i < N; i++) dop[i] = sum(dop[i - 1], mul(rev[i], i));
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> p[i], tr.root = tr.upd(p[i], 1, tr.root);
  cout << tr.get() << "\n";
  cin >> q;
  while (q--) {
    cin >> qi >> qv;
    tr.root = tr.upd(p[qi], -1, tr.root);
    p[qi] = qv;
    tr.root = tr.upd(p[qi], 1, tr.root);
    cout << tr.get() << "\n";
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  Solve();
  return 0;
}

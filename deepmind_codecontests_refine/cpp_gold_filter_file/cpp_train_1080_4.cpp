#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 5;
long long n, m, a[N], type, l, r;
inline long long myrand() { return rand() ^ (rand() << 16); }
struct item {
  item *l, *r;
  long long sum, ans;
  long long cnt, prior, key;
  item() {}
  item(long long _key) {
    key = _key;
    sum = _key;
    ans = 0;
    prior = myrand();
    cnt = 1;
    l = r = nullptr;
  }
};
typedef item *pitem;
pitem t;
inline long long cnt(pitem v) { return v ? v->cnt : 0; }
inline long long sum(pitem v) { return v ? v->sum : 0; }
inline long long ans(pitem v) { return v ? v->ans : 0; }
inline void upd_cnt(pitem &v) {
  if (v) {
    v->cnt = cnt(v->l) + 1 + cnt(v->r);
    v->sum = sum(v->l) + v->key + sum(v->r);
    v->ans =
        ans(v->l) + ans(v->r) + sum(v->r) * cnt(v->l) - sum(v->l) * cnt(v->r);
    v->ans += cnt(v->l) * v->key - sum(v->l) + sum(v->r) - cnt(v->r) * v->key;
  }
}
pitem aa(pitem l, pitem r) {
  if (!l || !r) {
    return l ? l : r;
  }
  if (l->prior > r->prior) {
    l->r = aa(l->r, r);
    upd_cnt(l);
    return l;
  } else {
    r->l = aa(l, r->l);
    upd_cnt(r);
    return r;
  }
}
void ab(pitem v, long long key, pitem &l, pitem &r) {
  if (!v) {
    l = r = nullptr;
    return;
  }
  if (key < v->key) {
    ab(v->l, key, l, v->l);
    r = v;
    upd_cnt(r);
  } else {
    ab(v->r, key, v->r, r);
    l = v;
    upd_cnt(l);
  }
}
inline void ac(long long x) {
  pitem r;
  ab(t, x - 1, t, r);
  t = aa(t, aa(new item(x), r));
}
inline void ad(long long x) {
  pitem l, r;
  ab(t, x - 1, t, r);
  ab(r, x, l, r);
  t = aa(t, r);
}
void output(pitem v) {
  if (!v) {
    return;
  }
  output(v->l);
  cout << v->key << " ";
  output(v->r);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  t = nullptr;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
    ac(a[i]);
  }
  cin >> m;
  for (long long i = 1; i <= m; i++) {
    cin >> type >> l >> r;
    if (type == 1) {
      ad(a[l]);
      a[l] += r;
      ac(a[l]);
    } else {
      pitem tl, tr;
      ab(t, l - 1, t, tl);
      ab(tl, r, tl, tr);
      cout << (!tl ? 0 : tl->ans) << "\n";
      t = aa(t, aa(tl, tr));
    }
  }
}

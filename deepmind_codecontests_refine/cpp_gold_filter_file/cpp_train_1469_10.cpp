#include <bits/stdc++.h>
using namespace std;
ifstream in;
ofstream out;
const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7;
struct triple {
  long long l, r, v;
};
long long lt[ml], rt[ml];
long long t[ml];
long long n, i, j, s, q;
vector<long long> x, w;
vector<triple> seg;
bool viv = false;
void change(long long v, long long tl, long long tr, long long num,
            long long nw) {
  if (tl <= num && num <= tr) {
    t[v] += nw;
    lt[v] += (x[num] - x[tl] - num + tl) * nw;
    long long real_tr = min(tr, n - 1);
    rt[v] += (x[real_tr] - x[num] - real_tr + num) * nw;
    lt[v] %= mod;
    rt[v] %= mod;
    long long tm = tl + tr >> 1;
    if (tl < tr) {
      change(2 * v, tl, tm, num, nw);
      change(2 * v + 1, tm + 1, tr, num, nw);
    }
  }
}
long long getr(long long l, long long r, long long v, long long tl,
               long long tr, long long num) {
  if (r < tl || tr < l) return 0;
  if (l <= tl && tr <= r) {
    long long ret = rt[v];
    long long real_tr = min(tr, n - 1);
    ret += ((t[v] % mod) * (x[num] - x[real_tr] - num + real_tr));
    ret %= mod;
    return ret;
  }
  long long tm = tl + tr >> 1;
  return (getr(l, r, 2 * v, tl, tm, num) +
          getr(l, r, 2 * v + 1, tm + 1, tr, num)) %
         mod;
}
long long getl(long long l, long long r, long long v, long long tl,
               long long tr, long long num) {
  if (r < tl || tr < l) return 0;
  if (l <= tl && tr <= r) {
    long long ret = lt[v];
    ret += ((t[v] % mod) * (x[tl] - x[num] - tl + num));
    ret %= mod;
    return ret;
  }
  long long tm = tl + tr >> 1;
  return (getl(l, r, 2 * v, tl, tm, num) +
          getl(l, r, 2 * v + 1, tm + 1, tr, num)) %
         mod;
}
long long sum(long long l, long long r, long long v, long long tl,
              long long tr) {
  if (r < tl || tr < l) return 0;
  if (l <= tl && tr <= r) return t[v];
  long long tm = tl + tr >> 1;
  return sum(l, r, 2 * v, tl, tm) + sum(l, r, 2 * v + 1, tm + 1, tr);
}
long long found(long long a, long long b) {
  long long l = a, r = b + 1;
  long long locs = sum(a, b, 1, 0, s - 1);
  long long tol = 0;
  while (l + 1 != r) {
    long long mi = l + r >> 1;
    long long ls = tol + sum(l, mi - 1, 1, 0, s - 1);
    if (2 * ls <= locs)
      l = mi, tol = ls;
    else
      r = mi;
  }
  return l;
}
void get(long long l, long long r, long long v, long long tl, long long tr) {
  if (r < tl || tr < l) return;
  if (l <= tl && tr <= r) {
    seg.push_back({tl, tr, t[v]});
    return;
  }
  long long tm = tr + tl >> 1;
  get(l, r, 2 * v, tl, tm);
  get(l, r, 2 * v + 1, tm + 1, tr);
}
long long ver(long long l, long long r, long long v, long long tl,
              long long tr) {
  if (l == tl && r == tr) return v;
  long long tm = tl + tr >> 1;
  if (tm >= r)
    return ver(l, r, 2 * v, tl, tm);
  else
    return ver(l, r, 2 * v + 1, tm + 1, tr);
}
long long gran(long long v, long long l, long long r, long long want) {
  if (l == r) return l;
  if (t[v] == want) return r + 1;
  long long tm = l + r >> 1;
  if (t[2 * v] > want) return gran(2 * v, l, tm, want);
  return gran(2 * v + 1, tm + 1, r, want - t[2 * v]);
}
long long found_new(long long a, long long b) {
  long long locs = sum(a, b, 1, 0, s - 1);
  seg.clear();
  get(a, b, 1, 0, s - 1);
  vector<long long> pr;
  pr.push_back(seg[0].v);
  for (long long i = 1; i < seg.size(); i++) pr.push_back(pr.back() + seg[i].v);
  j = 0;
  while (pr[j] * 2 < locs) j++;
  if (pr[j] * 2 == locs) return seg[j].r + 1;
  long long l = seg[j].l;
  long long r = seg[j].r;
  long long want = locs / 2;
  if (j != 0) want -= pr[j - 1];
  long long v = ver(l, r, 1, 0, s - 1);
  return gran(v, l, r, want);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> q;
  x.resize(n);
  w.resize(n);
  for (auto &i : x) cin >> i;
  for (auto &i : w) cin >> i;
  s = 1;
  while (s < n) s *= 2;
  for (i = 0; i < n; i++) change(1, 0, s - 1, i, w[i]);
  if (viv) {
    for (i = 1; i < n + s; i++) cout << t[i] << ' ';
    cout << endl;
    for (i = 1; i < n + s; i++) cout << lt[i] << ' ';
    cout << endl;
    for (i = 1; i < n + s; i++) cout << rt[i] << ' ';
    cout << endl;
  }
  for (i = 0; i < q; i++) {
    long long a, b;
    cin >> a >> b;
    if (a < 0) {
      a = -a;
      a--;
      change(1, 0, s - 1, a, b - w[a]);
      w[a] = b;
    } else {
      a--;
      b--;
      long long mi = found_new(a, b);
      long long lans = 0;
      lans += getr(a, mi - 1, 1, 0, s - 1, mi);
      lans += getl(mi + 1, b, 1, 0, s - 1, mi);
      lans %= mod;
      lans += mod;
      lans %= mod;
      cout << lans << '\n';
    }
  }
  return 0;
}

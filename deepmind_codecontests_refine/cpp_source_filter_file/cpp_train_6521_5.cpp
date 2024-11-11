#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
int seive[1000006], d[1000006];
int st[4 * 300005], n, m, a[300005];
long long stmx[4 * 300005];
void build(int lo, int hi, int pos) {
  if (lo == hi) {
    st[pos] = a[lo];
    stmx[pos] = 1ll * a[lo];
    return;
  }
  int mid = (lo + hi) / 2;
  build(lo, mid, 2 * pos + 1);
  build(mid + 1, hi, 2 * pos + 2);
  stmx[pos] = max(stmx[2 * pos + 1], stmx[2 * pos + 2]);
  st[pos] = st[2 * pos + 1] + st[2 * pos + 2];
}
long long rq(int qlo, int qhi, int lo, int hi, int pos) {
  if (qlo > hi || qhi < lo) {
    return 0ll;
  }
  if (qlo <= lo && hi <= qhi) {
    return st[pos];
  }
  int mid = (lo + hi) / 2;
  long long le = rq(qlo, qhi, lo, mid, 2 * pos + 1);
  long long ri = rq(qlo, qhi, mid + 1, hi, 2 * pos + 2);
  return le + ri;
}
void upd(int qlo, int qhi, int lo, int hi, int pos) {
  if (qlo > hi || qhi < lo) {
    return;
  }
  if (lo == hi) {
    st[pos] = d[st[pos]];
    stmx[pos] = d[stmx[pos]];
    return;
  }
  if (qlo <= lo && hi <= qhi) {
    if (stmx[pos] <= 2) return;
  }
  int mid = (lo + hi) / 2;
  upd(qlo, qhi, lo, mid, 2 * pos + 1);
  upd(qlo, qhi, mid + 1, hi, 2 * pos + 2);
  stmx[pos] = max(stmx[2 * pos + 1], stmx[2 * pos + 2]);
  st[pos] = st[2 * pos + 1] + st[2 * pos + 2];
  return;
}
void ini() {
  iota(seive, seive + 1000006, 0);
  for (int i = (int)2; i < (int)1000006; i = i + 1) {
    if (seive[i] != i) continue;
    for (int j = (int)2 * i; j < (int)1000006; j = j + i) {
      seive[j] = min(seive[j], i);
    }
  }
  d[1] = 1;
  for (int i = (int)2; i < (int)1000006; i = i + 1) {
    int cr = i, an = 1, cnt = 0, div;
    while (cr != 1) {
      cnt = 0;
      div = seive[cr];
      while (cr != 1 && seive[cr] == div) {
        cnt++;
        cr /= div;
      }
      an *= (cnt + 1);
    }
    d[i] = an;
  }
  return;
}
void solve() {
  cin >> n >> m;
  for (int i = (int)0; i < (int)n; i = i + 1) cin >> a[i];
  ;
  ini();
  build(0, n - 1, 0);
  int t, l, r;
  for (int i = (int)0; i < (int)m; i = i + 1) {
    cin >> t >> l >> r;
    l--;
    r--;
    if (t == 1)
      upd(l, r, 0, n - 1, 0);
    else {
      cout << rq(l, r, 0, n - 1, 0) << '\n';
      ;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  t = 1;
  while (t--) {
    solve();
  }
}

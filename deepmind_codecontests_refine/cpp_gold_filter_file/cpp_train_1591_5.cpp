#include <bits/stdc++.h>
using namespace std;
long long arr[300005];
struct stnode {
  long long ma_eve;
  long long ma_odd;
  long long mi_eve;
  long long mi_odd;
};
stnode st[2000005];
void merge(stnode &f, stnode &n1, stnode &n2) {
  f.ma_eve = max(n1.ma_eve + n2.ma_eve, n1.ma_odd - n2.mi_odd);
  f.mi_eve = min(n1.mi_eve + n2.mi_eve, n1.mi_odd - n2.ma_odd);
  f.ma_odd = max(n1.ma_eve + n2.ma_odd, n1.ma_odd - n2.mi_eve);
  f.mi_odd = min(n1.mi_eve + n2.mi_odd, n1.mi_odd - n2.ma_eve);
}
void build(long long node, long long l, long long r) {
  if (l == r) {
    st[node].mi_odd = st[node].ma_odd = arr[l];
    st[node].mi_eve = st[node].ma_eve = 0;
    return;
  }
  long long m = (l + r) / 2;
  build(2 * node, l, m);
  build(2 * node + 1, m + 1, r);
  merge(st[node], st[2 * node], st[2 * node + 1]);
}
void update(long long node, long long l, long long r, long long pos,
            long long val) {
  if (l == r) {
    st[node].mi_odd = st[node].ma_odd = val;
  } else {
    long long mid = (l + r) / 2;
    if (pos <= mid)
      update(2 * node, l, mid, pos, val);
    else
      update(2 * node + 1, mid + 1, r, pos, val);
    merge(st[node], st[2 * node], st[2 * node + 1]);
  }
}
stnode query(long long ind, long long l, long long r, long long lo,
             long long hi) {
  if (l == lo && r == hi) return st[ind];
  long long mid = (l + r) / 2;
  if (lo > mid) return query(2 * ind + 1, mid + 1, r, lo, hi);
  if (hi <= mid) return query(2 * ind, l, mid, lo, hi);
  stnode left = query(2 * ind, l, mid, lo, mid);
  stnode right = query(2 * ind + 1, mid + 1, r, mid + 1, hi);
  stnode result;
  merge(result, left, right);
  return result;
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n, q;
    cin >> n >> q;
    for (long long i = 1; i <= n; i++) cin >> arr[i];
    build(1, 1, n);
    cout << query(1, 1, n, 1, n).ma_odd << "\n";
    for (long long i = 0; i < q; i++) {
      long long l, r;
      cin >> l >> r;
      update(1, 1, n, l, arr[r]);
      update(1, 1, n, r, arr[l]);
      long long val = arr[r];
      arr[r] = arr[l];
      arr[l] = val;
      cout << query(1, 1, n, 1, n).ma_odd << "\n";
    }
  }
}

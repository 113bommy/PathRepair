#include <bits/stdc++.h>
using namespace std;
const long long int MAXM = 1e5 + 5;
const long long int INF = 2e9;
const long long int MOD = 1e9 + 7;
struct bus {
  long long int s, e;
  bus() {}
  bus(long long int _s, long long int _e) {
    s = _s;
    e = _e;
  }
};
long long int n, m, tmp[2 * MAXM] = {0}, sz = 1, BIT[MAXM];
bus A[MAXM];
void update(long long int idx, long long int val) {
  for (long long int _idx = idx + 1; _idx < MAXM; _idx += (_idx) & (-_idx)) {
    BIT[_idx] += val;
  }
}
long long int query(long long int idx) {
  long long int ret = 0;
  for (long long int _idx = idx + 1; _idx > 0; _idx -= (_idx) & (-_idx)) {
    ret += BIT[_idx];
  }
  return ret;
}
long long int query(long long int l, long long int r) {
  return query(r) - query(l - 1);
}
bool cmp(bus a, bus b) { return (a.e != b.e ? a.e < b.e : a.s < b.s); }
int main() {
  cin >> n >> m;
  for (long long int i = 0; i < m; i++) {
    cin >> A[i].s >> A[i].e;
    tmp[sz++] = A[i].s;
    tmp[sz++] = A[i].e;
  }
  sort(tmp, tmp + sz);
  sz = unique(tmp, tmp + sz) - tmp;
  for (long long int i = 0; i < m; i++) {
    A[i].s = lower_bound(tmp, tmp + sz, A[i].s) - tmp;
    A[i].e = lower_bound(tmp, tmp + sz, A[i].e) - tmp;
  }
  n = lower_bound(tmp, tmp + sz, n) - tmp;
  sort(A, A + m, cmp);
  update(0, 1);
  for (long long int i = 0; i < m; i++) {
    long long int tmp = query(A[i].s, A[i].e - 1) % MOD;
    update(A[i].e, tmp);
  }
  cout << query(n, n) << endl;
}

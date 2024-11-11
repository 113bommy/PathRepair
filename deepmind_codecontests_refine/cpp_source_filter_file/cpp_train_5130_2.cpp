#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const int inf = 1e9;
const long long biginf = 1e18;
const long double pi = acosl(-1);
const long double eps = 1e-9;
long long n, maxlen = 0;
vector<long long> v, bitChange;
long long bit(long long a, long long pos) { return (a >> pos) & 1; }
void foo(vector<long long>& a, long long d = maxlen) {
  if (d == -1 || a.size() <= 1) return;
  vector<long long> b1, b0, suf0(a.size(), 0), suf1(a.size(), 0);
  for (int i = a.size() - 1; i >= 0; i--) {
    if (i < a.size() - 1) {
      suf0[i] = suf0[i + 1];
      suf1[i] = suf1[i + 1];
    }
    if (!bit(v[a[i]], d)) {
      suf0[i]++;
    } else {
      suf1[i]++;
    }
  }
  long long cntInv = 0, cntInvChange = 0;
  for (int i = 0; i < a.size(); i++) {
    if (bit(v[a[i]], d)) {
      cntInv += suf0[i];
      b1.push_back(a[i]);
    } else {
      cntInvChange += suf1[i];
      b0.push_back(a[i]);
    }
  }
  bitChange[d] += cntInv - cntInvChange;
  foo(b1, d - 1);
  foo(b0, d - 1);
}
int invCount = 0;
vector<long long> nv;
vector<long long> mergeSortCount(long long l, long long r) {
  if (l == r) {
    vector<long long> res;
    res.push_back(nv[l]);
    return res;
  }
  vector<long long> lv, rv;
  long long m = l + (r - l) / 2;
  lv = mergeSortCount(l, m);
  rv = mergeSortCount(m + 1, r);
  vector<long long> res(r - l + 1);
  int curL = 0, curR = 0;
  for (int i = 0; i < r - l + 1; i++) {
    if (curL == lv.size()) {
      res[i] = rv[curR++];
      continue;
    }
    if (curR == rv.size()) {
      res[i] = lv[curL++];
      continue;
    }
    if (lv[curL] > rv[curR]) {
      invCount += lv.size() - curL;
      res[i] = rv[curR++];
    } else {
      res[i] = lv[curL++];
    }
  }
  return res;
}
void solve() {
  long long n;
  cin >> n;
  v.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    maxlen = max(maxlen, (long long)log2(v[i]));
  }
  bitChange.resize(maxlen + 1, 0);
  vector<long long> inds(n);
  for (long long i = 0; i < n; i++) inds[i] = i;
  foo(inds);
  long long optX = 0;
  for (int i = 0; i <= maxlen; i++) {
    if (bitChange[i] > 0) {
      optX |= (1 << i);
    }
  }
  nv.resize(n);
  for (int i = 0; i < n; i++) {
    nv[i] = v[i] ^ optX;
  }
  mergeSortCount(0, n - 1);
  cout << invCount << " " << optX;
}
void multisolve() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
}

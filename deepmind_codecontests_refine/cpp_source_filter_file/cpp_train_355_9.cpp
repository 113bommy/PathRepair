#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T bigmod(T p, T e, T M) {
  long long int ret = 1;
  for (; e > 0; e >>= 1) {
    if (e & 1) ret = (ret * p) % M;
    p = (p * p) % M;
  }
  return (T)ret;
}
template <class T>
inline T gcd(T a, T b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
template <class T>
inline T modinverse(T a, T M) {
  return bigmod(a, M - 2, M);
}
template <class T>
inline T bpow(T p, T e) {
  long long int ret = 1;
  for (; e > 0; e >>= 1) {
    if (e & 1) ret = (ret * p);
    p = (p * p);
  }
  return (T)ret;
}
int toInt(string s) {
  int sm;
  stringstream ss(s);
  ss >> sm;
  return sm;
}
int toLlint(string s) {
  long long int sm;
  stringstream ss(s);
  ss >> sm;
  return sm;
}
const double eps = 1e-9;
int ts, kk = 1;
int n, b[500005];
pair<int, int> a[500005];
int lt[500005], rt[500005];
int main() {
  int t, i, j, k;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &k);
    b[i] = k;
    a[i] = pair<int, int>(k, i);
    lt[i] = i - 1;
    rt[i] = i + 1;
  }
  sort(a + 1, a + n - 1);
  int x, y;
  long long int rs = 0;
  int lo, hi;
  lo = 0;
  hi = n - 1;
  for (i = 0; i < n - 2; i++) {
    k = a[i].second;
    if (k == lo) {
      rs += a[i].first;
      lo = rt[k];
      continue;
    }
    if (k == hi) {
      rs += a[i].first;
      hi = lt[k];
      continue;
    }
    x = lt[k];
    y = rt[k];
    rs += min(b[x], b[y]);
    rt[x] = y;
    lt[y] = x;
  }
  cout << rs << '\n';
  return 0;
}

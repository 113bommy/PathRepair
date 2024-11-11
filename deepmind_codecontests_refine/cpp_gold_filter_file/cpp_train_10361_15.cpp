#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T bigmod(T p, T e, T M) {
  long long ret = 1;
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
map<long long, int> mm;
long long ar[100001], dp[100001], seg[400001];
void insert(int idx, int s, int e, int p, long long v) {
  if (s == e) {
    seg[idx] = max(seg[idx], v);
    return;
  }
  int mid = (s + e) / 2;
  if (p <= mid)
    insert(idx * 2 + 1, s, mid, p, v);
  else
    insert(idx * 2 + 2, mid + 1, e, p, v);
  seg[idx] = max(seg[idx], v);
}
long long query(int idx, int s, int e, int st, int ed) {
  if (st > ed) return 0;
  if (s == st && e == ed) return seg[idx];
  int mid = (s + e) / 2;
  if (ed <= mid)
    return query(idx * 2 + 1, s, mid, st, ed);
  else if (st > mid)
    return query(idx * 2 + 2, mid + 1, e, st, ed);
  else
    return max(query(idx * 2 + 1, s, mid, st, mid),
               query(idx * 2 + 2, mid + 1, e, mid + 1, ed));
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = (0); i < (n); ++i) {
    long long r, h;
    cin >> r >> h;
    ar[i] = r * r * h;
    mm[ar[i]] = 1;
  }
  int cc = 0;
  for (auto &v : mm) v.second = ++cc;
  double res = 0.0;
  for (int i = n - 1; i >= 0; i--) {
    dp[i] = ar[i] + query(0, 1, cc, mm[ar[i]] + 1, cc);
    insert(0, 1, cc, mm[ar[i]], dp[i]);
    res = max(res, (double)dp[i]);
  }
  cout << fixed << setprecision(10) << res * acos(-1.0) << endl;
}

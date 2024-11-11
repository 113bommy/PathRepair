#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long nm = 0;
  bool fh = true;
  char cw = getchar();
  for (; !isdigit(cw); cw = getchar()) fh ^= (cw == '-');
  for (; isdigit(cw); cw = getchar()) nm = nm * 10 + (cw - '0');
  return fh ? nm : -nm;
}
long long n, m, K, P, ds[100020], h[100020], a[100020], Hv[100020];
priority_queue<pair<long long, long long> > Qh;
inline long long calc(long long x, long long y) {
  return (x % y == 0ll) ? (x / y) : (x / y + 1ll);
}
inline bool chk(long long x) {
  while (!Qh.empty()) Qh.pop();
  for (long long i = 1; i <= n; i++) {
    ds[i] = x / a[i], Hv[i] = 0ll;
    if (h[i] + m * a[i] > x) Qh.push(make_pair(-ds[i], i));
  }
  long long all = m * K;
  for (long long k = 1; k <= m; k++) {
    for (long long i = 1, id; i <= K; i++) {
      if (Qh.empty()) break;
      id = Qh.top().second, Qh.pop(), --all;
      if (ds[id] < k) return false;
      Hv[id] += P, ds[id] = (x + Hv[id]) / a[id];
      if (ds[id] < m) Qh.push(make_pair(-ds[id], id));
    }
    if (Qh.empty()) break;
  }
  if (!Qh.empty()) return false;
  long long res = 0ll;
  for (long long i = 1; i <= n; i++) {
    long long nowd = x + Hv[i] - m * a[i], tmp;
    if (nowd >= h[i])
      tmp = 0ll;
    else
      tmp = calc(h[i] - nowd, P);
    res += tmp;
  }
  return res <= all;
}
int main() {
  n = read(), m = read(), K = read(), P = read();
  for (long long i = 1; i <= n; i++) h[i] = read(), a[i] = read();
  long long ans = (1ll << 45);
  for (long long k = 45; k >= 0; --k) {
    long long tmp = ans - (1ll << k);
    if (tmp >= 0ll && chk(tmp)) ans = tmp;
  }
  printf("%lld\n", ans);
  return 0;
}

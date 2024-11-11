#include <bits/stdc++.h>
using namespace std;
const int N = 100005, oo = 0x3c3c3c3c;
int n, m, k, p;
int h[N], a[N];
inline long long ceil(long long a, long long b) { return a / b + !!(a % b); }
inline long long g(long long hu, int u) { return hu / a[u] + 1; }
struct cmp {
  inline bool operator()(pair<long long, long long> p,
                         pair<long long, long long> q) {
    return g(p.first, p.second) > g(q.first, q.second);
  }
};
bool ok(long long x) {
  priority_queue<pair<pair<long long, long long>, pair<long long, long long> > >
      qu;
  for (int i = 1; i <= n; i++)
    qu.push(pair<pair<long long, long long>, pair<long long, long long> >(
        pair<long long, long long>(-g(x, i), 0),
        pair<long long, long long>(x, i)));
  int Remain = 0;
  for (int i = 1; i <= m; i++) {
    if (Remain) {
      Remain += k;
      continue;
    }
    for (int j = 1; j <= k; j++) {
      pair<pair<long long, long long>, pair<long long, long long> > Top =
          qu.top();
      long long hu = Top.second.first, u = Top.second.second,
                gu = -Top.first.first;
      if (gu <= i) {
        return false;
      } else if (gu <= m) {
        qu.pop();
        qu.push(pair<pair<long long, long long>, pair<long long, long long> >(
            pair<long long, long long>(-g(hu + p, u), 0),
            pair<long long, long long>(hu + p, u)));
      } else {
        Remain++;
      }
    }
  }
  while (qu.size()) {
    pair<pair<long long, long long>, pair<long long, long long> > Top =
        qu.top();
    qu.pop();
    long long hu = Top.second.first, u = Top.second.second,
              gu = -Top.first.first;
    hu = hu - 1LL * a[u] * m;
    if (hu < h[u]) Remain -= ceil(h[u] - hu, p);
  }
  return Remain >= 0;
}
int main() {
  scanf("%d%d%d%d", &n, &m, &k, &p);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &h[i], &a[i]);
  }
  long long ll = 0, rr = 5001LL * oo, mm = (ll + rr) / 2;
  while (ll != rr) {
    if (ok(mm))
      rr = mm;
    else
      ll = mm + 1;
    mm = (ll + rr) / 2;
  }
  cout << mm << endl;
}

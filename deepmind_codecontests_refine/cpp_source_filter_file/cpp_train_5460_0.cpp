#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 7;
const int M = 1e9 + 9;
int n, q;
long long a[N], fib[N];
void pre() {
  fib[0] = 0;
  fib[1] = 1;
  for (int i = 2; i < N; i++) fib[i] = (fib[i - 1] + fib[i - 2]) % M;
}
long long term(long long x, long long y, int nn) {
  return (x * fib[nn - 1] + y * fib[nn]) % M;
}
long long sum(long long x, long long y, int nn) {
  return (term(x, y, nn + 1) - y + M) % M;
}
long long tr[4 * N];
pair<long long, long long> lz[4 * N];
pair<long long, long long> operator+(pair<long long, long long> a,
                                     pair<long long, long long> b) {
  return make_pair((a.first + b.first) % M, (a.second + b.second) % M);
}
bool operator!(pair<long long, long long> a) {
  return a.first == 0 && a.second == 0;
}
void build(int u, int st, int en) {
  if (st == en) {
    tr[u] = a[st];
  } else {
    int mid = (st + en) / 2;
    build(2 * u, st, mid);
    build(2 * u + 1, mid + 1, en);
    tr[u] = (tr[2 * u] + tr[2 * u + 1]) % M;
  }
}
void propagate(int u, int st, int en) {
  if (!lz[u]) return;
  tr[u] = (tr[u] + sum(lz[u].first, lz[u].second, en - st + 1));
  if (st != en) {
    int mid = (st + en) / 2;
    lz[2 * u] = lz[2 * u] + lz[u];
    lz[2 * u + 1] = lz[2 * u + 1] +
                    make_pair(term(lz[u].first, lz[u].second, mid + 1 - st),
                              term(lz[u].first, lz[u].second, mid + 2 - st));
  }
  lz[u] = make_pair(0, 0);
}
void update(int u, int st, int en, int l, int r) {
  propagate(u, st, en);
  if (r < st || en < l)
    return;
  else if (l <= st && en <= r)
    lz[u] = lz[u] + make_pair(fib[st - l + 1], fib[st - l + 2]),
    propagate(u, st, en);
  else {
    int mid = (st + en) / 2;
    update(2 * u, st, mid, l, r);
    update(2 * u + 1, mid + 1, en, l, r);
    tr[u] = (tr[2 * u] + tr[2 * u + 1]) % M;
  }
}
long long query(int u, int st, int en, int l, int r) {
  propagate(u, st, en);
  if (r < st || en < l)
    return 0;
  else if (l <= st && en <= r)
    return tr[u];
  else {
    int mid = (st + en) / 2;
    return (query(2 * u, st, mid, l, r) + query(2 * u + 1, mid + 1, en, l, r)) %
           M;
  }
}
void debug(int u, int st, int en) {
  cerr << "----->" << u << " " << st << " " << en << " " << tr[u] << " "
       << lz[u].first << " " << lz[u].second << endl;
  if (st == en) return;
  int mid = (st + en) / 2;
  debug(2 * u, st, mid);
  debug(2 * u + 1, mid + 1, en);
}
int main() {
  pre();
  cin >> n >> q;
  for (int i = 1; i <= n; i++) cin >> a[i];
  build(1, 1, n);
  while (q--) {
    int t, l, r;
    cin >> t >> l >> r;
    if (t == 1)
      update(1, 1, n, l, r);
    else
      cout << query(1, 1, n, l, r) << '\n';
  }
}

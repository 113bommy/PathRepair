#include <bits/stdc++.h>
using namespace std;
long long poww(long long a, long long b, long long md) {
  return (!b ? 1
             : (b & 1 ? a * poww(a * a % md, b / 2, md) % md
                      : poww(a * a % md, b / 2, md) % md));
}
using namespace std;
const int max_n = 2e5 + 20;
int n, m, k, p, q, x, a[max_n], b[max_n], par[max_n];
bool full[max_n];
int do_job(int p, int v) {
  if (p == n) {
    return n;
  }
  int c = b[p];
  b[p] = min(a[p], b[p] + v);
  v -= b[p] - c;
  if (b[p] == a[p]) {
    full[p] = true;
  }
  if (full[p]) {
    par[p] = (do_job(par[p], v));
    return par[p];
  } else {
    return p;
  }
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    par[i] = i + 1;
  }
  cin >> m;
  while (m--) {
    cin >> q;
    if (q == 1) {
      cin >> p >> x;
      p--;
      int o = do_job(p, x);
    } else {
      cin >> k;
      cout << b[k - 1] << '\n';
    }
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int mxN = 2e5, M = 1e9 + 7;
int n, q, x, y;
long long a[mxN], w[mxN], ft[mxN + 1][2];
void upd(int i, long long x, int j) {
  for (++i; i <= n; i += i & -i) {
    ft[i][j] += x;
    if (j) ft[i][j] %= M;
  }
}
long long qry(int i, int j) {
  long long r = 0;
  for (; i; i -= i & -i) {
    r += ft[i][j];
    if (j) r %= M;
  }
  return r;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> q;
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) {
    cin >> w[i];
    upd(i, w[i], 0);
    upd(i, (a[i] - i) * w[i], 1);
  }
  while (q--) {
    cin >> x >> y;
    if (x < 0) {
      x = -x - 1;
      upd(x, y - w[x], 0);
      upd(x, (a[x] - x) * (y - w[x]), 1);
      w[x] = y;
    } else {
      --x;
      --y;
      long long s1 = qry(x, 0), s2 = qry(y + 1, 0);
      int lb = x, rb = y;
      while (lb <= rb) {
        int mb = (lb + rb) / 2;
        long long c = qry(mb + 1, 0);
        if (2 * (c - s1) >= s2 - s1)
          rb = mb - 1;
        else
          lb = mb + 1;
      }
      cout << ((qry(y + 1, 1) - 2 * qry(lb, 1) + qry(x, 1)) -
               (qry(y + 1, 0) - 2 * qry(lb, 0) + qry(x, 0)) % M * (a[lb] - lb) %
                   M +
               M) %
                  M
           << "\n";
    }
  }
}

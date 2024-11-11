#include <bits/stdc++.h>
using namespace std;
struct www {
  int c, l;
  double s;
} f[1000];
int n, l, i, p;
long long res, nw;
bool cmp(const www &a, const www &b) { return a.s < b.s; }
int main() {
  cin >> n >> l;
  for (i = 1; i <= n; i++) cin >> f[i].c;
  f[1].l = 1;
  for (i = 2; i <= n; i++) f[i].l = f[i - 1].l * 2;
  for (i = 2; i <= n; i++)
    if (f[i - 1].c * 2 < f[i].c) f[i].c = f[i - 1].c * 2;
  res = 1e18;
  nw = 0;
  for (i = 1; i <= n; i++) {
    p = l / f[i].l;
    nw = nw + 1ll * p * f[i].c;
    if (l % f[i].c == 0) {
      if (nw < res) res = nw;
      break;
    }
    if (nw + f[i].c < res) res = nw + f[i].c;
    l = l % f[i].l;
  }
  cout << res << endl;
  return 0;
}

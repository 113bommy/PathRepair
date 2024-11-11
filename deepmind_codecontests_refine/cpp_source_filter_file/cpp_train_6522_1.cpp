#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 69, base = 1024 * 1024, mod = 1e9 + 7;
int l, p, lp, pp, al, ap, x1, x2, b, t[N], n, d;
void tl() {
  int re = b;
  int pal = al;
  while (re > 0 && pal <= l) {
    re -= t[pal];
    pal++;
  }
  if (re > 0) {
    x1++;
    return;
  }
  re = b;
  while (re > 0 && al <= l) {
    int zm = min(re, t[al]);
    re -= zm;
    t[al] -= zm;
    if (t[al] == 0) al++;
  }
}
void tp() {
  int re = b;
  int pap = ap;
  while (re > 0 && pap >= p) {
    re -= t[pap];
    pap--;
  }
  if (re > 0) {
    x2++;
    return;
  }
  re = b;
  while (re > 0 && ap >= p) {
    int zm = min(re, t[ap]);
    re -= zm;
    t[ap] -= zm;
    if (t[ap] == 0) ap--;
  }
}
int32_t main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> d >> b;
  for (int i = 1; i <= n; i++) cin >> t[i];
  l = 0;
  p = n + 1;
  lp = 1;
  pp = n;
  al = 1;
  ap = n;
  x1 = 0;
  x2 = 0;
  while (lp < pp) {
    l += 1 + d;
    p -= 1 + d;
    l = min(l, n);
    p = max(1, p);
    if (lp + 1 == pp - 1) {
      tl();
      break;
    }
    if (x1 >= x2)
      tl(), tp();
    else
      tp(), tl();
    lp++;
    pp--;
  }
  cout << max(x1, x2) << "\n";
}

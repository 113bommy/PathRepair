#include <bits/stdc++.h>
const long long M = 1000;
const long long N = 10020000;
const long long mx = (1e18);
using namespace std;
long long n, m, o, k, l, w, s, j, s1, e, mlen, s2, res, i, a[N], r, c, b[N];
void check() {
  long long l = 0;
  o = 1;
  s1 = s2 = 0;
  for (i = 1; i <= n; i++) b[i] = a[i];
  mlen = m;
  l = 0;
  for (i = 1; i <= (n + 1) / 2; i++) {
    if (i <= c) {
      mlen += 1 + m;
      continue;
    }
    while (s1 < k && l < mlen) {
      while (b[l] == 0 && l < mlen) l++;
      e = min(b[l], k - s1);
      s1 += e;
      b[l] -= e;
    }
    if (s1 >= k)
      s1 -= k;
    else {
      o = 0;
      break;
    }
    mlen += 1 + m;
  }
  mlen = n - m;
  l = n;
  for (i = n; i >= (n + 1) / 2 + 1; i--) {
    if ((n - i + 1) <= c) {
      mlen -= (m + 1);
      continue;
    }
    while (s2 < k && l > mlen) {
      while (b[l] == 0 && l > mlen) l--;
      e = min(b[l], k - s2);
      s2 += e;
      b[l] -= e;
    }
    if (s2 >= k)
      s2 -= k;
    else {
      o = 0;
      break;
    }
    mlen -= (m + 1);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m >> k;
  for (i = 1; i <= n; i++) cin >> a[i];
  l = 0;
  r = (n + 1) / 2;
  while (l < r) {
    c = (l + r) / 2;
    check();
    if (o == 0)
      l = c + 1;
    else
      r = c;
  }
  cout << l;
}

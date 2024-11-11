#include <bits/stdc++.h>
using namespace std;
const int Inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3fll;
int n, m, q, ans;
long long t;
int l[100005], r[100005];
int p[100005], s[100005];
int sc[100005];
bool qd[100005];
long long trytain(int l, int r, long long rem) {
  if (!rem) return 0;
  int xju = sc[l] - sc[r], ks = r - l;
  if (1ll * ks * xju <= rem) {
    for (int i = (l); i <= (r); ++i) sc[i] = sc[l];
    return rem - ks * xju;
  }
  long long ts = rem / ks;
  rem %= ks;
  for (int i = (l + 1); i <= (r); ++i) sc[i] += ts + (i - l - 1 < rem);
  return 0;
}
bool canpip(int l[], int w[], int ls, int ws) {
  int ptr = 0;
  long long wh = 0, wp = 0;
  for (int i = (ws); (-1) > 0 ? i <= (1) : i >= (1); i += (-1)) {
    wh += w[i];
    while (ptr < ls && l[ptr + 1] <= ws - i + 1) wp += l[++ptr];
    if (wh > wp + 1ll * (ws - i + 1) * (ls - ptr)) return 0;
  }
  return 1;
}
bool check(int mid, int hsc = -1) {
  memset(sc, -1, sizeof(sc));
  for (int i = 1; i <= (q); ++i) sc[p[i]] = s[i];
  sc[m + 1] = 0;
  long long ac = 0;
  for (int i = (m); (-1) > 0 ? i <= (1) : i >= (1); i += (-1)) {
    if (!qd[i]) sc[i] = sc[i + 1];
    ac += sc[i];
  }
  bool me = 0;
  if (mid >= p[1]) {
    for (int i = (p[1] + 1); i <= (mid); ++i) {
      if (qd[i] && s[1] != sc[i]) return 0;
      ac += s[1] - sc[i];
      sc[i] = s[1];
    }
    me = 1;
  } else if (~hsc) {
    for (int i = 1; i <= (mid); ++i) {
      if (qd[i] && hsc != sc[i]) return 0;
      ac += hsc - sc[i];
      sc[i] = hsc;
    }
  }
  if (ac > t) return 0;
  int na = t - ac;
  for (int i = (q); (-1) > 0 ? i <= (1) : i >= (1); i += (-1)) {
    na = trytain(max(p[i], mid), p[i + 1] - 1, na);
    if (!na || p[i] < mid) break;
  }
  if (p[1] > mid) {
    if (me)
      na = trytain(mid, p[1] - 1, na);
    else if (!~hsc) {
      sc[0] = n;
      na = trytain(0, p[1] - 1, na);
      if (sc[1] != sc[mid]) return check(mid, sc[1]);
    } else {
      sc[0] = n;
      na = trytain(mid, p[1] - 1, na);
      na = trytain(0, p[1] - 1, na);
      if (sc[1] != sc[mid]) return check(mid, sc[1]);
    }
  }
  if (na > 0) return 0;
  sort(sc + 1, sc + m + 1);
  return canpip(sc, l, m, n) && canpip(r, sc, n, m);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= (n); ++i) scanf("%d%d", l + i, r + i);
  scanf("%d", &q);
  vector<pair<int, int> > fs;
  for (int i = 1; i <= (q); ++i) {
    scanf("%d%d", p + i, s + i), qd[p[i]] = 1;
    fs.emplace_back(p[i], s[i]);
  }
  sort((fs).begin(), (fs).end());
  for (int i = 0; i < (q); ++i) tie(p[i + 1], s[i + 1]) = fs[i];
  p[q + 1] = m + 1;
  scanf("%lld", &t);
  sort(l + 1, l + n + 1);
  sort(r + 1, r + n + 1);
  int lm = 0, rm = m + 1;
  while (rm - lm > 1) {
    int mid = (lm + rm) >> 1;
    if (check(mid))
      lm = mid;
    else
      rm = mid;
  }
  if (!lm) return puts("-1 -1"), 0;
  if (lm >= p[1]) return printf("%d %d\n", lm, s[1]), 0;
  ans = lm;
  lm = s[1], rm = n + 1;
  while (rm - lm > 1) {
    int mid = (lm + rm) >> 1;
    if (check(ans, mid))
      lm = mid;
    else
      rm = mid;
  }
  printf("%d %d\n", ans, lm);
  return 0;
}

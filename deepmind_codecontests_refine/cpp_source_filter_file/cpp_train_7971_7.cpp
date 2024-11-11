#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5, M = N * 4;
int n, a[N], g[N], v[M], s[M], t[M], c[M];
void ins(int p, int x, int rk, int l, int r, int o) {
  s[o]++;
  if (l == r) return v[o] = x, c[o] = x + rk, void();
  rk -= t[o];
  if (p <= ((l + r) / 2))
    ins(p, x, rk + s[o * 2 + 1], l, ((l + r) / 2), o * 2);
  else
    ins(p, x, rk, ((l + r) / 2) + 1, r, o * 2 + 1), t[o * 2]++, c[o * 2]++;
  c[o] = min(c[o * 2], c[o * 2 + 1]) + t[o];
  v[o] = s[o * 2] ? v[o * 2] : v[o * 2 + 1];
}
int qry(int rk, int l, int r, int o) {
  return l < r ? s[o * 2 + 1] && v[o * 2 + 1] + rk + s[o * 2] <= 0
                     ? qry(rk + s[o * 2], ((l + r) / 2) + 1, r, o * 2 + 1)
                     : qry(rk, l, ((l + r) / 2), o * 2)
               : l;
}
int sz(int p, int l, int r, int o) {
  return l < r ? p <= ((l + r) / 2)
                     ? sz(p, l, ((l + r) / 2), o * 2)
                     : sz(p, ((l + r) / 2) + 1, r, o * 2 + 1) + s[o * 2]
               : s[o];
}
int qry(int p, int su, int l, int r, int o) {
  if (p <= l) return c[o] + su;
  su += t[o];
  int re = 1e9;
  if (p <= ((l + r) / 2) && s[o * 2])
    re = min(re, qry(p, su, l, ((l + r) / 2), o * 2));
  if (s[o * 2]) re = min(re, qry(p, su, ((l + r) / 2) + 1, r, o * 2 + 1));
  return re;
}
int main() {
  memset(c, 63, sizeof c);
  cin >> n;
  for (int i = (1); i <= (n); i++) scanf("%d", &a[i]), g[i] = a[i];
  sort(g + 1, g + n + 1);
  for (int i = (1); i <= (n); i++) {
    int p = lower_bound(g + 1, g + n + 1, a[i]) - g;
    ins(p, a[i], 0, 1, n, 1), g[p]--;
    int l = v[1] <= -1 ? qry(1, 1, n, 1) : 0, s = l ? sz(l, 1, n, 1) : 0;
    printf("%d\n", min(i - s * 2, qry(l + 1, 0, 1, n, 1)));
  }
  return 0;
}

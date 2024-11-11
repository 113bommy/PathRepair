#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
const int q = 233, mod = 1e9 + 7;
int ch[N << 2][2], siz[N << 2], H[N << 2];
int n, m, a[N], b[N], pos[N], HA, pw[N];
int ksm(int a, int b) {
  a %= mod;
  int res = 1;
  for (; b; b >>= 1) {
    if (b & 1) res = 1ll * res * a % mod;
    a = 1ll * a * a % mod;
  }
  return res;
}
void upd(int x) {
  siz[x] = siz[x << 1] + siz[x << 1 | 1];
  H[x] = (1ll * H[x << 1] * pw[siz[x << 1 | 1]] + H[x << 1 | 1]) % mod;
}
void Ins(int x, int p, int v, int s, int t) {
  if (s == t) {
    siz[x] = 1;
    H[x] = v;
    return;
  }
  int mid = s + t >> 1;
  if (p <= mid)
    Ins(x << 1, p, v, s, mid);
  else
    Ins(x << 1 | 1, p, v, mid + 1, t);
  upd(x);
}
void Del(int x, int p, int s, int t) {
  if (s == t) {
    siz[x] = 0;
    H[x] = 0;
    return;
  }
  int mid = s + t >> 1;
  if (p <= mid)
    Del(x << 1, p, s, mid);
  else
    Del(x << 1 | 1, p, mid + 1, t);
  upd(x);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (int i = 1; i <= m; ++i) scanf("%d", &b[i]), pos[b[i]] = i;
  pw[0] = 1;
  for (int i = 1; i <= m; ++i) pw[i] = 1ll * pw[i - 1] * q % mod;
  HA = 0;
  for (int i = 1; i <= n; ++i) HA = (1ll * HA * q + a[i]) % mod;
  int ans = 0;
  for (int i = 1; i <= n; ++i) Ins(1, pos[i], i, 1, m);
  if (H[1] == HA) ans++;
  int tmp = 1ll * (pw[n] - 1) * ksm(q - 1, mod - 2) % mod;
  tmp = (tmp + mod) % mod;
  for (int i = n + 1, dlt = tmp; i <= m; ++i, (dlt += tmp) %= mod) {
    Ins(1, pos[i], i, 1, m);
    Del(1, pos[i - n], 1, m);
    int tH = ((H[1] - dlt) % mod + mod) % mod;
    if (tH == HA) ans++;
  }
  cout << ans << '\n';
  return 0;
}

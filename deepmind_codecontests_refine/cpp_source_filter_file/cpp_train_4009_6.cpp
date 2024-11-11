#include <bits/stdc++.h>
using namespace std;
const int U = 65535, mod = 1000000007;
int state[5], f[10][65536];
char st[1000];
int qmod1(int x) { return x >= mod ? x - mod : x; }
int qmod2(int x) { return x + (x >> 31 & mod); }
void DFT_or(int a[]) {
  for (int i = 1; i <= U; i <<= 1)
    for (int j = 0; j <= U; j += i << 1)
      for (int k = 0; k < i; k++) a[i + j + k] = qmod1(a[i + j + k] + a[j + k]);
}
void IDFT_or(int a[]) {
  for (int i = 1; i <= U; i <<= 1)
    for (int j = 0; j <= U; j += i << 1)
      for (int k = 0; k < i; k++) a[i + j + k] = qmod2(a[i + j + k] - a[j + k]);
}
void DFT_and(int a[]) {
  for (int i = 1; i <= U; i <<= 1)
    for (int j = 0; j <= U; j += i << 1)
      for (int k = 0; k < i; k++) a[j + k] = qmod1(a[j + k] + a[i + j + k]);
}
void IDFT_and(int a[]) {
  for (int i = 1; i <= U; i <<= 1)
    for (int j = 0; j <= U; j += i << 1)
      for (int k = 0; k < i; k++) a[j + k] = qmod2(a[j + k] - a[i + j + k]);
}
void solve(int l, int r, int dep) {
  if (l == r) {
    fill(f[dep], f[dep] + U + 1, 0);
    if (st[l] == '?') {
      for (int i = 0; i < 4; i++)
        f[dep][state[i]] = 1, f[dep][U ^ state[i]] = 1;
    } else if (st[l] >= 'a')
      f[dep][U ^ state[st[l] - 97]] = 1;
    else
      f[dep][state[st[l] - 65]] = 1;
    return;
  }
  int stk = 1, mid;
  for (mid = l + 1; stk; ++mid)
    if (st[mid] == '(')
      ++stk;
    else if (st[mid] == ')')
      --stk;
  solve(l + 1, mid - 2, dep + 1);
  copy(f[dep + 1], f[dep + 1] + U + 1, f[dep]);
  solve(mid + 2, r - 1, dep + 1);
  int *a = f[dep], *b = f[dep + 1];
  if (st[mid] == '&') {
    DFT_and(a), DFT_and(b);
    for (int i = 0; i <= U; i++) a[i] = 1ll * a[i] * b[i] % mod;
    IDFT_and(a);
  } else if (st[mid] == '|') {
    DFT_or(a), DFT_or(b);
    for (int i = 0; i <= U; i++) a[i] = 1ll * a[i] * b[i] % mod;
    IDFT_or(a);
  } else {
    static int tmpa[U + 1], tmpb[U + 1];
    copy(a, a + U + 1, tmpa), copy(b, b + U + 1, tmpb);
    DFT_or(tmpa), DFT_or(tmpb), DFT_and(a), DFT_and(b);
    for (int i = 0; i <= U; i++)
      tmpa[i] = 1ll * tmpa[i] * tmpb[i] % mod, a[i] = 1ll * a[i] * b[i] % mod;
    IDFT_or(tmpa), IDFT_and(a);
    for (int i = 0; i <= U; i++) a[i] = qmod1(a[i] + tmpa[i]);
  }
}
pair<int, int> lim[20];
int main() {
  for (int i = 0; i < 4; i++)
    for (int k = 0; k < 16; k++)
      if (k >> i & 1) state[i] |= 1 << k;
  scanf("%s", st + 1);
  int n = strlen(st + 1);
  solve(1, n, 0);
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    for (int j = 0, x; j < 4; j++) {
      scanf("%d", &x);
      if (x) lim[i].first |= 1 << j;
    }
    scanf("%d", &lim[i].second);
  }
  int ans = 0;
  for (int i = 0; i <= U; i++) {
    int pd = 1;
    for (int j = 1; j <= n; j++)
      if ((i >> lim[j].first & 1) != lim[j].second) {
        pd = 0;
        break;
      }
    if (pd) ans = qmod1(ans + f[0][i]);
  }
  cout << ans << endl;
}

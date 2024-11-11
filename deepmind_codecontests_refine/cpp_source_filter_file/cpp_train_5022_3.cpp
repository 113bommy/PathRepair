#include <bits/stdc++.h>
using namespace std;
inline void read(int &x) {
  int v = 0, f = 1;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-')
    f = -1;
  else
    v = (c & 15);
  while (isdigit(c = getchar())) v = (v << 1) + (v << 3) + (c & 15);
  x = v * f;
}
inline void read(long long &x) {
  long long v = 0ll, f = 1ll;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-')
    f = -1;
  else
    v = (c & 15);
  while (isdigit(c = getchar())) v = (v << 1) + (v << 3) + (c & 15);
  x = v * f;
}
inline void readc(char &x) {
  char c;
  while (((c = getchar()) == ' ') || c == '\n')
    ;
  x = c;
}
const int e = 998244353, mod = 1e9 + 9;
int pw[100005];
int n, m, i, j, a[100005], bel[100005], l[100005], r[100005], blk, bs;
int stk[1005][1005], tp[1005], fsl[1005];
int hsh1[1005][1005], hsh2[1005][1005];
struct per {
  int x, l, r;
} cur[1005];
int tc;
void rebuild(int x, int typ) {
  int i;
  tp[x] = 0;
  for ((i) = (l[x]); (i) <= (r[x]); (i)++) {
    if (a[i] < 0 && tp[x] && stk[x][tp[x]] == -a[i]) {
      tp[x]--;
    } else {
      stk[x][++tp[x]] = a[i];
    }
  }
  fsl[x] = 0;
  for (((i)) = (1); ((i)) <= ((tp[x])); ((i))++) {
    if (stk[x][i] > 0) {
      if (fsl[x] == 0) fsl[x] = i;
    } else if (fsl[x]) {
      fsl[x] = -1;
    }
  }
  if (!fsl[x]) fsl[x] = tp[x] + 1;
  if (!(typ & 1)) {
    for (((i)) = (1); ((i)) <= ((tp[x])); ((i))++) {
      hsh2[x][i] =
          (1ll * hsh2[x][i - 1] * e + (stk[x][i] < 0 ? -stk[x][i] : 100003)) %
          mod;
    }
  }
  if (!(typ & 2)) {
    hsh1[x][tp[x] + 1] = 0;
    for (((i)) = ((tp[x])); ((i)) >= (1); ((i))--) {
      hsh1[x][i] =
          (1ll * hsh1[x][i + 1] * e + (stk[x][i] > 0 ? stk[x][i] : 200003)) %
          mod;
    }
  }
}
int gth1(int x, int l, int r) {
  int s = (hsh1[x][l] - 1ll * hsh1[x][r + 1] * pw[r - l + 1]) % mod;
  if (s < 0) s += mod;
  return s;
}
int gth2(int x, int l, int r) {
  int s = (hsh2[x][r] - 1ll * hsh2[x][l - 1] * pw[r - l + 1]) % mod;
  if (s < 0) s += mod;
  return s;
}
char push(int x) {
  if (fsl[x] == -1) return 0;
  int l = 1, r = fsl[x] - 1;
  while (tc) {
    int lt = cur[tc].r - cur[tc].l + 1;
    if (lt > r - l + 1) {
      break;
    }
    if (gth1(cur[tc].x, cur[tc].l, cur[tc].r) == gth2(x, l, l + lt - 1)) {
      l += lt;
      tc--;
    } else
      break;
  }
  if (l > r && tc) {
    int lt = r - l + 1;
    if (gth1(cur[tc].x, cur[tc].r - lt + 1, cur[tc].r) == gth2(x, l, r)) {
      cur[tc].r -= lt;
      l = r + 1;
    } else
      return 0;
  }
  if (l <= r) return 0;
  l = fsl[x];
  r = tp[x];
  if (l <= r) {
    cur[++tc] = (per){x, l, r};
  }
  return 1;
}
char solve(int l, int r) {
  if (bel[l] == bel[r]) {
    ::l[bs + 1] = l;
    ::r[bs + 1] = r;
    rebuild(bs + 1, 3);
    return !tp[bs + 1];
  }
  ::l[bs + 1] = l;
  ::r[bs + 1] = ::r[bel[l]];
  rebuild(bs + 1, 1);
  ::l[bs + 2] = ::l[bel[r]];
  ::r[bs + 2] = r;
  rebuild(bs + 2, 2);
  tc = 0;
  if (!push(bs + 1)) return 0;
  for ((i) = (bel[l] + 1); (i) <= (bel[r] - 1); (i)++)
    if (!push(i)) return 0;
  if (!push(bs + 2)) return 0;
  ;
  return !tc;
}
int main() {
  pw[0] = 1;
  for (((i)) = (1); ((i)) <= ((100000)); ((i))++)
    pw[i] = 1ll * pw[i - 1] * e % mod;
  read(n);
  read(m);
  blk = sqrt(n) + 1;
  for (((i)) = (1); ((i)) <= ((n)); ((i))++) {
    read(a[i]);
    bel[i] = i / blk + 1;
    if (l[bel[i]] == 0) l[bel[i]] = i;
    r[bel[i]] = i;
  }
  bs = bel[n];
  for (((i)) = (1); ((i)) <= ((bs)); ((i))++) {
    rebuild(i, 0);
  }
  int q;
  read(q);
  while (q--) {
    int op, x, y;
    read(op);
    read(x);
    read(y);
    if (op == 1) {
      a[x] = y;
      rebuild(bel[x], 0);
    } else {
      if (solve(x, y))
        puts("Yes");
      else
        puts("No");
    }
  }
  return 0;
}

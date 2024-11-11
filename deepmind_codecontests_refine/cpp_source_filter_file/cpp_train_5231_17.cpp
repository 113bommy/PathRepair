#include <bits/stdc++.h>
using namespace std;
struct state {
  int a[20];
  bool operator<(const state &b) const {
    for (int i = (int)(0); i <= (int)(19); i++)
      if (a[i] != b.a[i]) return a[i] < b.a[i];
    return 0;
  }
} sta[1005];
map<state, int> mp;
int n, top, bit[1 << 20], toper[100];
long long f[20][20], tr[20][20];
long long g[1 << 20], h[1 << 20], val[20];
char s[20][20];
void divide(int n, int d, state tmp) {
  if (!n) {
    toper[++top] = d - 1;
    sta[top] = tmp;
    mp[tmp] = top;
    return;
  }
  if (n < d) return;
  for (; n >= 0; n -= d) {
    divide(n, d + 1, tmp);
    ++tmp.a[d];
  }
}
int main() {
  scanf("%d", &n);
  state tmp;
  memset(tmp.a, 0, sizeof(tmp.a));
  divide(n, 1, tmp);
  for (int i = (int)(0); i <= (int)(n - 1); i++) scanf("%s", s[i]);
  for (int i = (int)(0); i <= (int)(n - 1); i++)
    for (int j = (int)(0); j <= (int)(n - 1); j++)
      tr[i][j] = (s[i][j] == '0' ? 0 : 1);
  for (int i = (int)(0); i <= (int)((1 << n) - 1); i++) {
    bit[i] = bit[i / 2] + (i & 1);
    memset(f, 0, sizeof(f));
    static int q[20];
    static bool ee[20][20];
    int id = 0, lim = n - 1;
    memset(q, 0, sizeof(q));
    memset(ee, 0, sizeof(ee));
    memset(f, 0, sizeof(f));
    for (int j = (int)(0); j <= (int)(lim); j++)
      if (i & (1 << j)) q[j] = ++id;
    for (int j = (int)(0); j <= (int)(lim); j++)
      for (int k = (int)(0); k <= (int)(lim); k++)
        if (!tr[j][k]) ee[q[j]][q[k]] = 1;
    for (int j = (int)(1); j <= (int)(id); j++) f[0][j] = 1;
    for (int j = (int)(1); j <= (int)(lim); j++)
      for (int k = (int)(1); k <= (int)(id); k++)
        for (int l = (int)(1); l <= (int)(id); l++)
          if (ee[k][l]) f[j][l] += f[j - 1][k];
    memset(val, 0, sizeof(val));
    for (int j = (int)(0); j <= (int)(n); j++)
      for (int k = (int)(1); k <= (int)(id); k++) val[j] += f[j][k];
    static long long p[20][20];
    for (int j = (int)(0); j <= (int)(n); j++) {
      p[j][0] = 1;
      for (int k = (int)(1); k <= (int)(n); k++) p[j][k] = p[j][k - 1] * val[j];
    }
    for (int j = (int)(1); j <= (int)(top); j++) {
      long long v = 1;
      for (int k = (int)(1); k <= (int)(toper[j]); k++)
        v *= p[k - 1][sta[j].a[k]];
      if ((n - bit[i]) & 1) v = -v;
      g[j] += v;
    }
  }
  for (int i = (int)(0); i <= (int)((1 << (n - 1)) - 1); i++) {
    memset(tmp.a, 0, sizeof(tmp.a));
    int l = 0;
    for (int j = (int)(0); j <= (int)(n - 1); j++)
      if (j == n - 1 || (i & (1 << j)))
        ++tmp.a[l + 1], l = 0;
      else
        ++l;
    h[i] = g[mp[tmp]];
  }
  n--;
  for (int d = 1; d < 1 << n; d <<= 1)
    for (int i = 0; i < 1 << n; i += d << 1)
      for (int j = 0; j < d; j++) h[i + j + d] -= h[i + j];
  for (int i = (int)(0); i <= (int)((1 << n) - 1); i++) printf("%lld ", h[i]);
}

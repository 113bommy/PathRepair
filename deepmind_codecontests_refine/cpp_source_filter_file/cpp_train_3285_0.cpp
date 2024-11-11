#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void read(T &x) {
  int f = 0;
  x = 0;
  char ch = getchar();
  for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
  for (; isdigit(ch); ch = getchar()) x = x * 10 + ch - '0';
  if (f) x = -x;
}
const int N = 255, mod = 998244353;
int f[N], g[N], p[N], q[N], cur[N], rev[N], vis[N], L[N], R[N], owo[N];
int n, bas, ans, c0, c1, c2, c3;
int mul(int x, int y) { return (long long)x * y % mod; }
void add(int &x, int y) { x = (x + y >= mod ? x + y - mod : x + y); }
int main() {
  read(n);
  for (int i = (1); i <= (n); i++) read(p[i]);
  for (int i = (1); i <= (n); i++) read(q[i]);
  for (int i = (1); i <= (n); i++) {
    if (p[i] && q[i])
      cur[p[i]] = q[i], rev[q[i]] = p[i];
    else if (q[i])
      L[q[i]] = 1;
    else if (p[i])
      R[p[i]] = 1;
    else
      c0++;
    owo[p[i]] = owo[q[i]] = 1;
  }
  for (int i = (1); i <= (n); i++) {
    if (vis[i] || rev[i]) continue;
    int p = i;
    vis[p] = 1;
    while (cur[p]) p = cur[p], vis[p] = 1;
    if (L[i] && R[p])
      c0++;
    else if (R[p])
      c1++;
    else if (L[i])
      c2++;
    else if (owo[i])
      c3++;
  }
  for (int i = (1); i <= (n); i++) {
    if (vis[i]) continue;
    int p = i;
    bas++;
    while (cur[p] != i) vis[p] = 1, p = cur[p];
    vis[p] = 1;
  }
  int res = 1, cnt = 0;
  for (int i = (1); i <= (n); i++)
    if (!owo[i]) res = mul(res, ++cnt);
  for (int i = (1); i <= (c3); i++) res = mul(res, c0 + 1 - i);
  f[0] = res;
  for (int i = (1); i <= (c0 + c1); i++) {
    memset(g, 0, sizeof g);
    for (int j = (0); j <= (i); j++) {
      add(g[j + 1], f[j]);
      add(g[j], mul(f[j], i - 1));
    }
    memcpy(f, g, sizeof g);
  }
  for (int i = (1); i <= (c2); i++) {
    memset(g, 0, sizeof g);
    for (int j = (0); j <= (c0 + i); j++) {
      add(g[j + 1], f[j]);
      add(g[j], mul(f[j], i - 1 + c0));
    }
    memcpy(f, g, sizeof g);
  }
  for (int i = (n); i >= (1); i--) printf("%d ", i < bas ? 0 : f[i - bas]);
  return 0;
}

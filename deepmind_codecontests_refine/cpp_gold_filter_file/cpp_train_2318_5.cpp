#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
int n, m, k;
char s[N], t[N];
int S[N], T[N];
int f[N], g[N];
int a[N], b[N];
int pos[N];
int read() {
  int ret = 0;
  char c = getchar();
  while (c < '0' || c > '9') c = getchar();
  while (c >= '0' && c <= '9') {
    ret = (ret << 1) + (ret << 3) + c - '0';
    c = getchar();
  }
  return ret;
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  scanf("%s%s", s, t);
  for (int i = 1; i <= n; ++i) {
    a[i] = read();
    b[i] = read();
    a[i]--;
    b[i]--;
  }
  for (int i = 0; i < k; ++i) S[i] = s[i] - '0';
  for (int i = 0; i < k; ++i) T[i] = t[i] - '0';
  int tot = 0;
  for (int i = 0; i < k; ++i) {
    tot += S[i] * (1 << i);
    pos[i] = i;
  }
  for (int i = 0; i < (1 << k); ++i) {
    f[i] = n + 1;
    g[i] = -1;
  }
  f[tot] = 0;
  for (int i = 1; i <= n; ++i) {
    tot -= (1 << pos[a[i]]) * S[a[i]] + (1 << pos[b[i]]) * S[b[i]];
    swap(pos[a[i]], pos[b[i]]);
    tot += (1 << pos[a[i]]) * S[a[i]] + (1 << pos[b[i]]) * S[b[i]];
    if (f[tot] > i) f[tot] = i;
  }
  for (int i = (1 << k) - 1; i >= 0; --i)
    for (int j = 0; j < k; ++j)
      if (!((1 << j) & i) && f[i ^ (1 << j)] < f[i]) f[i] = f[i ^ (1 << j)];
  tot = 0;
  for (int i = 0; i < k; ++i) {
    tot += T[i] * (1 << i);
    pos[i] = i;
  }
  g[tot] = 0;
  for (int i = 1; i <= n; ++i) {
    tot -= (1 << pos[a[i]]) * T[a[i]] + (1 << pos[b[i]]) * T[b[i]];
    swap(pos[a[i]], pos[b[i]]);
    tot += (1 << pos[a[i]]) * T[a[i]] + (1 << pos[b[i]]) * T[b[i]];
    g[tot] = i;
  }
  for (int i = (1 << k) - 1; i >= 0; --i)
    for (int j = 0; j < k; ++j)
      if (!((1 << j) & i) && g[i ^ (1 << j)] > g[i]) g[i] = g[i ^ (1 << j)];
  int ans = k;
  for (int i = 0; i < k; ++i) ans -= T[i] + S[i];
  int now = 0, L = 1, R = 1;
  for (int i = (1 << k) - 1; i >= 0; --i)
    if (g[i] - f[i] >= m) {
      int cnt = 0;
      for (int j = 0; j < k; ++j)
        if ((1 << j) & i) cnt += 2;
      if (cnt > now) {
        now = cnt;
        L = f[i] + 1;
        R = g[i];
      }
    }
  printf("%d\n", ans + now);
  printf("%d %d\n", L, R);
  return 0;
}

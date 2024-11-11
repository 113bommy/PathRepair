#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int w = 1, s = 0;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    s = s * 10 + ch - '0';
    ch = getchar();
  }
  return w * s;
}
struct node {
  int to, next;
} e[1010010];
int n, m, mod, h[1010010], tot, ind[101010], outd[1011000];
inline long long ksm(long long x, long long y) {
  long long res = 1;
  while (y) {
    if (y & 1) res = res * x % mod;
    x = x * x % mod;
    y >>= 1;
  }
  return res;
}
int mp[660][660], f[100010], d[101010];
inline void add(int from, int to) {
  ind[to]++;
  outd[from]++;
  e[++tot].next = h[from];
  h[from] = tot;
  e[tot].to = to;
}
inline int pls(int a, int b) {
  a += b;
  return a >= mod ? a - mod : a;
}
inline int mns(int a, int b) {
  a -= b;
  return a < 0 ? a + mod : a;
}
queue<int> q;
inline void Gao(int S) {
  memset(f, 0, sizeof(f));
  memcpy(d, ind, sizeof(ind));
  f[S] = 1;
  for (register int i = 1; i <= n; ++i)
    if (!ind[i]) q.push(i);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (register int i = h[u]; i; i = e[i].next) {
      int to = e[i].to;
      d[to]--;
      f[to] = pls(f[to], f[u]);
      if (!d[to]) q.push(to);
    }
  }
}
int cnt = 0;
inline long long Calc() {
  long long res = 1;
  for (register int i = 1; i <= n; ++i) {
    int pos = 0;
    for (register int j = i; j <= n; ++j)
      if (mp[j][i]) pos = j;
    if (!pos) return 0;
    if (pos != i) res = mod - res, swap(mp[pos], mp[i]);
    long long Inv = ksm(mp[i][i], mod - 2);
    for (register int j = i + 1; j <= cnt; ++j) {
      long long t = Inv * mp[j][i] % mod;
      for (register int k = i; k <= cnt; ++k)
        mp[j][k] = mns(mp[j][k], 1ll * t * mp[i][k] % mod);
    }
    res = res * mp[i][i] % mod;
  }
  return res;
}
int main() {
  n = read(), m = read(), mod = read();
  for (register int i = 1; i <= m; ++i) {
    int x = read(), y = read();
    add(x, y);
  }
  cnt = 0;
  for (register int i = 1; i <= n; ++i) {
    if (!ind[i]) {
      ++cnt;
      Gao(i);
      int tot = 0;
      for (register int j = 1; j <= n; ++j)
        if (!outd[j]) mp[cnt][++tot] = f[j];
    }
  }
  cout << Calc();
  return 0;
}

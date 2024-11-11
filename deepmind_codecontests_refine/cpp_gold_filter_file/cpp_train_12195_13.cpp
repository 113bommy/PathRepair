#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
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
} e[1000010];
int col[500100], f[500010][2], n, fa[500010], tot, h[500010], Col[500100],
    tong[500010], dep[500010], K;
priority_queue<pair<int, int> > q;
inline void add(int from, int to) {
  e[++tot].next = h[from];
  h[from] = tot;
  e[tot].to = to;
}
inline long long ksm(long long x, long long y) {
  long long res = 1;
  while (y) {
    if (y & 1) res = res * x % mod;
    x = x * x % mod;
    y >>= 1;
  }
  return res;
}
inline int Add(int a, int b) {
  a += b;
  return a >= mod ? a - mod : a;
}
inline void DFS1(int now, int ffa) {
  dep[now] = dep[ffa] + 1;
  fa[now] = ffa;
  for (register int i = h[now]; i; i = e[i].next) {
    int to = e[i].to;
    if (to == ffa) continue;
    DFS1(to, now);
  }
}
inline void DFS2(int now, int ffa) {
  for (register int i = h[now]; i; i = e[i].next) {
    int to = e[i].to;
    if (to == ffa) continue;
    DFS2(to, now);
  }
  if (Col[now]) {
    f[now][0] = 0;
    f[now][1] = 1;
    for (register int i = h[now]; i; i = e[i].next) {
      int to = e[i].to;
      if (to == ffa) continue;
      f[now][1] = 1ll * f[now][1] * Add(f[to][1], f[to][0]) % mod;
    }
  } else {
    f[now][0] = 1;
    long long res = 1;
    for (register int i = h[now]; i; i = e[i].next) {
      int to = e[i].to;
      if (to == ffa) continue;
      res = res * Add(f[to][0], f[to][1]) % mod;
    }
    f[now][0] = res;
    for (register int i = h[now]; i; i = e[i].next) {
      int to = e[i].to;
      if (to == ffa) continue;
      f[now][1] = Add(f[now][1], res * ksm(Add(f[to][0], f[to][1]), mod - 2) %
                                     mod * f[to][1] % mod);
    }
  }
}
int main() {
  n = read();
  K = read();
  for (register int i = 1; i <= n; ++i) Col[i] = read();
  for (register int i = 1; i < n; ++i) {
    int x = read(), y = read();
    add(x, y);
    add(y, x);
  }
  DFS1(1, 0);
  for (register int i = 1; i <= n; ++i)
    if (Col[i]) q.push(make_pair(dep[i], i)), tong[Col[i]]++;
  while (!q.empty()) {
    pair<int, int> tmp = q.top();
    q.pop();
    int u = tmp.second;
    if (!fa[u]) {
      break;
    }
    if (Col[u] == Col[fa[u]])
      tong[Col[u]]--;
    else {
      if (tong[Col[u]] != 1) {
        if (Col[fa[u]]) {
          cout << 0;
          exit(0);
        }
        Col[fa[u]] = Col[u];
        q.push(make_pair(dep[fa[u]], fa[u]));
      }
    }
  }
  DFS2(1, 0);
  cout << f[1][1];
  return 0;
}

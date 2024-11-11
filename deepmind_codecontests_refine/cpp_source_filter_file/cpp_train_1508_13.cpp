#include <bits/stdc++.h>
using namespace std;
inline char gc() {
  static char now[1 << 16], *S, *T;
  if (T == S) {
    T = (S = now) + fread(now, 1, 1 << 16, stdin);
    if (T == S) return EOF;
  }
  return *S++;
}
inline int read() {
  int x = 0;
  char ch = gc();
  while (ch < '0' || ch > '9') ch = gc();
  while (ch <= '9' && ch >= '0') {
    x = x * 10 + ch - '0';
    ch = gc();
  }
  return x;
}
struct node {
  int y, z, next, x;
} data[220 * 220];
int num = 1, prime[11000], h[220], T, n, level[220], age[220];
bool not_prime[11000], visit[220];
vector<int> print[220];
inline void insert1(int x, int y, int z) {
  data[++num].y = y;
  data[num].z = z;
  data[num].next = h[x];
  h[x] = num;
  data[num].x = x;
  data[++num].y = x;
  data[num].z = 0;
  data[num].next = h[y];
  h[y] = num;
  data[num].x = y;
}
inline bool bfs() {
  queue<int> q;
  memset(level, 0, sizeof(level));
  level[0] = 1;
  q.push(0);
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (int i = h[x]; i; i = data[i].next) {
      int y = data[i].y, z = data[i].z;
      if (level[y] || !z) continue;
      level[y] = level[x] + 1;
      q.push(y);
      if (y == T) return 1;
    }
  }
  return 0;
}
inline int dfs(int x, int s) {
  if (x == T) return s;
  int ss = s;
  for (int i = h[x]; i; i = data[i].next) {
    int y = data[i].y, z = data[i].z;
    if (level[x] + 1 == level[y] && z) {
      int xx = dfs(y, min(s, z));
      if (!x) level[y] = 0;
      s -= xx;
      data[i].z -= xx;
      data[i ^ 1].z += xx;
      if (!s) return ss;
    }
  }
  return ss - s;
}
inline void dfs1(int x, int id, int op) {
  print[id].push_back(x);
  visit[x] = 1;
  for (int i = h[x]; i; i = data[i].next) {
    int y = data[i].y, z = data[i].z;
    if (visit[y]) continue;
    if ((i ^ op) == 0) continue;
    if (z ^ op) dfs1(y, id, op ^ 1);
  }
}
int main() {
  n = read();
  T = n + 1;
  int odd = 0, even = 0;
  for (int i = 1; i <= n; ++i) {
    age[i] = read();
    if (age[i] % 2)
      insert1(0, i, 2), ++odd;
    else
      insert1(i, T, 2), ++even;
  }
  int tot = 0;
  if (odd != even) {
    printf("Impossible");
    return 0;
  }
  for (int i = 2; i <= 10000; ++i) {
    if (!not_prime[i]) prime[++tot] = i;
    for (int j = 1; prime[j] * i <= 1e4; ++j) {
      not_prime[prime[j] * i] = 1;
      if (i % prime[j] == 0) break;
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (age[i] % 2 == 0) continue;
    for (int j = 1; j <= n; ++j) {
      if (i == j) continue;
      int sum = age[i] + age[j];
      if (!not_prime[sum]) {
        insert1(i, j, 1);
      }
    }
  }
  int ans = 0;
  while (bfs()) ans += dfs(0, 0x3f3f3f3f);
  if (ans != n) {
    printf("Impossible");
    return 0;
  }
  tot = 0;
  visit[0] = 1;
  visit[T] = 1;
  for (int i = h[0]; i; i = data[i].next) {
    int y = data[i].y;
    if (!visit[y]) dfs1(y, ++tot, 1);
  }
  printf("%d\n", tot);
  for (int i = 1; i <= tot; ++i) {
    printf("%d ", print[i].size());
    for (int j = 0; j < print[i].size(); ++j) printf("%d ", print[i][j]);
    printf("\n");
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int BUFFER_SIZE = 1 << 20;
char rb[BUFFER_SIZE], *rp = rb, *rt = rb;
inline char read_char() {
  return rp == rt ? (rt = rb + fread(rb, 1, BUFFER_SIZE, stdin), rp = rb, *rp++)
                  : *rp++;
}
inline int read_int() {
  int x = 0;
  char ch = read_char(), flag = 0;
  while (ch != '-' && (ch < '0' || ch > '9')) {
    ch = read_char();
  }
  if (ch == '-') {
    flag = 1;
    ch = read_char();
  }
  for (x = 0; ch >= '0' && ch <= '9'; ch = read_char()) {
    x = x * 10 + (ch - '0');
  }
  return flag ? -x : x;
}
const int MAX_N = 200000 + 5;
int N, n[2], siz[MAX_N];
int ey[MAX_N << 1], enext[MAX_N << 1], elast[MAX_N];
void dp(int u, int fa, int dep) {
  n[dep & 1]++;
  siz[u] = 1;
  for (int j = elast[u]; j; j = enext[j]) {
    int v = ey[j];
    if (v != fa) {
      dp(v, u, dep ^ 1);
      siz[u] += siz[v];
    }
  }
}
int main() {
  N = read_int();
  for (int i = 1, j = 1; i < N; i++) {
    int x = read_int();
    int y = read_int();
    ey[j] = y;
    enext[j] = elast[x];
    elast[x] = j++;
    ey[j] = x;
    enext[j] = elast[y];
    elast[y] = j++;
  }
  dp(1, 0, 0);
  long long ans = 0;
  for (int i = 1; i <= N; i++) {
    ans += 1ll * siz[i] * (N - siz[i]);
  }
  ans += 1ll * n[0] * n[1];
  printf("%lld\n", ans >> 1);
  return 0;
}

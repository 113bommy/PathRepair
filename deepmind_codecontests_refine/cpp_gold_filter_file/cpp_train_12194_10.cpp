#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:102400000,102400000")
long long mul(long long a, long long b) { return (a * b) % (1000000007); }
long long add(long long a, long long b) { return (a + b) % (1000000007); }
long long sub(long long a, long long b) {
  return ((a - b) % (1000000007) + (1000000007)) % (1000000007);
}
void upd(long long &a, long long b) {
  a = (a % (1000000007) + b % (1000000007)) % (1000000007);
}
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int n, q;
bitset<7001> g[7001], g2[7001], p;
bitset<7001> h[(101010)];
int wq[7001];
int main() {
  n = read(), q = read();
  int M = 7000;
  for (int i = 2; i * i <= M; i++) {
    int t = i * i;
    for (int j = 1; j * t <= M; j++) wq[t * j] = 1;
  }
  for (int i = 1; i <= 7000; i++) g[i].reset(), g2[i].reset();
  for (int i = 1; i <= 7000; i++) {
    for (int j = 1; j <= i; j++) {
      if (i % j == 0) {
        g[i].set(j);
        if (!wq[i / j]) g2[j].set(i);
      }
    }
  }
  for (int i = 1; i <= n; i++) h[i].reset();
  for (int i = 1; i <= q; i++) {
    int op = read();
    if (op == 1) {
      int x = read(), v = read();
      h[x] = g[v];
    }
    if (op == 2) {
      int x = read(), y = read(), z = read();
      h[x] = h[y] ^ h[z];
    } else if (op == 3) {
      int x = read(), y = read(), z = read();
      h[x] = h[y] & h[z];
    } else if (op == 4) {
      int x = read(), v = read();
      p = h[x] & g2[v];
      int q = p.count() % 2;
      printf("%d", q);
    }
  }
  return 0;
}

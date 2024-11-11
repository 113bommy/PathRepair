#include <bits/stdc++.h>
using namespace std;
const int inf = 0x20202020;
const long long mod = 1000000007;
const double eps = 1e-9;
const double pi = 3.1415926535897932384626;
const int DX[] = {1, 0, -1, 0}, DY[] = {0, 1, 0, -1};
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= mod;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
long long powmod(long long a, long long b, long long mod) {
  long long res = 1;
  a %= mod;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
int ans = -inf;
int g[40][40], s[20][2], x, n;
inline int G(int x, int i, int j) { return x ? -g[i][j] : g[i][j]; }
int main() {
  scanf("%d", &n);
  for (int i = 0; i < (int)n; i++)
    for (int j = 0; j < (int)n; j++) scanf("%d", &g[i][j]);
  x = (n + 1) / 2;
  for (int S = 0; S < (int)(1 << (x)); S++) {
    int al = (S >> (x - 1)) & 1, sm = G(al, x - 1, x - 1);
    for (int i = 0; i < (int)x - 1; i++)
      for (int j = 0; j < (int)2; j++)
        s[i][j] = G(j, i, x - 1) + G(j ^ al, i + x, x - 1);
    for (int i = 0; i < (int)x - 1; i++)
      sm += G((S >> i) & 1, x - 1, i) + G(((S >> i) & 1) ^ al, x - 1, i + x);
    for (int i = 0; i < (int)x - 1; i++)
      for (int j = 0; j < (int)x - 1; j++)
        for (int sr = 0; sr < (int)2; sr++) {
          int sc = (S >> i) & 1;
          s[i][sr] += abs(G(0, i, j) + G(sr, i, j + x) + G(sc, i + x, j) +
                          G(sr ^ sc ^ al, i + x, j + x));
        }
    for (int i = 0; i < (int)x - 1; i++) sm += max(s[i][0], s[i][1]);
    ans = max(ans, sm);
  }
  printf("%d\n", ans);
}

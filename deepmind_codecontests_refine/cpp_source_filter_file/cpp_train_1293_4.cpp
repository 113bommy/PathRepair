#include <bits/stdc++.h>
const int mod = 1e9 + 7;
const int maxn = 1e2 + 5;
const double eps = 1e-6;
using namespace std;
bool eq(const double &a, const double &b) { return fabs(a - b) < eps; }
bool ls(const double &a, const double &b) { return a + eps < b; }
bool le(const double &a, const double &b) { return eq(a, b) || ls(a, b); }
long long gcd(long long a, long long b) { return a == 0 ? b : gcd(b % a, a); };
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
long long kpow(long long a, long long b) {
  long long res = 1;
  a %= mod;
  if (b < 0) return 1;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int mp[maxn][maxn] = {0};
int k;
void add(int a, int b) { mp[a][b] = mp[b][a] = 1; }
void init() {
  add(1, 3);
  add(1, 4);
  add(100, 2);
  for (int i = 3; i < (60); i += 2) {
    add(i, i + 2);
    add(i, i + 3);
    add(i + 1, i + 2);
    add(i + 1, i + 3);
  }
  for (int i = 62; i < (100); ++i) add(i, i + 1);
}
void solve() {
  scanf("%d", &k);
  for (int i = 30; i >= (1); --i) {
    if (k >= (1 << i)) {
      k -= (1 << i);
      add(2 * i + 1, 62 + i);
      add(2 * i + 2, 62 + i);
    }
  }
  if (k) add(1, 62);
  printf("100\n");
  for (int i = 1; i < (101); ++i) {
    for (int j = 1; j < (101); ++j) printf("%c", mp[i][j] ? 'Y' : 'N');
    puts("");
  }
}
int main() {
  init();
  solve();
  return 0;
}

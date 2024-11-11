#include <bits/stdc++.h>
using namespace std;
template <class T>
void chkmin(T &x, T y) {
  if (y < x) x = y;
}
template <class T>
void chkmax(T &x, T y) {
  if (y > x) x = y;
}
void read(long long &x) {
  x = 0;
  register char ch = getchar();
  while (!isdigit(ch)) ch = getchar();
  while (isdigit(ch)) x = x * 10 + (ch ^ 48), ch = getchar();
}
void write(unsigned int x) {
  if (x > 9) write(x / 10);
  putchar(x % 10 ^ 48);
}
const unsigned int MOD = 1000000007;
unsigned int mo(unsigned int x) { return x >= MOD ? x - MOD : x; }
void pluseq(unsigned int &x, unsigned int y) { x = mo(x + y); }
long long m;
unsigned int f[8], ff[8];
void solve() {
  memset(f, 0, sizeof(f));
  f[0] = 1;
  read(m);
  for (int i = 59; i >= (0); i--) {
    for (int i = 0; i <= (3); i++)
      ff[i << 1] = (f[i] + f[i + 1] + f[i + 2] + f[i + 3]) % MOD;
    if (m >> i & 1)
      for (int i = 0; i <= (3); i++) ff[i << 1 | 1] = ff[i << 1];
    else {
      for (int i = 0; i <= (2); i++) ff[i << 1 | 1] = ff[i + 1 << 1];
      ff[7] = (f[4] + f[5] + f[6] + f[7]) % MOD;
    }
    memcpy(f, ff, 32);
  }
  write(f[0]);
  putchar('\n');
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) solve();
}

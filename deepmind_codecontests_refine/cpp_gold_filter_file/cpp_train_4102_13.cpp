#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long sum = 0, f = 0;
  char ch = getchar();
  while (!isdigit(ch)) f |= (ch == '-'), ch = getchar();
  while (isdigit(ch)) sum = (sum << 1) + (sum << 3) + (ch ^ 48), ch = getchar();
  return f ? -sum : sum;
}
void write(const long long x) {
  if (x < 0) {
    putchar('-');
    write(-x);
    return;
  }
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
const long long mod = 1e9 + 7;
long long f[1000007];
void init() {
  f[0] = f[1] = 1;
  for (register long long i = (2); i <= (1e6); i++)
    f[i] = f[i - 2] * (i - 1) + f[i - 1], f[i] %= mod;
}
void solve() {
  long long ans = 1, n, cnt = 0;
  n = read();
  for (register long long i = (1); i <= (n); i++)
    if (read() == 1) cnt++;
  for (register long long i = (cnt + 1); i <= (n); i++) ans = ans * i % mod;
  write(ans * f[cnt] % mod), puts("");
}
int main() {
  init();
  solve();
}

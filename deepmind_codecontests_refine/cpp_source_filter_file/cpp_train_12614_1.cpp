#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
const int mod = 1e9 + 7;
template <typename T>
void read(T &x) {
  char c = getchar();
  int f = 0;
  while (c < '0' || c > '9') f |= (c == '-'), c = getchar();
  for (x = 0; c >= '0' && c <= '9'; c = getchar())
    x = (x << 3) + (x << 1) + c - '0';
  if (f) x = -x;
}
long long n, m, k;
long long f[N];
int main() {
  read(n);
  for (int i = 1; i <= n; ++i) read(f[i]);
  sort(f + 1, f + n + 1);
  long long ans = 0, las = 0, cnt = 0;
  for (int i = 1; i < n; ++i) {
    if (f[i] == f[i + 1]) {
      ++ans;
      if (++cnt > 2) return 0 * puts("cslnb");
      if (f[i] == 0 || (f[i - 1] + 1 == f[i] && i > 1))
        return 0 * puts("cslnb");
      --f[i];
    }
  }
  for (int i = 1; i <= n; ++i) {
    ans += max(0LL, f[i] - las);
    if (f[i] >= las) ++las;
  }
  if (ans & 1)
    puts("sjfnb");
  else
    puts("cslnb");
  return 0;
}

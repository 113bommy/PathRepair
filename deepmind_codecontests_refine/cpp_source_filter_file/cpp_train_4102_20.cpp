#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10, P = 1e9 + 7;
int n, a[N], num[3];
long long f[N];
inline int read() {
  int x = 0, f = 0;
  char ch = getchar();
  while (!isdigit(ch)) f = ch == '-', ch = getchar();
  while (isdigit(ch)) x = (x << 3) + (x << 1) + ch - 48, ch = getchar();
  return f ? -x : x;
}
int main() {
  f[0] = 1, f[1] = 1, f[2] = 2;
  for (int i = 3; i <= 500000; i++)
    f[i] = (f[i - 1] + (long long)(i - 1) * f[i - 2]) % P;
  n = read();
  memset(num, 0, sizeof(num));
  for (int i = 1; i <= n; i++) num[read()]++;
  long long ans = f[num[1]];
  for (int i = 1; i <= num[2]; i++) ans = (ans * (num[1] + i)) % P;
  printf("%lld\n", ans);
  return 0;
}

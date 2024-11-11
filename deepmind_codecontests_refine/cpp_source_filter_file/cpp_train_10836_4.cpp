#include <bits/stdc++.h>
using namespace std;
const long long p = 998244353;
inline long long read() {
  long long neg = 1, num = 0;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') neg = -1;
  for (; isdigit(c); c = getchar()) num = (num << 1) + (num << 3) + c - '0';
  return neg * num;
}
long long n, a[2000010], s[2000010], ans[2000010];
signed main() {
  n = read();
  for (long long i = 1; i <= n; i++) s[i] = s[i - 1] + read();
  ans[n] = 1;
  ans[n - 1] = 2;
  long long inv = 1;
  for (long long i = n - 2; i >= 1; i--) {
    ans[i] = ans[i + 1] * 2 % p + inv;
    ans[i] %= p;
    inv = inv * 2 % p;
  }
  long long sum = 0;
  for (long long i = 1; i <= n; i++) sum = (sum + s[i] * ans[i] % p) % p;
  printf("%lld", sum);
  return 0;
}

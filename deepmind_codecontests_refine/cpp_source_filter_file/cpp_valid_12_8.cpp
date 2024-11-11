#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#pragma GCC optimize(2)
using namespace std;
const int maxn = 2e5 + 1010;
const int mod = 1e9 + 7;
const int MOD = 10007;
inline int read() {
  int x = 0;
  bool t = false;
  char ch = getchar();
  while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
  if (ch == '-') t = true, ch = getchar();
  while (ch <= '9' && ch >= '0') x = x * 10 + ch - 48, ch = getchar();
  return t ? -x : x;
}
long long n, m, k;
void solve() {
  scanf("%lld%lld%lld", &n, &m, &k);
  if ((k == 0 && n % 2 == 0) || (k * 2 == n * m && m % 2 == 0)) {
    puts("Yes");
    return;
  }
  if ((k == 0 && n % 2 == 1) || (k * 2 == n * m && m % 2 == 1)) {
    puts("No");
    return;
  }
  if (n == 1 || m == 1) {
    puts("No");
    return;
  }
  if (n % 2 == 1) {
    long long num = m / 2;
    if (k < num)
      puts("No");
    else {
      n--;
      k -= num;
      if (k % 2)
        puts("No");
      else
        puts("Yes");
    }
  } else if (m % 2 == 1) {
    long long sum = n * m / 2;
    long long num = n / 2;
    long long res = sum - num;
    if (k % 2 || res > k)
      puts("No");
    else
      puts("Yes");
  } else {
    if (k % 2)
      puts("No");
    else
      puts("Yes");
  }
}
int main() {
  long long t = 1;
  scanf("%lld", &t);
  while (t--) {
    solve();
  }
  return 0;
}

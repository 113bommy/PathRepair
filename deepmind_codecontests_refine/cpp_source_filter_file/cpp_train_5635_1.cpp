#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long M = 1e8;
const long long N = 1e5 + 5;
long long n, k;
long long a[N], b[N];
void init() {
  a[1] = 2;
  b[1] = 1;
  for (long long i = 2; i <= 32; i++) {
    a[i] = a[i - 1] * 2;
    b[i] = b[i - 1] * 4;
    a[i - 1] += a[i - 2] - 1;
    b[i - 1] += b[i - 2];
  }
}
void solve() {
  cin >> n >> k;
  if (n > 31) {
    printf("YES %lld\n", n - 1);
    return;
  }
  if (k > a[n]) {
    puts("NO");
    return;
  }
  long long flag = 0;
  for (long long i = 1; i <= n; i++)
    if (k >= a[i] && k <= a[i] + a[n - i] * ((1 << i) - 1) * ((1 << i) - 1)) {
      flag = i;
      break;
    }
  if (!flag)
    puts("NO");
  else
    printf("YES %lld\n", n - flag);
}
signed main() {
  init();
  long long T = 1;
  cin >> T;
  for (long long index = 1; index <= T; index++) {
    solve();
  }
  return 0;
}

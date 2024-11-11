#include <bits/stdc++.h>
using namespace std;
long long read() {
  char x = getchar();
  long long ans = 0, flag = 1;
  while (!isdigit(x))
    if (x == '-')
      flag = -1, x = getchar();
    else
      x = getchar();
  while (isdigit(x)) ans = ans * 10 + x - '0', x = getchar();
  return ans * flag;
}
long long n, a[100005], b[100005];
signed main() {
  long long T = read();
  while (T--) {
    n = read();
    for (long long i = 1; i <= n; i++) a[i] = read();
    b[0] = -2000000000;
    for (long long i = 1; i <= n; i++) b[i] = max(b[i - 1], a[i]);
    long long tmp = 0;
    for (long long i = 1; i <= n; i++) {
      tmp = max(tmp, b[i] - a[i]);
    }
    if (!tmp) {
      puts("0");
      continue;
    }
    for (long long i = 0; i <= 32; i++) {
      if ((1ll << (i + 1)) > tmp) {
        cout << i + 1 << '\n';
        break;
      }
    }
  }
  return 0;
}

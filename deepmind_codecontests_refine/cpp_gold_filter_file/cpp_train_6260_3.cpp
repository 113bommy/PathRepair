#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 3e5 + 10;
long long read() {
  long long f = 1, a = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') {
      f = -f;
    }
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    a = a * 10 + ch - '0';
    ch = getchar();
  }
  return a * f;
}
long long n, ans;
long long q[2][MAXN], tot[2], a[MAXN], num[MAXN];
signed main() {
  n = read();
  for (long long i = 1; i <= n; ++i) {
    a[i] = read();
  }
  for (long long i = 1; i <= n; ++i) {
    num[i] = num[i - 1] ^ a[i];
    q[i & 1][++tot[i & 1]] = num[i];
  }
  sort(q[1] + 1, q[1] + tot[1] + 1);
  sort(q[0] + 1, q[0] + tot[0] + 2);
  for (long long t = 0; t <= 1; ++t) {
    for (long long i = 1; i <= tot[t]; ++i) {
      long long x = q[t][i], ii = 1;
      while (q[t][i + 1] == x && i <= tot[t]) {
        i++, ii++;
      }
      ans += ii * (ii - 1) / 2;
    }
  }
  cout << ans << endl;
  return 0;
}

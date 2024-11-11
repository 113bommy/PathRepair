#include <bits/stdc++.h>
using namespace std;
const long long mod = 9901;
const double eps = 1e-8;
const long long INF = 0x3f3f3f3f;
const long long maxn = 1e5 + 5;
const long long maxm = 1e6 + 5;
long long n, m, ans, sum;
string s[55];
inline long long read();
signed main() {
  n = read(), m = read() / 2;
  for (long long i = 1; i <= n; ++i) {
    getline(cin, s[i]);
  }
  for (long long i = n; i; --i) {
    if (s[i] == "halfplus") sum++;
    ans += sum, sum *= 2;
  }
  printf("%d\n", ans * m);
  return 0;
}
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
  return x * f;
}

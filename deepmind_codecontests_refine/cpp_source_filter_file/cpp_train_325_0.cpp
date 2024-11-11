#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const long long MOD = 1e9 + 7;
const long long MAXN = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const long long ll_INF = 9223372036854775807;
long long qm(long long a, long long b) {
  long long ret = 1;
  while (b) {
    if (b & 1) ret = ret * a % MOD;
    a = a * a % MOD;
    b >>= 1;
  }
  return ret;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
int n, x, y;
char s[MAXN];
int main() {
  scanf("%d%d%d", &n, &x, &y);
  getchar();
  scanf("%s", s + 1);
  int ans = 0;
  for (int i = n; i >= n - x; i--) {
    if (i != (n - y) && i != (n - x)) {
      if (s[i] == '1') ans++;
    } else {
      if (s[i] != '1') ans++;
    }
  }
  printf("%d", ans);
  return 0;
}

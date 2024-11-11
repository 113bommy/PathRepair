#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const double eps = 1e-9;
const double pi = acos(0) * 2;
long long powmod(long long a, long long b) {
  long long res = 1;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
long long powmod(long long a, long long b, long long mod) {
  long long res = 1;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
struct RE {
  long long v, mark;
} aa[100005];
int n, a[100005], b[100005], c[100005], tmp, bn, cn, cnt, k, p;
inline bool cmp(RE a, RE b) { return a.mark < b.mark; }
int main() {
  scanf("%d%d%d", &n, &k, &p);
  p = k - p;
  bn = 0;
  cn = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%Id", a + i);
    if (a[i] % 2 == 1)
      b[++bn] = a[i];
    else
      c[++cn] = a[i];
  }
  if (bn < p || (bn - p) % 2 == 1 || cn + (bn - p) / 2 < k - p) {
    puts("NO");
    return 0;
  } else
    puts("YES");
  int i;
  for (i = 1; i < k && i <= p; i++) printf("1 %d\n", b[bn--]);
  for (; i < k && bn > 0; i++, bn -= 2) printf("2 %d %d\n", b[bn], b[bn - 1]);
  for (; i < k && cn > 0; i++, cn -= 1) printf("1 %d\n", c[cn]);
  if (bn + cn > 0) {
    printf("%d", bn + cn);
    while (bn) printf(" %d", b[bn--]);
    while (cn) printf(" %d", c[cn--]);
    puts("");
  }
  return 0;
}

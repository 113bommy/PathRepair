#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const long long MOD = 998244353;
const int MAXN = 1e4 + 10;
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
int n;
int a[MAXN];
int num[MAXN];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  memset(num, 0, sizeof(num));
  for (int i = 1; i <= n; i++) {
    if (a[i] == 4)
      num[4]++;
    else if (a[i] == 8)
      num[8] = min(num[8] + 1, num[4]);
    else if (a[i] == 15)
      num[15] = min(num[15] + 1, num[8]);
    else if (a[i] == 16)
      num[16] = min(num[16] + 1, num[15]);
    else if (a[i] == 23)
      num[23] = min(num[23] + 1, num[16]);
    else
      num[42] = min(num[42] + 1, num[23]);
  }
  int cnt = num[42];
  printf("%d\n", n - cnt * 6);
  return 0;
}

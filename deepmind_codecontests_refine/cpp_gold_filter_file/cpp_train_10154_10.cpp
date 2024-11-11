#include <bits/stdc++.h>
using namespace std;
const long long N = 5e5 + 5;
long long a[N], b[N], c[N];
bool over[N];
bool can[N];
long long n;
long long s;
long long have;
long long len = 61;
bool pos = true;
map<long long, long long> dp[N];
int main() {
  scanf("%I64d", &n);
  for (long long i = 1; i <= n; i++) {
    scanf("%I64d %I64d", &a[i], &b[i]);
    c[i] = (a[i] ^ b[i]);
    s ^= a[i];
  }
  for (long long i = len; i >= 0; i--) {
    long long j = -1;
    for (j = 1; j <= n; j++) {
      if (((c[j] >> i) & 1) and !over[j]) break;
    }
    if (j == n + 1) continue;
    over[j] = true;
    for (long long k = 1; k <= n; k++) {
      if (k == j or !((c[k] >> i) & 1)) continue;
      c[k] ^= c[j];
    }
  }
  for (long long i = 1; i <= n; i++) {
    if (c[i] == 0) have++;
  }
  for (long long i = 0; i <= len; i++) {
    if (!((s >> i) & 1)) continue;
    for (long long j = 1; j <= n; j++) {
      if (((c[j] >> i) & 1)) s ^= c[j];
    }
  }
  if (s) {
    printf("1/1\n");
    return 0;
  }
  long long num = pow(2ll, n - have) - 1ll;
  long long den = pow(2ll, n - have);
  printf("%I64d/%I64d\n", num, den);
}

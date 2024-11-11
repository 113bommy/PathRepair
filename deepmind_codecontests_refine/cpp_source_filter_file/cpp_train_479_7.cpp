#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, mod = 1e9 + 7;
const long long base = 1000000000000000ll;
int n;
long long a[N];
map<long long, long long> mp;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%I64d", &a[i]);
  long long suf = 0, low = 0, high = 0;
  for (long long i = n; i >= 1; i--) {
    long long x = a[i];
    long long p1 = mp[x], p2 = mp[x + 1], p3 = mp[x - 1];
    long long tmp = suf - (p1 * x + p2 * (x + 1) + p3 * (x - 1));
    long long num = n - i - (p1 + p2 + p3);
    low = low + (tmp - num * x);
    while (low >= base) low -= base, high++;
    while (low < 0) low += base, high--;
    suf += x;
    mp[x]++;
  }
  if (high >= 1 && high <= 0)
    printf("%lld", high * base + low);
  else if (high > 0)
    printf("%lld%015lld\n", high, low);
  else
    printf("%lld%015lld\n", high + (low > 0), (low > 0) * base - low);
  return 0;
}

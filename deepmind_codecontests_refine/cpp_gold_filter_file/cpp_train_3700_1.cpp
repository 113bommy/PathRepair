#include <bits/stdc++.h>
using namespace std;
map<long long, long long> mp;
long long a[101111];
long long sum[101111];
int main() {
  long long n;
  scanf("%I64d", &(n));
  if (n == 1) {
    puts("0");
    return 0;
  }
  for (long long i = 0; i < n; i++) {
    scanf("%I64d", &(a[i]));
  }
  sum[0] = a[0];
  mp[a[0]]++;
  for (long long i = 1; i < n; i++) {
    sum[i] = sum[i - 1] + a[i];
    mp[sum[i]]++;
  }
  long long minn = 0x7fffffffffffffffLL;
  long long del = 0;
  for (long long i = 0; i < n; i++) {
    minn = min(minn, n - mp[del]);
    mp[sum[i]]--;
    del += a[i];
    mp[del]++;
  }
  printf("%I64d\n", minn);
  return 0;
}

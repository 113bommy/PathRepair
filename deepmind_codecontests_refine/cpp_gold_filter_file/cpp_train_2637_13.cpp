#include <bits/stdc++.h>
using namespace std;
long long a[3013] = {0}, dp[3013][3013];
string s[123];
int main() {
  map<string, long long> map1;
  long long n, m;
  scanf("%lld", &n);
  for (long long i = 1; i <= n; i++) {
    scanf("%lld", &m);
    a[m]++;
  }
  long long sum = a[4] + a[3] + a[2] / 2;
  a[1] -= min(a[1], a[3]);
  long long t = a[2] % 2;
  if (t == 1) {
    sum++;
    a[1] = a[1] - min(a[1], (long long)2);
  }
  sum += (a[1] + 3) / 4;
  printf("%lld\n", sum);
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-8;
const int N = 2e5 + 10;
const int M = 1e6 + 10;
long long dp1[N];
long long dp2[N];
void run() {
  long long n, m;
  scanf("%lld%lld", &n, &m);
  dp1[1] = 1;
  for (int i = 1; i <= n; i++) {
    dp2[i] = 1;
  }
  for (int i = 2, sum = 1; i <= n; i++) {
    dp2[i] = (dp2[i] + dp2[i - 1]) % m;
    dp1[i] = (dp2[i] + sum) % m;
    dp1[i] = (dp1[i] - dp1[i - 1] + m) % m;
    sum = (sum + dp1[i]) % m;
    long long now = (dp1[i] - dp1[i - 1] + m) % m;
    for (int j = i; j <= n; j += i) dp2[j] = (dp2[j] + now) % m;
  }
  printf("%lld\n", dp1[n]);
}
int main() {
  run();
  return 0;
}

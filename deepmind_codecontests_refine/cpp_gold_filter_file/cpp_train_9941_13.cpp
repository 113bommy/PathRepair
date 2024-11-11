#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9 + 7, maxc = 1e3 + 1;
long long int fact[maxc * maxc], rfact[maxc], rop[maxc * maxc];
long long int modi(long long int a, long long int b) {
  if (b == 0) return 1;
  if (b == 1) return a % mod;
  long long int h = modi(a, b / 2);
  return (((h * h) % mod) * modi(a, b % 2)) % mod;
}
long long int arr[maxc];
long long int ans = 1;
void mohasebeh(int i, long long int &sum) {
  ans = (ans * rop[sum]) % mod;
  ans = (ans * arr[i]) % mod;
  sum -= arr[i];
}
int main() {
  fact[0] = 1;
  for (long long int i = 1; i < maxc * maxc; i++)
    fact[i] = (fact[i - 1] * i) % mod;
  for (long long int i = 0; i < maxc; i++) rfact[i] = modi(fact[i], mod - 2);
  rop[0] = 1;
  for (long long int i = 1; i < maxc * maxc; i++) rop[i] = modi(i, mod - 2);
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%I64d", arr + i);
  long long int sum = 0;
  for (int i = 0; i < n; i++) sum += arr[i];
  ans = fact[sum];
  for (int i = 0; i < n; i++) ans = (ans * rfact[arr[i]]) % mod;
  for (int i = n - 1; i > 0; i--) mohasebeh(i, sum);
  printf("%I64d", ans);
}

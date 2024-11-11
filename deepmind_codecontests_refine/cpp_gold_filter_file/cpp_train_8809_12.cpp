#include <bits/stdc++.h>
using namespace std;
long long n, a[1000001], b[1000001], f[1000001], s[26];
string A, B;
long long qow(long long x, long long y) {
  return y ? (y & 1 ? x * qow(x, y - 1) % 1000000007
                    : qow(x * x % 1000000007, y / 2))
           : 1;
}
void pretype() {
  f[0] = 1;
  for (long long i = 1; i < 1000001; i++) f[i] = f[i - 1] * i % 1000000007;
}
long long cal(long long x[]) {
  long long ans = 0, k = 1, sum, re[26];
  for (long long i = 0; i < 26; i++) re[i] = s[i];
  for (long long i = 1; i <= n; i++) {
    sum = 0;
    for (long long j = 0; j < x[i]; j++) sum += re[j];
    ans += sum * f[n - i] % 1000000007 * k % 1000000007;
    ans %= 1000000007;
    if (!re[x[i]]) break;
    k *= re[x[i]], k %= 1000000007;
    re[x[i]]--;
  }
  for (int i = 0; i < 26; i++)
    ans *= qow(f[s[i]], 1000000007 - 2), ans %= 1000000007;
  return ans;
}
int main() {
  pretype();
  cin >> A;
  cin >> B;
  n = A.size();
  if (A >= B) return printf("0\n"), 0;
  for (long long i = 1; i <= n; i++) a[i] = A[i - 1] - 'a', s[a[i]]++;
  for (long long i = 1; i <= n; i++) b[i] = B[i - 1] - 'a';
  return printf("%I64d\n", (cal(b) - cal(a) + 1000000007 - 1) % 1000000007), 0;
}

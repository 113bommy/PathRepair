#include <bits/stdc++.h>
using namespace std;
const int MAXN = 509;
const int MD = 1e9 + 7;
int arr[MAXN];
const int NCR_MAX = 509;
long long fact[32600], invFact[32600];
long long modPow(long long n, long long k, int MOD) {
  long long r = 1;
  while (k) {
    if (k & 1) {
      r = (r * n) % MOD;
    }
    n = (n * n) % MOD;
    k >>= 1;
  }
  return r % MOD;
}
void preCalc(int till_3) {
  fact[0] = 1LL;
  for (int i = 1; i <= till_3; i++) {
    fact[i] = (fact[i - 1] * i) % MD;
  }
  invFact[till_3] = modPow(1LL * fact[till_3], 1LL * (MD - 2), MD);
  for (int i = till_3 - 1; i >= 0; i--) {
    invFact[i] = ((i + 1) * invFact[i + 1]) % MD;
  }
}
long long C(int n, int r) {
  if (r > n) return 0LL;
  return (fact[n] * invFact[r] % MD * invFact[n - r] % MD);
}
map<long long, long long> factors;
int main(int argc, char const *argv[]) {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  preCalc(32599);
  for (int i = 0; i < n; i++) {
    for (int j = 2; 1LL * j * j <= arr[i]; j++)
      if (arr[i] % j == 0) {
        int expo = 0;
        while (arr[i] % j == 0) {
          expo++;
          arr[i] /= j;
        }
        if (!factors.count(j)) {
          factors[j] = 0;
        }
        factors[j] += expo;
      }
    if (arr[i] > 1) {
      if (!factors.count(arr[i])) {
        factors[arr[i]] = 0;
      }
      factors[arr[i]]++;
    }
  }
  long long ans = 1;
  for (auto it : factors) {
    int count = it.second;
    ans = (1LL * ans * C(n + count - 1, n - 1)) % MD;
  }
  cout << ans;
  return 0;
}

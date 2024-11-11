#include <bits/stdc++.h>
using namespace std;
long long int powm(long long int x, long long int y,
                   long long int m = 1000000007) {
  x = x % m;
  long long int res = 1;
  while (y) {
    if (y & 1) res = res * x;
    res %= m;
    y = y >> 1;
    x = x * x;
    x %= m;
  }
  return res;
}
long long int factorialNumInverse[200001 + 1];
long long int naturalNumInverse[200001 + 1];
long long int fact[200001 + 1];
void InverseofNumber(long long int p) {
  naturalNumInverse[0] = naturalNumInverse[1] = 1;
  for (int i = 2; i <= 200001; i++)
    naturalNumInverse[i] = naturalNumInverse[p % i] * (p - p / i) % p;
}
void InverseofFactorial(long long int p) {
  factorialNumInverse[0] = factorialNumInverse[1] = 1;
  for (int i = 2; i <= 200001; i++)
    factorialNumInverse[i] =
        (naturalNumInverse[i] * factorialNumInverse[i - 1]) % p;
}
void factorial(long long int p) {
  fact[0] = 1;
  for (int i = 1; i <= 200001; i++) {
    fact[i] = (fact[i - 1] * i) % p;
  }
}
long long int Binomial(long long int n, long long int R, long long int p) {
  if (R == 0 or R == n) return 1;
  long long int ans =
      ((fact[n] * factorialNumInverse[R]) % p * factorialNumInverse[n - R]) % p;
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  InverseofNumber(1000000007);
  InverseofFactorial(1000000007);
  factorial(1000000007);
  long long int n;
  cin >> n;
  vector<long long int> arr(n);
  for (int i = (0); i <= (n - 1); i += (1)) cin >> arr[i];
  long long int ans = 0;
  if (n % 2 == 0) {
    if ((n / 2) & 1) {
      for (int i = (0); i <= (n - 1); i += (2)) {
        ans += arr[i] * Binomial((n - 2) / 2, i, 1000000007);
        ans %= 1000000007;
      }
      for (int i = (1); i <= (n - 1); i += (2)) {
        ans += arr[i] * Binomial((n - 2) / 2, i, 1000000007);
        ans %= 1000000007;
      }
    } else {
      for (int i = (0); i <= (n - 1); i += (1)) {
        ans += (i & 1 ? -1 : 1) * arr[i] *
               Binomial((n - 2) / 2, i / 2, 1000000007);
        ans %= 1000000007;
      }
    }
  } else {
    if ((n / 2) & 1) {
      for (int i = (0); i <= (n - 1); i += (1)) {
        ans += arr[i] *
               (i & 1 ? 2 * Binomial((n - 3) / 2, i / 2, 1000000007)
                      : (i / 2 <= (n - 3) / 2
                             ? Binomial((n - 3) / 2, i / 2, 1000000007)
                             : 0) -
                            (i / 2 - 1 >= 0
                                 ? Binomial((n - 3) / 2, i / 2 - 1, 1000000007)
                                 : 0));
        ans %= 1000000007;
      }
    } else {
      for (int i = (0); i <= (n - 1); i += (2)) {
        ans += (arr[i] * Binomial((n - 1) / 2, i / 2, 1000000007));
        ans %= 1000000007;
      }
    }
  }
  while (ans < 0) ans += 1000000007;
  cout << ans << endl;
  return 0;
}

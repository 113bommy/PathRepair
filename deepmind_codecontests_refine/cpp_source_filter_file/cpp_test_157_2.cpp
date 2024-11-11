#include <bits/stdc++.h>
using namespace std;
const long long int mod = 998244353;
const long long int inf = 1e18;
const long long int N = 5000;
long long int factorialNumInverse[N + 1];
long long int naturalNumInverse[N + 1];
long long int fact[N + 1];
void InverseofNumber(long long int p) {
  naturalNumInverse[0] = naturalNumInverse[1] = 1;
  for (long long int i = 2; i <= N; i++)
    naturalNumInverse[i] = naturalNumInverse[p % i] * (p - p / i) % p;
}
void InverseofFactorial(long long int p) {
  factorialNumInverse[0] = factorialNumInverse[1] = 1;
  for (long long int i = 2; i <= N; i++)
    factorialNumInverse[i] =
        (naturalNumInverse[i] * factorialNumInverse[i - 1]) % p;
}
void factorial(long long int p) {
  fact[0] = 1;
  for (long long int i = 1; i <= N; i++) {
    fact[i] = (fact[i - 1] * i) % p;
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int p = mod;
  InverseofNumber(p);
  InverseofFactorial(p);
  factorial(p);
  long long int n, k;
  string s;
  cin >> n >> k >> s;
  long long int l = 0, r = 0;
  vector<long long int> a;
  for (long long int i = 0; i < n; i++) {
    if (s[i] == '1') a.push_back(i);
  }
  if (a.size() < k || k == 0) {
    cout << 1 << "\n";
    return 0;
  }
  r = (a.size() == k ? n - 1 : a[k] - 1);
  long long int ans =
      (fact[r - l + 1] *
       (factorialNumInverse[k] * factorialNumInverse[r - l + 1 - k]) % mod) %
      mod;
  long long int pl = l, pr = r;
  bool done = 0;
  long long int g = k;
  while (g < a.size()) {
    pr = r;
    pl = l;
    l = a[g - k] + 1;
    r = (g + 1 == a.size() ? n - 1 : a[g + 1] - 1);
    long long int t1 =
        (fact[r - l + 1] *
         (factorialNumInverse[k] * factorialNumInverse[r - l + 1 - k] % mod)) %
        mod;
    long long int x = pr - l + 1;
    long long int t2 = (fact[x] * (factorialNumInverse[k - 1] *
                                   factorialNumInverse[x - k + 1] % mod)) %
                       mod;
    ans = (ans + t1 - t2 + mod) % mod;
    g++;
  }
  cout << ans << "\n";
  return 0;
}

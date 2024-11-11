#include <bits/stdc++.h>
using namespace std;
priority_queue<long long int, vector<long long int>, greater<long long int> >
    pq;
double startTime;
double getCurrentTime() {
  return ((double)clock() - startTime) / CLOCKS_PER_SEC;
}
bool isPrime(long long int n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long int i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
long long int gcd(long long int a, long long int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long int power(long long int x, unsigned long long int y,
                    long long int p) {
  long long int res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
void outP(long long int idx) { cout << "Case #" << idx << ": "; }
const long long int mod = 1e9 + 7;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int tt = 1;
  cin >> tt;
  while (tt--) {
    long long int n, k;
    cin >> n >> k;
    if (k == 0) {
      cout << "1\n";
      continue;
    }
    long long int crr = 1;
    for (long long int i = 0; i < n - 1; i++) crr = (crr * 2) % mod;
    long long int p2n = crr * 2;
    p2n %= mod;
    long long int mlt[k];
    mlt[0] = 1;
    for (long long int i = 1; i < k; i++) mlt[i] = (mlt[i - 1] * p2n) % mod;
    long long int abrr = 1, ans = 0;
    if (n % 2 == 0) {
      crr--;
      for (long long int i = k - 1; i > 0; i--) {
        ans = (ans + (abrr * mlt[i]) % mod) % mod;
        abrr = (abrr * crr) % mod;
      }
      crr++;
      crr %= mod;
      abrr = (abrr * crr) % mod;
      ans = (ans + abrr) % mod;
      cout << ans << endl;
      continue;
    }
    crr++;
    crr %= mod;
    ans = 1;
    for (long long int i = 0; i < k; i++) ans = (ans * crr) % mod;
    cout << ans << endl;
  }
  return 0;
}

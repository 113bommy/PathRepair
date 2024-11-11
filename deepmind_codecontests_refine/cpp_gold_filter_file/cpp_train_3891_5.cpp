#include <bits/stdc++.h>
using namespace std;
long long int mod = 1e9 + 7;
const long long inf = 1e18;
const long long maxn = 2e5 + 100;
long long pow(long long a, long long b) {
  if (b < 0) return 0LL;
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a;
    a = a * a;
    b >>= 1;
  }
  return ans;
}
long long binpow(long long a, long long b, long long m) {
  if (b < 0) return 0LL;
  if (a <= 0) return 0LL;
  a %= m;
  long long ans = 1LL;
  while (b) {
    if (b & 1) ans = ans * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return ans;
}
long long modinv(long long n) { return binpow(n, mod - 2, mod); }
int gcdExtended(int a, int b, int *x, int *y) {
  if (a == 0) {
    *x = 0, *y = 1;
    return b;
  }
  int x1, y1;
  int gcd = gcdExtended(b % a, a, &x1, &y1);
  *x = y1 - (b / a) * x1;
  *y = x1;
  return gcd;
}
void modInverse(int a, int m) {
  int x, y;
  int g = gcdExtended(a, m, &x, &y);
  if (g != 1)
    cout << "Inverse doesn't exist";
  else {
    int res = (x % m + m) % m;
    cout << "Modular multiplicative inverse is " << res;
  }
}
bool sortbysec(const pair<long long, long long> &a,
               const pair<long long, long long> &b) {
  return (a.second < b.second);
}
const long long N = 1e6 + 10;
long long sp[N];
void sieve(long long N) {
  for (long long i = 1; i < N; i++) sp[i] = i;
  for (long long i = 2; i < N; i++) {
    if (sp[i] == i) {
      for (long long j = i * i; j < N; j += i) {
        if (sp[j] == j) sp[j] = i;
      }
    }
  }
}
void solve() {
  int n, d;
  cin >> n >> d;
  vector<long long> x(n);
  for (long long i = 0; i < n; i++) {
    cin >> x[i];
  }
  long long ans = 0;
  for (long long i = 0; i < n - 2; i++) {
    int tar = x[i] + d;
    int l = i + 1, r = n - 1;
    int mid;
    while (l <= r) {
      mid = (l + r) / 2;
      if (x[mid] == tar) {
        break;
      }
      if (x[mid] < tar) {
        l = mid + 1;
      }
      if (x[mid] > tar) {
        r = mid - 1;
      }
    }
    if (l > r) {
      if (r - i >= 2) {
        ans += ((r - i) * (r - i - 1)) / 2;
      }
    } else {
      if (mid - i >= 2) {
        ans += ((mid - i) * (mid - i - 1)) / 2;
      }
    }
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t;
  t = 1;
  while (t--) {
    solve();
  }
  return 0;
}

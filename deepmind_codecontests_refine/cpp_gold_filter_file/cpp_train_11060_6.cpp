#include <bits/stdc++.h>
using namespace std;
const long double PI = (long double)(3.1415926535897932384626433832795);
int parity_check(int n) {
  int par = n;
  par = par ^ (par >> 1);
  par = par ^ (par >> 2);
  par = par ^ (par >> 4);
  par = par ^ (par >> 8);
  par = par ^ (par >> 16);
  if (par % 2 == 1) {
    return 1;
  } else {
    return 0;
  }
}
int lcs(string X, string Y, int m, int n) {
  int L[m + 1][n + 1];
  int i, j;
  for (i = 0; i <= m; i++) {
    for (j = 0; j <= n; j++) {
      if (i == 0 || j == 0)
        L[i][j] = 0;
      else if (X[i - 1] == Y[j - 1])
        L[i][j] = L[i - 1][j - 1] + 1;
      else
        L[i][j] = max(L[i - 1][j], L[i][j - 1]);
    }
  }
  return L[m][n];
}
int long long gcd(int long long a, int long long b) {
  if (a == 0) {
    return b;
  }
  return gcd(b % a, a);
}
int long long lcm(int long long a, int long long b) {
  int long long pro = a * b;
  int long long ans = gcd(a, b);
  pro = pro / ans;
  return pro;
}
int long long fast_power(int long long a, int long long b, int long long p) {
  if (b == 0) {
    return (1 % p);
  }
  int long long t = fast_power(a, b / 2, p);
  int long long ans = (t * t) % p;
  if (b % 2) {
    ans = (ans * (a % p)) % p;
  }
  return ans;
}
bool prime_check(int long long n) {
  int long long i, j;
  if (n == 1) {
    return false;
  }
  for (i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}
int long long fact(int long long n, int long long mod) {
  int long long prod = 1;
  for (int long long i = 1; i <= n; i++) {
    prod = (prod * i) % mod;
  }
  return prod;
}
int long long fac[500001];
void calc_fac(int long long mod) {
  fac[0] = 1;
  for (int i = 1; i <= 500000; i++) {
    fac[i] = (fac[i - 1] * i) % mod;
  }
}
int long long comb(int long long n, int long long r, int long long mod) {
  if (r > n) {
    return 0;
  }
  int long long ans = fac[n];
  int long long den = (fac[n - r] * fac[r]) % mod;
  ans = (ans * fast_power(den, mod - 2, mod)) % mod;
  return ans;
}
void mera_sieve() {
  bool prime[6000013];
  memset(prime, true, sizeof(prime));
  for (int long long p = 2; p * p <= 6000012; p++) {
    if (prime[p] == true) {
      for (int long long i = p * p; i <= 6000012; i += p) prime[i] = false;
    }
  }
  for (int long long i = 2; i <= 6000012; i++) {
    if (prime[i]) {
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int long long test, n, i, j;
  cin >> test;
  while (test--) {
    cin >> n;
    int long long arr[n];
    int long long a = n / 2;
    if (a % 2 == 1) {
      cout << "NO"
           << "\n";
      ;
    } else {
      cout << "YES"
           << "\n";
      ;
      int long long k = 2;
      for (i = 0; i < a; i++) {
        arr[i] = k;
        k += 2;
      }
      k = 1;
      for (i = a; i < n; i++) {
        arr[i] = k;
        k += 2;
      }
      arr[n - 1] += a;
      for (i = 0; i < n; i++) {
        cout << arr[i] << " ";
      }
      cout << "\n";
    }
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1);
vector<bool> prime;
void primes(long long n) {
  prime.resize(n + 1);
  prime.assign(n + 1, true);
  prime[0] = 0;
  prime[1] = 0;
  for (long long i = 2; i * i <= n; i++) {
    if (prime[i]) {
      for (long long j = (i * i); j < n; j = j + i) prime[j] = false;
    }
  }
}
void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
long long gcd(long long x, long long y) {
  if (x == 0) return y;
  return gcd(y % x, x);
}
long long powM(long long x, long long y, long long m) {
  long long ans = 1, r = 1;
  x = x % m;
  while (r > 0 && r <= y) {
    if (r & y) {
      ans = ans * x;
      ans = ans % m;
    }
    r = r << 1;
    x = x * x;
    x = x % m;
  }
  return ans;
}
long long powN(long long a, long long n) {
  if (n == 0) return 1;
  if (n == 1) return a;
  long long u = powN(a, n / 2);
  u = u * u;
  if (n % 2) u = u * a;
  return u;
}
long long modinv(long long a, long long m) { return powM(a, m - 2, m); }
long long ncr(long long n, long long r, long long m) {
  if (n < r) return 0;
  if (n == r || r == 0) return 1;
  if (r == 1) return n;
  if (n - r < r) return ncr(n, n - r, m);
  long long a = n;
  long long b = r;
  for (long long i = 1; i < r; i++) {
    a = (a * (n - i)) % m;
    b = (b * (r - i)) % m;
  }
  b = modinv(b, m);
  a = (a * b) % m;
  return a;
}
long long countbits(long long n) {
  long long cot = 0;
  while (n) {
    cot++;
    n >>= 1;
  }
  return cot;
}
long long check_prime(long long n) {
  long long ans = 1;
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      ans = 0;
      break;
    }
  }
  return ans;
}
long long SOD(long long n) {
  long long sum = 0;
  while (n > 0) {
    sum += n % 10;
    n /= 10;
  }
  return sum;
}
int main() {
  fast();
  long long t = 1;
  while (t--) {
    long long n;
    cin >> n;
    vector<pair<long long, string>> a;
    string tt;
    long long k;
    for (long long i = 0; i < n; i++) {
      cin >> tt;
      k = tt.size();
      a.push_back({k, tt});
    }
    sort(a.begin(), a.end());
    vector<string> b;
    bool ok = 1;
    for (auto i : a) {
      b.push_back(i.second);
    }
    for (long long i = 0; i < n - 1; i++) {
      if (b[i + 1].find(b[i]) == string::npos) ok = 0;
    }
    if (ok) {
      cout << "YES\n";
      for (auto i : a) {
        cout << i.second << "\n";
      }
    } else {
      puts("NO");
    }
  }
  return 0;
}

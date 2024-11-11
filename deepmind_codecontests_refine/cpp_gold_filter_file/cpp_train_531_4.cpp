#include <bits/stdc++.h>
using namespace std;
vector<vector<long long> > coprime(100001);
void prime_factorization() {
  for (long long i = 2; i <= 100001; i += 2) {
    coprime[i].push_back(2);
  }
  for (long long i = 3; i <= 100001; i += 3) {
    coprime[i].push_back(3);
  }
  for (long long i = 5; i <= 50000; i += 6) {
    if (coprime[i].size() == 0) {
      for (long long j = i; j <= 100000; j += i) {
        coprime[j].push_back(i);
      }
    }
    if (coprime[i + 2].size() == 0) {
      for (long long j = i + 2; j <= 100000; j += i + 2) {
        coprime[j].push_back(i + 2);
      }
    }
  }
}
bool isprime(long long n) {
  if (n < 2) return false;
  if (n == 2 || n == 3) return true;
  if (n % 2 == 0) return false;
  if (n % 3 == 0) return false;
  for (long long i = 5; i <= sqrt(n); i += 6) {
    if (n % i == 0 || n % (i + 2) == 0) return false;
  }
  return true;
}
long long bin_power(long long a, long long n) {
  if (a == 0) return 0;
  long long res = 1;
  while (n) {
    if (n % 2) {
      res = (res * a) % 1000000007;
      n--;
    } else {
      a = (a * a) % 1000000007;
      n /= 2;
    }
  }
  return res;
}
void p_factors(long long &n, map<long long, long long> &m) {
  if (n % 2 == 0) {
    long long c = 0;
    while (n % 2 == 0) {
      n /= 2;
      c++;
    }
    m[2] = c;
  }
  for (long long i = 3; i <= sqrt(n); i += 2) {
    if (n % i == 0) {
      long long c = 0;
      while (n % i == 0) {
        n /= i;
        c++;
      }
      m[i] = c;
    }
  }
  if (n != 1) m[n] = 1;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long extended_gcd(long long a, long long b, long long *x, long long *y) {
  if (a == 0) {
    *x = 0;
    *y = 1;
    return b;
  }
  long long x1, y1;
  long long g = extended_gcd(b % a, a, &x1, &y1);
  *x = y1 - (b / a) * x1;
  *y = x1;
  return g;
}
void simple_sieve(long long n, vector<long long> &primes) {
  if (n < 2) return;
  if (n < 3) {
    primes.push_back(2);
    return;
  }
  vector<bool> mark(n + 1, true);
  mark[2] = true;
  mark[3] = true;
  primes.push_back(2);
  primes.push_back(3);
  for (long long i = 5; i * i < n; i += 6) {
    if (mark[i]) {
      for (long long j = i * i; j < n; j += i) mark[j] = false;
    }
    if (mark[i + 2] && (i + 2) < sqrt(n)) {
      for (long long j = (i + 2) * (i + 2); j < n; j += (i + 2))
        mark[j] = false;
    }
  }
  for (long long i = 5; i < n; i += 6) {
    if (mark[i]) primes.push_back(i);
    if (mark[i + 2] && (i + 2) < n) primes.push_back(i + 2);
  }
}
void linear_sieve(long long n, vector<long long> &primes) {
  if (n < 2) return;
  if (n < 3) {
    primes.push_back(2);
    return;
  }
  vector<long long> mark(n + 1);
  for (long long i = 2; i <= n; i++) {
    if (mark[i] == 0) {
      primes.push_back(i);
      mark[i] = i;
    }
    for (long long j = 0;
         j < primes.size() && primes[j] <= mark[i] && i * primes[j] <= n; j++)
      mark[i * primes[j]] = primes[j];
  }
}
void segmented_sieve(long long n, vector<long long> &primes) {
  if (n < 2) return;
  long long limit = sqrt(n) + 1;
  simple_sieve(limit, primes);
  long long low = limit;
  long long high = 2 * limit;
  while (low < n) {
    if (high >= n) high = n + 1;
    vector<bool> mark(high - low + 2, true);
    for (long long i = 0; i < primes.size(); i++) {
      long long lolim = (low / primes[i]) * primes[i];
      if (lolim < low) lolim += primes[i];
      for (long long j = lolim; j < high; j += primes[i]) mark[j - low] = false;
    }
    for (long long j = low; j < high; j++) {
      if (mark[j - low]) primes.push_back(j);
    }
    low += limit;
    high += limit;
  }
}
void ranged_primes(long long low, long long high, vector<long long> &primes) {
  if (low < 2) low = 2;
  if (high < 2) return;
  long long lim = sqrt(high);
  vector<long long> pr;
  linear_sieve(lim, pr);
  if (pr.size() == 0) {
    if (high == 2) {
      primes.push_back(2);
      return;
    }
    if (high == 3) {
      if (low <= 2) {
        primes.push_back(2);
        primes.push_back(3);
        return;
      }
      primes.push_back(3);
      return;
    }
  }
  vector<bool> mark(high - low + 1, true);
  for (auto &i : pr) {
    long long j = i * i;
    if (j < low) {
      j = (low / i) * i;
      if (j < low) j += i;
    }
    while (j <= high) {
      mark[j - low] = false;
      j += i;
    }
  }
  for (long long i = low; i <= high; i++) {
    if (mark[i - low]) primes.push_back(i);
  }
}
long long totient(long long n) {
  long long res = n;
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      while (n % i == 0) {
        n /= i;
      }
      res -= res / i;
    }
  }
  if (n > 1) res -= res / n;
  return res;
}
void phi_1_to_n(long long n, vector<long long> &phi) {
  for (long long i = 0; i <= n; i++) {
    phi[i] = i;
  }
  for (long long i = 2; i <= n; i++) {
    if (phi[i] == i) {
      for (long long j = i; j <= n; j += i) {
        phi[j] -= phi[j] / i;
      }
    }
  }
}
string division(long long a, long long b) {
  if (a == 0) return "null";
  if (b == 0) return "0";
  string s;
  if (a * b < 0)
    s = "-";
  else
    s = "";
  a = abs(a);
  b = abs(b);
  long long c = gcd(a, b);
  a = a / c;
  b = b / c;
  s += to_string(b);
  s += "/";
  s += to_string(a);
  return s;
}
long long factorial(long long n) {
  long long res = 1;
  for (long long i = 2; i <= n; i++) {
    res = (res * i) % 1000000007;
  }
  return res % 1000000007;
}
long long sumofint(long long n) {
  string s = to_string(n);
  long long sum = 0;
  for (long long i = 0; i < s.size(); i++) {
    int j = s[i];
    j -= 48;
    sum += j;
  }
  return sum;
}
int day(int m, int d) {
  int res = 0;
  for (int i = 1; i < m; i++) {
    if (i == 4 || i == 6 || i == 9 || i == 11)
      res += 30;
    else if (i == 2)
      res += 28;
    else
      res += 31;
  }
  res += d;
  return res;
}
double fac(long long n) {
  double res = 1.000;
  for (long long i = 2; i <= n; i++) {
    res = res * (double)i;
  }
  return res;
}
long long modinverse(long long n) { return bin_power(n, 1000000007 - 2); }
long long solve(long long a) {
  string s = to_string(a);
  long long n = s.size();
  long long res = 0;
  for (long long i = 1; i < n; i++)
    res += 9 * pow(10, max((long long)0, i - 2));
  res += (s[0] - '1') * (pow(10, max((long long)0, n - 2)));
  if (n == 1)
    res++;
  else if (n == 2) {
    if (s[0] <= s[1]) res++;
  } else {
    long long x = (s[0] - '0') * (pow(10, n - 1) + 1);
    res += (a + 10 - x) / 10;
  }
  return res;
}
long long ncr(long long n, long long r) {
  if (n < 0 || r > n || r < 0) return 0;
  if (n - r < r) r = n - r;
  vector<long long> c(n + 1);
  c[0] = 1;
  for (long long i = 1; i <= n; i++) {
    for (long long j = min(i, r); j > 0; j--) {
      c[j] = (c[j] + c[j - 1]) % 1000000007;
    }
  }
  return c[r] % 1000000007;
}
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long tc = 1;
  while (tc--) {
    long long n, k, xx, yy;
    cin >> n >> k;
    xx = (k + 1) / 2;
    yy = (k + 1) / 2;
    vector<long long> v(n);
    for (long long i = 0; i < n; i++) cin >> v[i];
    vector<vector<long long> > dp(k + 1, vector<long long>(k + 1));
    for (long long i = 0; i < n; i++) {
      long long x = -1, y1, y2, mn = INT_MAX;
      for (long long j = 1; j <= k; j++) {
        long long s = 0, sum = 0;
        for (long long l = 1; l <= v[i]; l++) {
          sum += abs(yy - l);
          sum += abs(xx - j);
          if (dp[j][l]) s = l;
          if (l - s == v[i]) {
            if (sum < mn) {
              mn = sum;
              x = j;
              y2 = l;
              y1 = l - v[i] + 1;
            }
          }
        }
        for (long long l = v[i] + 1; l <= k; l++) {
          sum += abs(yy - l);
          sum -= abs(yy - l + v[i]);
          if (dp[j][l]) s = l;
          if (l - s >= v[i]) {
            if (sum < mn) {
              mn = sum;
              x = j;
              y2 = l;
              y1 = l - v[i] + 1;
            }
          }
        }
      }
      if (x == -1)
        cout << "-1\n";
      else {
        cout << x << " " << y1 << " " << y2 << endl;
        for (long long j = y1; j <= y2; j++) dp[x][j] = 1;
      }
    }
  }
  return 0;
}

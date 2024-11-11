#include <bits/stdc++.h>
using namespace std;
const long long M = 1e9 + 7;
const long long N = 1e5 + 1;
void solve();
void findDivisors(long long n);
long long gcd(long long a, long long b);
void sieve(long long n);
long long lcm(long long a, long long b);
long long mexp(long long base, long long exp);
long long highestPowerOf2(long long n);
long long count_digit(long long number);
long long sum_digit(long long n);
long long sum_digit_string(string str);
string dec2bin(long long n);
long long ceilval(long long a, long long b);
long long binarysrch(long long arr[], long long n, long long x);
long long closesttotheleft(long long a[], long long n, long long x);
bool cmp(long long a, long long b);
void solve() {
  long long n, k;
  cin >> n >> k;
  long long a[n];
  long long x1, x2, y1, y2, z1, z2;
  cout << "or 1 2" << endl << flush;
  cin >> x1;
  cout << "and 1 2" << endl << flush;
  cin >> x2;
  x1 += x2;
  cout << "or 2 3" << endl << flush;
  cin >> y1;
  cout << "and 2 3" << endl << flush;
  cin >> y2;
  y1 += y2;
  cout << "or 1 3" << endl << flush;
  cin >> z1;
  cout << "and 1 3" << endl << flush;
  cin >> z2;
  z1 += z2;
  a[0] = (x1 - y1 + z1) / 2;
  a[1] = x1 - a[0];
  a[2] = z1 - a[0];
  for (long long i = 3; i < n; i++) {
    long long x1, x2;
    cout << "or 1 " << i << endl << flush;
    cin >> x1;
    cout << "and 1 " << i << endl << flush;
    cin >> x2;
    x1 += x2;
    a[i] = x1 - a[0];
  }
  sort(a, a + n);
  cout << "finish " << a[k - 1] << endl << flush;
}
int32_t main() {
  std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  long long t = 1, cse = 0;
  while (t--) {
    solve();
  }
  return 0;
}
void findDivisors(long long n) {
  long long div[N];
  memset(div, 0, sizeof div);
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j * i <= n; j++) div[i * j]++;
  }
}
void sieve(long long n) {
  vector<long long> primes;
  bool check[N];
  for (long long i = 0; i * i <= n; ++i) {
    if (!check[i]) primes.push_back(i);
    for (long long j = 0; j < primes.size() && i * primes[j] <= n; ++j) {
      check[i * primes[j]] = true;
      if (i % primes[j] == 0) break;
    }
  }
}
long long mpow(long long base, long long exp, long long md = M) {
  long long result = 1;
  base %= md;
  if (base == 0) return 0;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % md;
    base = (base * base) % md;
    exp >>= 1;
  }
  return result;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return a * (b / gcd(a, b)); }
long long highestPowerOf2(long long n) { return (n & (~(n - 1))); }
long long count_digit(long long number) { return int32_t(log10(number) + 1); }
long long sum_digit(long long n) {
  long long sum = 0;
  while (n != 0) {
    sum = sum + n % 10;
    n = n / 10;
  }
  return sum;
}
long long sum_digit_string(string str) {
  long long sum = 0;
  for (long long i = 0; i < str.length(); i++) {
    sum = sum + str[i] - 48;
  }
  return sum;
}
string dec2bin(long long n) {
  const long long size = sizeof(n) * 8;
  string s = "00000000000000000000000000000000";
  for (long long a = 0; a < 32; a++) {
    if (n == 0)
      return s;
    else {
      if (n % 2 != 0) s[31 - a] = '1';
      n /= 2;
    }
  }
  return s;
}
bool cmp(long long a, long long b) { return a > b; }
long long ceilval(long long a, long long b) {
  long long x = (a / b) + ((a % b) != 0);
  return x;
}
long long binarysrch(long long arr[], long long n, long long x) {
  long long lo = 0;
  long long hi = n - 1;
  long long mid = (hi + lo) / 2;
  while (hi - lo > 1) {
    if (arr[mid] < x) {
      lo = mid + 1;
      mid = (hi + lo) / 2;
    } else {
      hi = mid;
      mid = (hi + lo) / 2;
    }
  }
  if (arr[lo] == x) {
    return lo;
  } else if (arr[hi] == x) {
    return hi;
  } else {
    return -1;
  }
}
long long closesttotheleft(long long a[], long long n, long long x) {
  long long lo = 0, hi = n - 1;
  long long mid = (lo + hi) / 2;
  while (lo <= hi) {
    if (a[mid] == x) {
      if (a[mid + 1] > x) {
        lo = mid;
      } else {
        lo = mid + 1;
      }
      mid = (lo + hi) / 2;
    }
    if (a[mid] <= x) {
      lo = mid + 1;
      mid = (lo + hi) / 2;
    } else {
      hi = mid - 1;
      mid = (lo + hi) / 2;
    }
  }
  return lo;
}

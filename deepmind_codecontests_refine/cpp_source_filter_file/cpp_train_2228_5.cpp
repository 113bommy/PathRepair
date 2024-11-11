#include <bits/stdc++.h>
using namespace std;
bool isPrime(int n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (int i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
long long nextPrime(long long N) {
  if (N <= 1) return 2;
  long long prime = N;
  bool found = false;
  while (!found) {
    prime++;
    if (isPrime(prime)) found = true;
  }
  return prime;
}
long long powerexp(long long x, long long n) {
  long long result = 1;
  while (n) {
    if (n & 1) result = result * x % 1000000007;
    n = n / 2;
    x = x * x % 1000000007;
  }
  return result;
}
int gcd(int a, int b) {
  if (a == 0) return b;
  if (b == 0) return a;
  if (a == b) return a;
  if (a > b) return gcd(a - b, b);
  return gcd(a, b - a);
}
int largest_divisor(long long n) {
  long long i;
  for (i = n / 2; i >= 1; i--) {
    if (n % i == 0) {
      return i;
    }
  }
  return 0;
}
bool checkPalindrome(string str) {
  int n = str.length();
  int count = 0;
  for (int i = 0; i < n / 2; ++i)
    if (str[i] != str[n - i - 1]) ++count;
  return (count <= 1);
}
void SieveOfEratosthenes(long long n, bool prime[], bool primesquare[],
                         long long a[]) {
  for (long long i = 2; i <= n; i++) prime[i] = true;
  for (long long i = 0; i <= (n * n + 1); i++) primesquare[i] = false;
  prime[1] = false;
  for (long long p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (int i = p * 2; i <= n; i += p) prime[i] = false;
    }
  }
  int j = 0;
  for (long long p = 2; p <= n; p++) {
    if (prime[p]) {
      a[j] = p;
      primesquare[p * p] = true;
      j++;
    }
  }
}
long long countDivisors(long long n) {
  if (n == 1) return 1;
  bool prime[n + 1], primesquare[n * n + 1];
  long long a[n];
  SieveOfEratosthenes(n, prime, primesquare, a);
  long long ans = 1;
  for (long long i = 0;; i++) {
    if (a[i] * a[i] * a[i] > n) break;
    long long cnt = 1;
    while (n % a[i] == 0) {
      n = n / a[i];
      cnt = cnt + 1;
    }
    ans = ans * cnt;
  }
  if (prime[n])
    ans = ans * 2;
  else if (primesquare[n])
    ans = ans * 3;
  else if (n != 1)
    ans = ans * 4;
  return ans;
}
long long factorial(long long n) {
  if (n == 0) return 0;
  return n * factorial(n - 1);
}
long long lcm(long long a, long long b) { return (a / gcd(a, b)) * b; }
void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
long long sum(long long n) {
  long long sum = 0;
  while (n != 0) {
    sum += n % 10;
    n = n / 10;
  }
  return sum;
}
long long next(long long a, long long b) {
  if (a % b == 0) {
    return a / b;
  } else {
    return (a / b) + 1;
  }
}
long long Chefora(long long n) {
  long long res = n / 10;
  long long ans = n;
  while (res != 0) {
    long long y = res % 10;
    res = res / 10;
    ans = (ans * 10) + y;
  }
  return ans;
}
int main() {
  long long t = 1;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    long long a[m];
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a, a + m);
    long long mn = a[m - 1] - a[0];
    for (long long i = 0; i < m - n; i++) {
      long long x = a[i + n - 1] - a[i];
      mn = min(x, mn);
    }
    cout << mn << endl;
  }
  return 0;
}

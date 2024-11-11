#include <bits/stdc++.h>
using namespace std;
template <class T>
T max(T a, T b, T c) {
  return max(a, max(b, c));
}
template <class T>
T min(T a, T b, T c) {
  return min(a, min(b, c));
}
void fastio() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
bool prime[100005];
void SieveOfEratosthenes(long long int n) {
  memset(prime, true, sizeof(prime));
  for (long long int p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (long long int i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
}
bool isPrime(long long int n) {
  if (n < 2) return false;
  for (long long int i = 2; i * i <= n; i++)
    if (n % i == 0) return false;
  return true;
}
std::vector<long long int> generatePrimeFactors(long long int n) {
  std::vector<long long int> prime;
  for (long long int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      prime.push_back(i);
      while (n % i == 0) n = n / i;
    }
  }
  if (n != 1) prime.push_back(n);
  return prime;
}
std::vector<long long int> generateFactors(long long int n) {
  std::vector<long long int> fact;
  for (long long int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      fact.push_back(i);
      if (n / i != i) fact.push_back(n / i);
    }
  }
  fact.push_back(1);
  fact.push_back(n);
  sort(fact.begin(), fact.end());
  return fact;
}
long long int gcd(long long int a, long long int b) {
  if (!b) return a;
  return gcd(b, a % b);
}
long long int modpow(long long int x, long long int n, long long int m) {
  if (n == 0) return 1 % m;
  long long int u = modpow(x, n / 2, m) % m;
  u = ((u % m) * (u % m)) % m;
  if (n % 2 == 1) u = ((u % m) * (x % m)) % m;
  return u % m;
}
long long int eulerstotientfunction(long long int n) {
  long long int ans = n;
  for (long long int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      while (n % i == 0) n = n / i;
      ans -= ans / i;
    }
  }
  if (n > 1) ans -= ans / n;
  return ans;
}
long long int modinverse(long long int x, long long int m) {
  return modpow(x, m - 2, m);
}
long long int add(long long int a, long long int b, long long int m) {
  return (((a % m) + (b % m)) % m);
}
long long int substract(long long int a, long long int b, long long int m) {
  return (((a % m) - (b % m) + m) % m);
}
long long int multiply(long long int a, long long int b, long long int m) {
  return (((a % m) * (b % m)) % m);
}
long long int divide(long long int a, long long int b, long long int m) {
  long long int temp = modinverse(b, m);
  return multiply(a, temp, m);
}
long long int singlemod(long long int a, long long int m) { return (a % m); }
long long int ncr(long long int n, long long int k, long long int m) {
  if (k > n) return 0;
  long long int res = 1;
  k = min(k, n - k);
  for (long long int i = 1; i <= k; i++) {
    res = multiply(res, n - i + 1, m);
    res = divide(res, i, m);
  }
  return singlemod(res, m);
}
long long int kadaneAlgo(const std::vector<long long int> &arr) {
  long long int size = arr.size();
  long long int currmax = arr[0], maxsofar = arr[0];
  for (long long int i = 1; i < size; i++) {
    currmax = max(arr[i], currmax + arr[i]);
    maxsofar = max(maxsofar, currmax);
  }
  return maxsofar;
}
long long int getDigitSum(long long int n) {
  long long int co = 0;
  while (n > 0) {
    co += n % 10;
    n = n / 10;
  }
  return co;
}
template <class T>
void printVector(const std::vector<T> arr) {
  for (auto i : arr) cout << i << " ";
  cout << '\n';
}
template <class T>
void printArray(T arr[], long long int n) {
  for (long long int i = 1; i <= n; i++) cout << arr[i] << " ";
  cout << '\n';
}
long long int solve(long long int pos, string str, long long int final,
                    long long int curr) {
  if (pos == str.length()) return curr == final;
  if (str[pos] == '+')
    return solve(pos + 1, str, final, curr + 1);
  else if (str[pos] == '-')
    return solve(pos + 1, str, final, curr - 1);
  else {
    return (solve(pos + 1, str, final, curr + 1) +
            solve(pos + 1, str, final, curr - 1));
  }
}
int main() {
  fastio();
  long long int t = 1;
  while (t--) {
    long long int n, m, ans = 0;
    cin >> n >> m;
    for (long long int i = 1; i <= n; i++) {
      long long int a = n - i, b = m - i;
      ans = max(ans, min(i, a + b));
    }
    cout << ans << '\n';
  }
}

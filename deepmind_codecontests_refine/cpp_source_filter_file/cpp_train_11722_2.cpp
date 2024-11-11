#include <bits/stdc++.h>
const long long MOD = 1e9 + 7;
using namespace std;
bool isPrime(long long n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long i = 5; i * i <= n; i = i + 2)
    if (n % i == 0) return false;
  return true;
}
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long lcm(long long a, long long b) {
  long long g = gcd(a, b);
  long long ans = (a * b) / g;
  return ans;
}
bool palindrome(string s) {
  for (long long i = 0; i < s.length() / 2; i++) {
    if (s[i] != s[s.length() - i - 1]) return 0;
  }
  return 1;
}
void printDivisors(int n) {
  for (int i = 1; i <= sqrt(n); i++) {
    if (n % i == 0) {
      if (n / i == i)
        printf("%d ", i);
      else
        printf("%d %d ", i, n / i);
    }
  }
}
int convert_number(string s) {
  int n;
  stringstream(s) >> n;
  return n;
}
vector<long long> prime;
void primes(long long m) {
  bool isprime[m];
  for (int i = 0; i <= m; i++) isprime[i] = true;
  for (int i = 3; i * i <= m; i++) {
    if (isprime[i]) {
      for (int j = i * i; j <= m; j += i) isprime[j] = false;
    }
  }
  prime.push_back(2);
  for (int i = 3; i <= m; i += 2)
    if (isprime[i]) prime.push_back(i);
}
int main(int argc, char *argv[]) {
  int n, k;
  cin >> n >> k;
  int ara[n];
  double dev = n - k + 1;
  int temp = 0, res = 0;
  for (int i = 0; i < n; i++) {
    cin >> ara[i];
    if (i < k)
      temp += ara[i];
    else {
      res += temp;
      temp -= ara[i - k];
      temp += ara[i];
    }
  }
  res += temp;
  cout << fixed << setprecision(8) << res / dev << endl;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
long long pwr(long long a, long long b, long long mod) {
  a %= mod;
  if (a < 0) a += mod;
  long long ans = 1;
  while (b) {
    if (b & 1) ans = (ans * a) % mod;
    a = (a * a) % mod;
    b /= 2;
  }
  return ans;
}
long long pwr(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans *= a;
    a *= a;
    b /= 2;
  }
  return ans;
}
long long gcd(long long a, long long b) {
  while (b) {
    long long temp = a;
    a = b;
    b = temp % b;
  }
  return a;
}
long long lcm(long long a, long long b) { return (a / gcd(a, b)) * b; }
long long modularInverse(long long a, long long m) {
  assert(false);
  return pwr(a, m - 2, m);
}
int main(int argc, char const *argv[]) {
  std::ios::sync_with_stdio(false);
  string a[10] = {"zero", "one", "two",   "three", "four",
                  "five", "six", "seven", "eight", "nine"};
  string b[10] = {"ten",   "twenty",  "thirty", "forty", "fifty",
                  "sixty", "seventy", "eighty", "ninety"};
  string c[10] = {"eleven",  "twelve",    "thirteen", "fourteen", "fifteen",
                  "sixteen", "seventeen", "eighteen", "nineteen"};
  int n;
  cin >> n;
  if (n >= 0 && n <= 9)
    cout << a[n];
  else if (n >= 11 && n < 20)
    cout << c[n - 11];
  else if (n % 10 == 0)
    cout << b[(n / 10) - 1];
  else {
    int rem = n / 10;
    int scnd = n % 10;
    cout << b[rem - 1] << "-" << a[scnd];
  }
  return 0;
}

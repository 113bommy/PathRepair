#include <bits/stdc++.h>
using namespace std;
long long maxx = 1000000007;
bool sortbyfir(const pair<long long, long long> &a,
               const pair<long long, long long> &b) {
  return (a.first < b.first || (a.first == b.first && a.second < b.second));
}
long long inline power(long long a, long long b, long long p) {
  a %= p;
  long long ans = 1;
  while (b > 0) {
    if (b & 1) ans = ans * a % p;
    a = a * a % p;
    b >>= 1;
  }
  return ans;
}
long long inv(long long n, long long p) { return power(n, p - 2, p); }
inline vector<long long> allinv(long long n, long long p) {
  vector<long long> arr(n);
  arr[1] = 1;
  for (long long i = (2); i < (n); i += 1) {
    arr[i] = (p - (p / i) * arr[p % i] % p) % p;
  }
  return arr;
}
long long max3(long long a, long long b, long long c) {
  return max(max(a, b), c);
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
bool inline isPrime(long long n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
void prt(int i) { i ? cout << "YES\n" : cout << "NO\n"; }
long long getSum(long long n) {
  long long sum = 0;
  while (n != 0) {
    sum = sum + n % 10;
    n = n / 10;
  }
  return sum;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long test = 1;
  while (test--) {
    string s;
    long long c = 0;
    cin >> s;
    long long n = s.size();
    for (long long i = 0; i < n; i++) {
      if (s[i] == '1') c++;
    }
    if (n % 2) {
      if (c > 1) {
        cout << ceil(n / 2) << "\n";
        continue;
      }
      cout << n / 2 << "\n";
      continue;
    }
    cout << n / 2 << "\n";
  }
}

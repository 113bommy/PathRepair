#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  return b == 0 ? a : gcd(b, a % b);
}
long long int power(long long int x, long long int n) {
  long long int result = 1;
  while (n > 0) {
    if (n % 2 == 1) result = (result * x) % 1000000007;
    x = (x * x) % 1000000007;
    n = n / 2;
  }
  return result % 1000000007;
}
bool isPrime(long long int n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long int i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
long long int inv(long long int a, long long int m) { return power(a, m - 2); }
long long int lcm(long long int a, long long int b) {
  return a * b / (gcd(a, b));
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int n;
  cin >> n;
  string str;
  cin >> str;
  map<long long int, long long int> mp;
  for (long long int i = 1; i <= 9; i++) {
    long long int x;
    cin >> x;
    mp[i] = x;
  }
  for (long long int i = 0; i < n; i++) {
    long long int x = str[i] - '0';
    if (mp[x] > x) {
      str[i] = (char)(mp[x] + '0');
      for (long long int j = i + 1; j < n; j++) {
        long long int g = str[j] - '0';
        if (mp[g] > g)
          str[j] = (char)(mp[g] + '0');
        else
          break;
      }
      break;
    }
  }
  cout << str;
}

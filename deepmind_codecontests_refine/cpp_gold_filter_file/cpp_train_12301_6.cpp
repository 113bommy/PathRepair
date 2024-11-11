#include <bits/stdc++.h>
using namespace std;
const long long int M = 1000000007;
long long int ncr(int n, int r) {
  if (r > n) return 0;
  if (r > n - r) r = n - r;
  long long int ans = 1;
  int i;
  for (i = 1; i <= r; i++) {
    ans *= n - r + i;
    ans /= i;
  }
  return ans;
}
long long int power(long long int x, long long int n, long long int m) {
  if (n == 0)
    return 1;
  else if (n % 2 == 0)
    return (power(((x % m) * (x % m)) % m, n / 2, m)) % m;
  else
    return ((x % m) * (power(x, n - 1, m) % m)) % m;
}
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
long long int modInverse(long long int a, long long int m) {
  long long int m0 = m;
  long long int y = 0, x = 1;
  if (m == 1) return 0;
  while (a > 1) {
    long long int q = a / m;
    long long int t = m;
    m = a % m, a = t;
    t = y;
    y = x - q * y;
    x = t;
  }
  if (x < 0) x += m0;
  return x;
}
string binary(long long int n) {
  if (n == 0) {
    return "0";
  }
  string ans;
  while (n > 0) {
    if (n & 1)
      ans.push_back('1');
    else
      ans.push_back('0');
    n = n >> 1;
  }
  reverse(ans.begin(), ans.end());
  return ans;
}
bool is_prime(long long int n) {
  if (n == 1) return 0;
  for (long long int i = 2; i * i <= n; i++) {
    if (n % i == 0) return 0;
  }
  return 1;
}
long long int sum_digit(long long int n) {
  long long int ans = 0;
  while (n > 0) {
    ans += (n % 10);
    n /= 10;
  }
  return ans;
}
long long int len_digit(long long int n) {
  long long int ans = 0;
  while (n > 0) {
    ans += 1;
    n /= 10;
  }
  return ans;
}
long long int binary_to_decimal(string str) {
  long long int ans = 0, d = 1;
  for (int i = str.length() - 1; i >= 0; i--) {
    ans += d * (str[i] - 48);
    d *= 2;
  }
  return ans;
}
double round(double var) {
  double value = (long long int)(var * 100 + .5);
  return (double)value / 100;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  string str;
  cin >> str;
  long long int len = str.length(), ans = (len * (len + 1)) / 2;
  for (int i = 0; i < len; i++) {
    string ptr;
    for (int j = i; j < i + 10; j++) {
      if (j >= len) break;
      ptr.push_back(str[j]);
      long long int f = 0;
      for (int i = 0; i < ptr.length(); i++) {
        for (int j = i + 1; j < ptr.length(); j++) {
          if (ptr[i] == ptr[j] && (j - i) % 2 == 0 &&
              ptr[i + ((j - i) / 2)] == ptr[i])
            f += 1;
        }
      }
      if (f == 0) ans -= 1;
    }
  }
  cout << ans;
  return 0;
}

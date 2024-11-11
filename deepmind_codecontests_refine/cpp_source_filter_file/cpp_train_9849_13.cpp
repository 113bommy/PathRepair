#include <bits/stdc++.h>
using namespace std;
long long todec(string& num, int b) {
  long long dec = num[0] - (isupper(num[0]) ? 'A' - 10 : '0');
  for (int i = 1; num[i]; i++) {
    if (num[i] >= 'A' && num[i] <= 'Z')
      num[i] -= 'A' - 10;
    else
      num[i] -= '0';
    dec *= b;
    dec += num[i];
  }
  return dec;
}
long long modpow(long long x, long long y, long long m) {
  if (y == 0) return 1;
  long long p = modpow(x, y / 2, m) % m;
  p = (p * p) % m;
  return ((y & 1) ? (x * p) % m : p);
}
long long ncr(int n, int k) {
  long long res = 1;
  if (k > n - k) k = n - k;
  for (int i = 0; i < k; i++) {
    res *= n - i;
    res /= i + 1;
  }
  return res;
}
int phi(int n) {
  int ret = n;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      while (n % i == 0) {
        n /= i;
      }
      ret -= ret / i;
    }
  }
  if (n > 1) ret -= ret / n;
  return ret;
}
int egcd(int a, int b, int& x, int& y) {
  if (a == 0) {
    x = 0;
    y = 1;
    return b;
  }
  int x1, y1;
  int gcd = egcd(b % a, a, x1, y1);
  x = y1 - (b / a) * x1;
  y = x1;
  return gcd;
}
string z[2] = {"NO", "YES"};
int main() {
  ios_base::sync_with_stdio(false);
  int n, k, i, j, prev = 1, nxt = 2, cur = 2;
  cin >> n >> k;
  cout << (n + k - 3) / k + (n + k - 2) / k << "\n";
  for (i = 0; i < (n - 1) % k; ++i) {
    prev = 1, nxt = cur;
    j = 0;
    while (cur <= n && j < (n + k - 2) / k) {
      cout << prev << " " << nxt << "\n";
      prev = cur++, nxt = cur, ++j;
    }
  }
  for (; i < k; ++i) {
    prev = 1, nxt = cur;
    j = 0;
    while (cur <= n && j < (n + k - 3) / k) {
      cout << prev << " " << nxt << "\n";
      prev = cur++, nxt = cur, ++j;
    }
  }
  return 0;
}

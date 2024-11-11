#include <bits/stdc++.h>
using namespace std;
bool is_prime(int n) {
  for (int i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}
inline long long getPow(long long a, long long b) {
  long long res = 1, tp = a;
  while (b) {
    if (b & 1ll) {
      res *= tp;
      res %= 1000000007;
    }
    tp *= tp;
    tp %= 1000000007;
    b >>= 1ll;
  }
  return res;
}
inline long long to_ll(string s) {
  long long cur = 0;
  for (int i = 0; i < s.size(); i++) {
    cur = cur * 10 + s[i] - '0';
  }
  return cur;
}
inline string to_str(long long x) {
  string s = "";
  while (x) {
    s += char(x % 10 + '0');
    x /= 10;
  }
  reverse(s.begin(), s.end());
  return s;
}
inline long long nxt() {
  long long x;
  scanf("%lld", &x);
  return x;
}
void ok() {
  puts("YES");
  exit(0);
}
void panic() {
  puts("NO");
  exit(0);
}
const long long N = 1e6 + 5;
long long value(long long d) {
  if (d == 0) {
    return 2;
  }
  if (d == 1) {
    return 6;
  }
  if (d == 2) {
    return 2;
  }
  if (d == 3) {
    return 3;
  }
  if (d == 4) {
    return 3;
  }
  if (d == 5) {
    return 3;
  }
  if (d == 6) {
    return 2;
  }
  if (d == 7) {
    return 5;
  }
  if (d == 8) {
    return 1;
  }
  if (d == 9) {
    return 2;
  }
}
int main() {
  long long n = nxt();
  cout << value(n % 10) * value(n / 10);
  return 0;
}

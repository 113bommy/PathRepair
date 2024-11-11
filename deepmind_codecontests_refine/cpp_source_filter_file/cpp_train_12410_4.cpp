#include <bits/stdc++.h>
using namespace std;
int64_t checkpalindrome(int64_t c) {
  string p = to_string(c);
  int j = p.size() - 1;
  for (int i = 0; i < j; i++, j--) {
    if (p[i] != p[j]) {
      return 0;
    }
  }
  return 1;
}
int max(int a, int b) { return (a > b) ? a : b; }
int64_t binaryToDecimal(int64_t n) {
  int64_t num = n;
  int64_t dec_value = 0;
  int64_t base = 1;
  int64_t temp = num;
  while (temp) {
    int last_digit = temp % 10;
    temp = temp / 10;
    dec_value += (last_digit * base) % 1000003;
    base = base * 2;
  }
  return dec_value;
}
bool isprime(int64_t n) {
  if (n == 1) return true;
  if (n == 2 || n == 3) return true;
  if (n % 2 == 0) return false;
  for (int64_t i = 3; i * i <= n; i += 2) {
    if (n % i == 0) return false;
  }
  return true;
}
int gcd(int64_t a, int64_t b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
int lcm(int64_t a, int64_t b) { return a * (b / gcd(a, b)); }
set<int64_t> fac;
int64_t checkfactors(int64_t n) {
  int i;
  for (i = 1; i <= sqrt(n); i++) {
    if (n % i != 0) {
      return i;
    }
  }
  return i + 1;
}
void allFactors(int64_t n) {
  for (int64_t i = 1; i <= sqrt(n); i++) {
    if (n % i == 0) {
      fac.insert(i);
      if (i != n / i) {
        fac.insert(n / i);
      }
    }
  }
}
bool threefactors(int64_t n) {
  int64_t p = sqrt(n);
  if (p * p == n) {
    if (isprime(p))
      return 1;
    else
      return 0;
  } else
    return 0;
}
int64_t sum(int64_t n) {
  int s;
  for (s = 0; n > 0; s += n % 10, n /= 10)
    ;
  return s;
}
bool isPowerOfTwo(int64_t n) {
  if (n == 0) return false;
  return (ceil(log2(n)) == floor(log2(n)));
}
int64_t myXOR(int64_t x, int64_t y) { return (x | y) & (~x | ~y); }
int f(int n) {
  int count = 0;
  for (int i = 5; n / i >= 1; i *= 5) {
    count += n / i;
  }
  return count;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int64_t t;
  cin >> t;
  while (t--) {
    int n, k1, k2;
    int mx1 = -1, mx2 = -1;
    cin >> n >> k1 >> k2;
    for (int i = 0; i < k1; i++) {
      int x;
      cin >> x;
      mx2 = max(mx2, x);
    }
    for (int i = 0; i < k2; i++) {
      int x;
      cin >> x;
      mx2 = max(mx2, x);
    }
    if (mx1 > mx2)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}

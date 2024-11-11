#include <bits/stdc++.h>
using namespace std;
const long double PI = 3.1415926535897932384626433832795L;
const long double EPS = 1e-9;
long long gcd(long long a, long long b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
long long lcm(const long long a, const long long b) {
  return a / gcd(a, b) * b;
}
long long sign(const long long x) { return (x > 0) - (x < 0); }
template <class T>
const T sqr(const T x) {
  return x * x;
}
template <class T>
const T binpow(const T a, const unsigned long long n, const T modulo) {
  return n == 0 ? 1
                : sqr(binpow(a, n / 2, modulo)) % modulo * (n % 2 ? a : 1) %
                      modulo;
}
const int MAXN = 123;
int c[MAXN];
int main() {
  ios::sync_with_stdio(false);
  int n, k, x;
  cin >> n >> k >> x;
  for (int i = 0; i < n; ++i) {
    cin >> c[i];
  }
  int result = 0;
  for (int i = 0; i < n - 1; ++i) {
    if (c[i] != x || c[i + 1] != x) {
      continue;
    }
    int left = i, right = i + 1;
    int current = 0;
    while (left >= 0 && right < n && c[left] == c[right]) {
      int left_begin = left;
      int right_begin = right;
      for (; left >= 0 && c[left] == c[left_begin]; --left)
        ;
      for (; right < n && c[right] == c[right_begin]; ++right)
        ;
      ++left;
      --right;
      int add = left_begin - left + 1 + right - right_begin + 1;
      if (right_begin - left_begin == 1) {
        current += add + 1;
      } else if (add >= 3) {
        current += add;
      } else {
        break;
      }
      --left;
      ++right;
    }
    result = max(result, current);
  }
  cout << result << endl;
  return 0;
}

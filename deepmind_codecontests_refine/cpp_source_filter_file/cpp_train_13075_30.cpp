#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int lcm(int a, int b) { return a * (b / gcd(a, b)); }
long long powi(long long base, long long exp, long long m) {
  long long res = 1;
  while (exp) {
    if (exp % 2) {
      res *= base;
      res %= m;
    }
    base *= base;
    base %= m;
    exp >>= 1;
  }
  return res % m;
}
int fact(int x) {
  int res = 1;
  for (int i = 2; i <= x; i++) {
    res *= i;
  }
  return res;
}
int main(int argc, const char* argv[]) {
  int n, m;
  string s, t;
  cin >> n >> m;
  cin >> s;
  cin >> t;
  int min = 2000, pos = -1;
  for (int i = 0; i < m; i++) {
    int val = 0;
    for (int j = i; j < (i + n); j++) {
      if (s[j - i] != t[j]) {
        val++;
      }
    }
    if (val < min) {
      min = val;
      pos = i;
    }
  }
  cout << min << endl;
  int i = pos;
  for (; i < (pos + n); i++) {
    if (t[i] != s[i - pos]) {
      cout << i - pos + 1 << " ";
    }
  }
  return 0;
}

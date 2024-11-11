#include <bits/stdc++.h>
using namespace std;
long long int pow(long long int a, long long int b, long long int m) {
  a %= m;
  long long int x = 1, y = a;
  while (b > 0) {
    if (b % 2 == 1) {
      x = (x * y);
      if (x > m) x %= m;
    }
    y = (y * y);
    if (y > m) y %= m;
    b /= 2;
  }
  return x % m;
}
long long int gcd(long long int a, long long int b) {
  if (a == 0) return b;
  if (b == 0) return a;
  if (a == b) return a;
  if (a > b) return gcd(a - b, b);
  return gcd(a, b - a);
}
long long int factorial(long long int x) {
  if (x <= 1)
    return 1;
  else {
    long long int t = 1;
    for (long long int i = 2; i <= x; i++) {
      t *= i;
    }
    return t;
  }
}
void run() {}
void solve() {
  string s;
  getline(cin, s);
  int n = s.length();
  int x = 0;
  for (int i = 1; i < n; i++) {
    if (int(s[n - i]) > 64) {
      x = i;
      break;
    }
  }
  if (s[n - x] == 'A' || s[n - x] == 'E' || s[n - x] == 'I' ||
      s[n - x] == 'O' || s[n - x] == 'U' || s[n - x] == 'Y' ||
      s[n - x] == 'a' || s[n - x] == 'e' || s[n - x] == 'i' ||
      s[n - x] == 'o' || s[n - x] == 'u' || s[n - x] == 'y') {
    cout << "YES";
    return;
  }
  cout << "NO";
}
int main() {
  run();
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ;
  solve();
}

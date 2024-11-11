#include <bits/stdc++.h>
using namespace std;
bool ispalindrome(string s) {
  long long l = s.length(), i;
  bool r = 0;
  for (i = 0; i < l / 2; i++) {
    if (s[i] == s[l - i - 1]) {
      r = 0;
      continue;
    } else {
      r = 1;
      break;
    }
  }
  if (r == 1)
    return false;
  else
    return true;
}
long long fact(long long n) { return (n == 1 || n == 0) ? 1 : n * fact(n - 1); }
void primefactors(long long n) {
  while (n % 2 == 0) {
    cout << "2"
         << " ";
    n /= 2;
  }
  for (long long i = 3; i <= sqrt(n); i = i + 2) {
    while (n % i == 0) {
      cout << i << " ";
      n /= i;
    }
  }
  if (n > 2) cout << n << " ";
}
long long check(string s1, string s2) {
  long long p = 0, i, x = s1.length();
  for (long long i = 0; i < x; i++) {
    if (s1[i] == s2[x - i - 1]) {
      p++;
    }
  }
  if (p == x)
    return 1;
  else
    return 0;
}
int main() {
  long long n, a, x, b, y, i, k = 0;
  vector<long long> v, v1;
  cin >> n >> a >> x >> b >> y;
  while (a != x && b != y) {
    if (a < n) {
      a++;
    } else {
      a = 1;
    }
    if (b > 1) {
      b--;
    } else {
      b = n;
    }
    if (a == b) {
      k = 1;
      break;
    }
  }
  if (k)
    cout << "YES\n";
  else
    cout << "NO\n";
}

#include <bits/stdc++.h>
long long int power(long long int a, long long int n) {
  long long int p = 1;
  while (n > 0) {
    if (n % 2) {
      p = p * a;
    }
    n >>= 1;
    a *= a;
  }
  return p;
}
long long int power(long long int a, long long int n, long long int mod) {
  long long int p = 1;
  while (n > 0) {
    if (n % 2) {
      p = p * a;
      p %= mod;
    }
    n >>= 1;
    a *= a;
    a %= mod;
  }
  return p % mod;
}
using namespace std;
int main() {
  string s;
  cin >> s;
  long long int n = s.length();
  long long int l = 0;
  long long int r = n - 1;
  long long int cnt = 0;
  while (l < r) {
    if (s[l] != '[') {
      l++;
      cnt++;
    }
    if (s[r] != ']') {
      r--;
      cnt++;
    }
    if (s[l] == '[' && s[r] == ']') break;
  }
  if (l >= r) {
    cout << -1 << endl;
    return 0;
  }
  l++;
  r--;
  while (l < r) {
    if (s[l] != ':') {
      l++;
      cnt++;
    }
    if (s[r] != ':') {
      r--;
      cnt++;
    }
    if (s[l] == ':' && s[r] == ':') break;
  }
  long long int i, j;
  if (l >= r) {
    cout << -1 << endl;
    return 0;
  }
  for (i = l + 1; i < r; i++) {
    if (s[i] != '|') {
      cnt++;
    }
  }
  cout << n - cnt << endl;
}

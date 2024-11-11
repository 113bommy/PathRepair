#include <bits/stdc++.h>
using namespace std;
int mod = 1000000007;
int func(int x) {
  int p = 1;
  for (int i = 0; i < x; i++) {
    p = p * 2 % mod;
  }
  return p;
}
int main() {
  string s;
  cin >> s;
  int n = s.length();
  long long int a = 0;
  for (int i = 0; i < n; i++) {
    a = a + func(n - i - 1) * (s[i] - 48);
  }
  a = a * func(n - 1) % mod;
  cout << a;
  return 0;
}

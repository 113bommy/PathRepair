#include <bits/stdc++.h>
using namespace std;
string s, s1;
long long n, m, r = 0;
int check(int k) {
  for (int i = 0; i < n; i++)
    if (s[i] != s[i % k]) return 0;
  for (int i = 0; i < m; i++)
    if (s1[i] != s1[i % k]) return 0;
  return 1;
}
int main() {
  cin >> s >> s1;
  n = s.length();
  m = s1.length();
  for (int i = 1; i <= min(n, m); i++) {
    if (n % i == 0 && m % i == 0) r = r + check(i);
  }
  cout << r;
  return 0;
}

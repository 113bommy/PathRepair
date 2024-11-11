#include <bits/stdc++.h>
using namespace std;
int dx[] = {-1, 0, 0};
int dy[] = {0, 1, -1};
long long mo = 1e9;
const long double P = 3.141592653589793238L;
void trust_your_self() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
long long gcd(long long x, long long y) {
  if (x == 0) return y;
  return gcd(y % x, x);
}
long long fast_power(long long x, long long y) {
  long long p = 1;
  while (y) {
    if (y % 2 != 0) p = (p * x);
    y /= 2;
    x = (x * x);
  }
  return p;
}
long long com(long long n, long long x) {
  long long p = 1, p1 = 1;
  for (int i = n; i > n - x; i--) p = p * i;
  for (int i = 1; i <= x; i++) p1 = p1 * i;
  return (p / p1);
}
int main() {
  trust_your_self();
  int t;
  cin >> t;
  while (t--) {
    string s;
    multiset<char> s1;
    cin >> s;
    if (s.size() == 1)
      cout << s << '\n';
    else {
      for (int i = 0; i < s.size(); i++) {
        if (s[i] != s[i + 1])
          s1.insert(s[i]);
        else {
          i++;
        }
      }
      for (auto it : s1) cout << it;
      cout << '\n';
    }
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-9;
const long double pi = acos(-1.0);
const long double inf = 1e+9;
long long gcd(long long a, long long b) { return (b == 0) ? a : gcd(b, a % b); }
int xabs(int a) { return a >= 0 ? a : -a; }
int sign(int a) { return (a < 0) ? -1 : 1; }
int main() {
  string s;
  cin >> s;
  int n = s.size();
  char ma = '1';
  string res;
  for (int i = 0; i < n; i++) {
    if (s[i] > ma) {
      ma = s[i];
      res = s[i];
      continue;
    }
    if (s[i] <= s[i - 1]) {
      res.push_back(s[i]);
      continue;
    }
    if (s[i] > s[i - 1]) {
      int j = res.size();
      while (j != 0 && res[j - 1] != s[i]) {
        j--;
        res.erase(--res.end());
      }
      res.push_back(s[i]);
      continue;
    }
  }
  cout << res << endl;
  return 0;
}

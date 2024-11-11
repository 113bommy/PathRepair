#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  long long m;
  cin >> s;
  cin >> m;
  int n = s.size();
  s += s;
  for (int i = 0; i < (int)(2 * n); i++) s[i] -= '0';
  long long p = 1;
  for (int i = 0; i < (int)(n - 1); i++) {
    p = p * 10 % m;
  }
  long long x = 0;
  for (int i = 0; i < (int)(n); i++) {
    x = (x * 10 + s[i]) % m;
  }
  long long res = x;
  for (int i = 0; i < (int)(n); i++) {
    x = (x - s[i] * p % m + m) % m;
    x = (x * 10 + s[i + n]) % m;
    if (s[i + 1] != 0) {
      res = min(res, x);
    }
  }
  cout << res;
}

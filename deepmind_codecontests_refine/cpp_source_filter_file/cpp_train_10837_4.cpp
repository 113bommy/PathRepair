#include <bits/stdc++.h>
const long long MXN = 1e5 + 12;
const double eps = 1e-10;
const double pi = acos(-1.0);
const long long OO = 1e18 + 1;
const int MNN = 1e5 + 1;
const int MOD = 1e9 + 7;
using namespace std;
string s;
int main() {
  ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0);
  ;
  cin >> s;
  int sz = s.size();
  for (int i = 1; i <= 100; i++) {
    int x = sz / i;
    if (sz % x > 0) x++;
    if (x > 20) {
      continue;
    }
    long long b = x, a = i;
    x = sz / i;
    long long k = a - (sz % x);
    if (sz % x == 0) x = 0;
    cout << a << " " << b << '\n';
    long long kek = 1, lol = 0;
    while (lol < sz) {
      if (kek % b == 0 && x > 0) {
        cout << '*' << '\n';
        k--;
        kek++;
        continue;
      }
      cout << s[lol];
      if (kek % b == 0) cout << '\n';
      kek++, lol++;
    }
    exit(0);
  }
  return 0;
}

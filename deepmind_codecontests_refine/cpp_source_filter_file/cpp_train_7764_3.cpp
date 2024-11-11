#include <bits/stdc++.h>
using namespace std;
long long x, n;
string s;
long long power_2[65];
void preprocess() {
  power_2[0] = 1;
  for (long long int i = 1; i < 50; i++) power_2[i] = power_2[i - 1] * 2;
}
string binary_rep(long long no) {
  string r = "";
  while (no) r += char('0' + no % 2), no /= 2;
  return r;
}
int solve() {
  preprocess();
  long long q;
  cin >> n >> q;
  while (q--) {
    cin >> x >> s;
    string rep = binary_rep(x);
    long long h = 0;
    while (rep[h] == '0') h++;
    for (long long int i = 0; i < (long long int)s.size(); i++) {
      if (x % 2 == 1 && (s[i] == 'L' || s[i] == 'R')) continue;
      if (x == (n + 1) / 2 && s[i] == 'U') continue;
      long long left = 0;
      if ((x & power_2[h + 1]) == 0) left = 1;
      if (s[i] == 'U') {
        if (left == 1)
          x += power_2[h];
        else
          x -= power_2[h];
        h++;
      } else {
        if (s[i] == 'L')
          x -= power_2[h - 1];
        else
          x += power_2[h - 1];
        h--;
      }
    }
    cout << x << "\n";
  }
  return 0;
}
int main() {
  auto start = chrono::high_resolution_clock::now();
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long test_cases = 1;
  while (test_cases--) solve();
  auto stop = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
}

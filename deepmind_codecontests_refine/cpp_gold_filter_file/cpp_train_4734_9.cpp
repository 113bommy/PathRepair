#include <bits/stdc++.h>
using namespace std;
long long int solve() {
  string t;
  getline(cin, t);
  char d;
  for (long long int i = 0; i < t.length(); i++)
    if (t[i] > 64 && t[i] < 91) t[i] += 32;
  for (long long int i = t.length() - 1; i >= 0; i--)
    if (t[i] > 96 && t[i] < 123) {
      d = t[i];
      break;
    }
  if (d == 'a' || d == 'e' || d == 'i' || d == 'o' || d == 'u' || d == 'y')
    return cout << "YES" << endl, 0;
  else
    return cout << "NO" << endl, 0;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int tests = 1;
  while (tests--) solve();
  return 0;
}

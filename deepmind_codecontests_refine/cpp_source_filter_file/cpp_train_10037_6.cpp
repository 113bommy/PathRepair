#include <bits/stdc++.h>
using namespace std;
long long int i, j, k;
const int N = 200 * 1000 + 9;
void solve() {
  string s;
  cin >> s;
  long long int n = (long long int)s.size();
  vector<long long int> str(n, 1);
  for (i = 1; i < n; i++) {
    if (s[i] == s[i - 1]) {
      str[i] = str[i - 1] + 1;
    }
  }
  long long int prev = 0;
  cout << s[0];
  for (i = 1; i < n; i++) {
    if (str[i] < 2)
      cout << s[i];
    else if (str[i] == 2 and prev < 2)
      cout << s[i];
    if (s[i] != s[i - 1])
      prev = str[i - 1];
    else if (s[i] == s[i - 1] and prev > 2)
      str[i] = 1;
  }
  return;
}
signed main() {
  solve();
  return 0;
}

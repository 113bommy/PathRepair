#include <bits/stdc++.h>
using namespace std;
const int N = 60;
string s[N];
int n, ans;
int main() {
  cin >> s[0];
  n = s[0].length() - 1;
  for (int i = 1, nn = int(n); i <= nn; ++i) {
    s[i] += s[i - 1][n];
    for (int j = 0, nn = int(n - 1); j <= nn; ++j) s[i] += s[i - 1][j];
  }
  sort(s, s + n);
  ans = 1;
  for (int i = 1, nn = int(n); i <= nn; ++i)
    if (s[i] != s[i - 1]) ++ans;
  cout << ans << endl;
  return 0;
}

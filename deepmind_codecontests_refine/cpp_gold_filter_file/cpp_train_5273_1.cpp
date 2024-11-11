#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
const long long MAXN = 1e5 + 5;
string s, t;
long long n;
bool solve() {
  if (t.size() != s.size()) return 0;
  for (int j = 0; j < s.size(); ++j) {
    if (s[j] == t[j]) continue;
    if (s[j] >= 'a' && s[j] <= 'z' && t[j] >= 'A' && t[j] <= 'Z')
      if (s[j] - 'a' == t[j] - 'A') continue;
    if (t[j] >= 'a' && t[j] <= 'z' && s[j] >= 'A' && s[j] <= 'Z')
      if (t[j] - 'a' == s[j] - 'A') continue;
    if (s[j] == '0' && (t[j] == 'o' || t[j] == 'O')) continue;
    if (t[j] == '0' && (s[j] == 'o' || s[j] == 'O')) continue;
    if (s[j] == '1' &&
        (t[j] == 'l' || t[j] == 'I' || t[j] == 'L' || t[j] == 'i'))
      continue;
    if (t[j] == '1' &&
        (s[j] == 'l' || s[j] == 'I' || s[j] == 'L' || s[j] == 'i'))
      continue;
    if ((s[j] == 'i' || s[j] == 'I') && (t[j] == 'L' || t[j] == 'l')) continue;
    if ((t[j] == 'i' || t[j] == 'I') && (s[j] == 'L' || s[j] == 'l')) continue;
    return 0;
  }
  return 1;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> s >> n;
  for (int i = 0; i < n; ++i) {
    cin >> t;
    if (solve()) {
      cout << "No";
      return 0;
    }
  }
  cout << "Yes";
  return 0;
}

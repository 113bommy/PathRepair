#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e6 + 9;
int n, m, kmp[N + N], z[N + N];
string s, t, s1, s2;
void buildKmpTable(string& s) {
  for (int i = 1; i < s.size(); ++i) {
    kmp[i] = kmp[i - 1];
    while (kmp[i] > 0 && s[i] != s[kmp[i]]) kmp[i] = kmp[kmp[i] - 1];
    if (s[i] == s[kmp[i]]) ++kmp[i];
  }
}
void buildZTable(string& s) {
  for (int i = 1, l, r = 0; i < s.size(); ++i) {
    if (r < i) {
      l = r = i;
      while (r < s.size() && s[r] == s[r - l]) ++r;
      z[i] = r - l;
    } else {
      if (i + z[i - l] < r)
        z[i] = z[i - l];
      else {
        l = i;
        while (r < s.size() && s[r] == s[r - l]) ++r;
        z[i] = r - l;
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  getline(cin, s), getline(cin, t);
  n = s.size(), m = t.size();
  if (n != m) {
    cout << "-1 -1";
    return 0;
  }
  s1 = s;
  reverse(s1.begin(), s1.end());
  s1 += '#' + t;
  s2 = t + '#' + s;
  buildKmpTable(s1);
  buildZTable(s2);
  int ans_i = -1, ans_j = -1;
  for (int i = 0, len; i + 1 < n; ++i) {
    if (s[i] != t[n - 1 - i]) break;
    len = kmp[n + n - 1 - i];
    if (z[n + i + 2] >= n - i - len - 1) ans_i = i, ans_j = n - len;
  }
  cout << ans_i << ' ' << ans_j << '\n';
}

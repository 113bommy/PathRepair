#include <bits/stdc++.h>
using namespace std;
vector<int> lps(string s) {
  int l = s.length();
  vector<int> ans(l, 0);
  int len = 0;
  for (int i = 1; i < l; i++) {
    while (len != 0 && s[i] != s[len]) {
      len = ans[len - 1];
    }
    if (s[i] == s[len]) {
      len++;
      ans[i] = len;
    }
  }
  return ans;
}
vector<int> z_function(string s) {
  int n = (int)s.length();
  vector<int> z(n);
  for (int i = 1, l = 0, r = 0; i < n; ++i) {
    if (i <= r) z[i] = min(r - i + 1, z[i - l]);
    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
    if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
  }
  return z;
}
int main() {
  string a, b;
  getline(cin, a);
  getline(cin, b);
  if (a.length() != b.length()) {
    cout << "-1 -1" << '\n';
    exit(0);
  }
  string ra = a;
  reverse(ra.begin(), ra.end());
  string rb = b;
  reverse(rb.begin(), rb.end());
  vector<int> lp = lps(ra + '\0' + b);
  vector<int> z = z_function(b + '\0' + a);
  vector<int> sec = lps(rb + '\0' + a);
  int l = a.length();
  int a1 = -1;
  int a2 = -1;
  for (int i = 0; i <= l - 2; i++) {
    int px = lp[l + l - i - 1];
    int j = l - px;
    int min_match = max(0, j - 1 - (i + 1) + 1);
    if (z[l + (i + 1) + 1] < min_match) continue;
    if (sec[l + i + 1] < i + 1) continue;
    a1 = i;
    a2 = j;
  }
  cout << a1 << " " << a2 << '\n';
}

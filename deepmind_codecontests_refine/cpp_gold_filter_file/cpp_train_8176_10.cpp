#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  cin >> s;
  int n = s.size();
  if (n < 26) {
    cout << -1 << "\n";
    return 0;
  }
  int l = -1;
  vector<int> m(26);
  int cnt = 0;
  for (int i = 0; i < 26; ++i) {
    if (s[i] == '?') {
      continue;
    }
    if (m[s[i] - 'A']++) {
      ++cnt;
    }
  }
  if (cnt == 0) {
    l = 0;
  }
  for (int i = 26; i < n && (cnt != 0); ++i) {
    char lc = s[i - 26];
    char rc = s[i];
    if (lc != '?' && m[lc - 'A']-- > 1) {
      --cnt;
    }
    if (rc != '?' && ++m[rc - 'A'] > 1) {
      ++cnt;
    }
    if (cnt == 0) {
      l = i - 26 + 1;
      break;
    }
  }
  if (l == -1) {
    cout << l << "\n";
    return 0;
  }
  vector<int> ind(n);
  vector<char> rem;
  for (int i = 0; i < 26; ++i) {
    if (m[i] == 0) {
      rem.push_back(i + 'A');
    }
  }
  int i = 0;
  for (int j = l; j < l + 26; ++j) {
    if (s[j] == '?') {
      s[j] = rem[i++];
    }
  }
  for (char &c : s) {
    if (c == '?') {
      c = 'A';
    }
  }
  cout << s << "\n";
  return 0;
}

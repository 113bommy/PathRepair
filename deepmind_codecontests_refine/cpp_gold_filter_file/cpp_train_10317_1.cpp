#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  int n, k;
  int m[char('z' + 1)];
  char sym[26];
  cin >> s;
  cin >> k;
  n = s.length();
  memset(m, 0, sizeof(m));
  for (int i = 0; i < n; i++) m[s[i]]++;
  for (int i = 0; i < 26; i++) sym[i] = char(i + 'a');
  for (char c = 'a'; c <= 'z' - 1; c = char(c + 1))
    for (char f = char(c + 1); f <= 'z'; f = char(f + 1))
      if (m[f] < m[c]) {
        int tmp = m[f];
        m[f] = m[c];
        m[c] = tmp;
        char tmpsym = sym[char(c) - 'a'];
        sym[char(c) - 'a'] = sym[char(f) - 'a'];
        sym[char(f) - 'a'] = tmpsym;
      }
  int j = 0;
  while (m[char(j + 'a')] <= k) {
    k -= m[char(j + 'a')];
    j++;
  }
  j--;
  bool fprint[char('z' + 1)];
  memset(fprint, false, sizeof(fprint));
  for (int i = j + 1; i < 26; i++) fprint[sym[i]] = true;
  cout << max(25 - j, 0) << endl;
  for (int i = 0; i < n; i++)
    if (fprint[s[i]]) cout << s[i];
  return 0;
}

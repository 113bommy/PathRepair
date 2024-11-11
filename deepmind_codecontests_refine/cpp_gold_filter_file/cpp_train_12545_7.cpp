#include <bits/stdc++.h>
using namespace std;
int main() {
  int k;
  string s;
  cin >> k >> s;
  int sz = s.size();
  bool used[26];
  for (int i = 0; i < k; i++) used[i] = false;
  for (int i = 0; i < sz; i++) {
    int idx = s[i] - 'a';
    if (idx >= k) {
      cout << "IMPOSSIBLE" << endl;
      return 0;
    }
    used[idx] = true;
  }
  queue<char> q;
  for (int i = k - 1; i >= 0; i--)
    if (!used[i]) q.push('a' + i);
  for (int i = 0; i < sz; i++) {
    char a = s[i], b = s[sz - 1 - i];
    if (a != '?' && b != '?') {
      if (a != b) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
      }
    } else if (a == '?' && b != '?')
      s[i] = b;
    else if (a != '?' && b == '?')
      s[sz - 1 - i] = a;
  }
  for (int i = sz / 2; i >= 0; i--) {
    if (s[i] == '?') {
      if (!q.empty()) {
        char ch = q.front();
        q.pop();
        s[i] = s[sz - 1 - i] = ch;
      } else
        break;
    }
  }
  if (!q.empty()) {
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }
  for (int i = 0; i <= sz / 2; i++)
    if (s[i] == '?') s[i] = s[sz - 1 - i] = 'a';
  cout << s << endl;
  return 0;
}

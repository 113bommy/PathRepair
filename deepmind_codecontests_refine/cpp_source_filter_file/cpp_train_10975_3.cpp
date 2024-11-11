#include <bits/stdc++.h>
using namespace std;
bool used[2 * 1000000 + 1];
int main() {
  cin.sync_with_stdio(false);
  string s;
  cin >> s;
  int n = s.length();
  if (s[n - 1] == 'L') {
    for (int i = 0; i < n; ++i)
      if (s[i] == 'L')
        s[i] = 'R';
      else
        s[i] = 'L';
  }
  memset(used, 0, sizeof used);
  int pos = 1000000;
  used[pos] = true;
  for (int i = 0; i < n - 1; ++i) {
    if (s[i] == 'L')
      --pos;
    else
      ++pos;
    used[pos] = true;
  }
  if (!used[pos + 1]) {
    cout << 1;
    return 0;
  }
  int l = 0, r = 1000000 - 1, m;
  while (l < r) {
    memset(used, 0, sizeof used);
    m = (l + r) / 2;
    int pos = 1000000;
    used[pos] = true;
    for (int i = 0; i < n - 1; ++i) {
      if (s[i] == 'L') {
        if (pos > m + 1) --pos;
      } else
        ++pos;
      used[pos] = true;
    }
    if (used[pos + 1])
      l = m + 1;
    else
      r = m;
  }
  cout << 1000000 - l;
  return 0;
}

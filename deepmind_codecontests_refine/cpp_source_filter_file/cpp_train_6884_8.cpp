#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  bool b1 = 0, b2 = 0;
  long long l1, l2;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == '[') {
      b1 = 1;
    }
    if (s[i] == ':' && b1) {
      b2 = 1;
      l1 = i;
      break;
    }
  }
  if (!b2) {
    cout << -1 << endl;
    return 0;
  }
  b1 = b2 = 0;
  for (int i = s.size() - 1; i > 0; --i) {
    if (s[i] == ']') {
      b1 = 1;
    }
    if (s[i] == ':' && b1) {
      b2 = 1;
      l2 = i;
      break;
    }
  }
  if (!b2) {
    cout << -1 << endl;
    return 0;
  }
  long long ans = 0;
  for (int i = l1 + 1; i < l2; ++i) {
    if (s[i] == '|') {
      ans++;
    }
  }
  cout << ans + 4 << endl;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j = 0, mx = -1, fromleft, fromright;
  string s, t;
  cin >> s >> t;
  int left[t.size()], right[t.size()];
  for (i = 0; i < s.size(); i++) {
    if (s[i] == t[j]) {
      left[j++] = i;
    }
    if (j == t.size()) {
      fromleft = s.size() - i - 1;
      break;
    }
  }
  j = t.size() - 1;
  for (i = s.size() - 1; i >= 0; i--) {
    if (s[i] == t[j]) {
      right[j--] = i;
    }
    if (j == -1) {
      fromright = i;
      break;
    }
  }
  for (i = 0; i < t.size() - 1; i++) {
    mx = max(mx, right[i + 1] - left[i] - 1);
  }
  cout << max({mx, fromleft, fromright}) << endl;
}

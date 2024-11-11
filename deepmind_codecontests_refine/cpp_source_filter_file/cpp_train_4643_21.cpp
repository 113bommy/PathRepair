#include <bits/stdc++.h>
using namespace std;
int minn[100005];
vector<int> t;
int main() {
  string s;
  cin >> s;
  minn[s.size() - 1] = s[s.size() - 1];
  for (int i = s.size() - 2; i >= 0; i--) {
    minn[i] = min(minn[i + 1], (int)s[i]);
  }
  for (int i = 0; i < s.size(); i++) {
    if ((t.empty() || minn[i] <= t[t.size() - 1]) && s[i] == minn[i]) {
      putchar(s[i]);
    } else if (!t.empty() && minn[i] >= t[t.size() - 1]) {
      putchar(t[t.size() - 1]);
      t.pop_back();
      i--;
    } else {
      t.push_back(s[i]);
    }
  }
  while (!t.empty()) {
    putchar(t[t.size() - 1]);
    t.pop_back();
  }
  return 0;
}

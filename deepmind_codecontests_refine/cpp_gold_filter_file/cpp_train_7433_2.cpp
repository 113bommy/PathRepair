#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios_base::sync_with_stdio(false);
  stack<bool> wire;
  string s;
  cin >> s;
  int n = s.size();
  for (int i = 0; i < n; i++) {
    bool next = true;
    if (s[i] == '-') next = false;
    if (wire.empty())
      wire.push(next);
    else {
      if (wire.top() == next)
        wire.pop();
      else
        wire.push(next);
    }
  }
  if (wire.empty()) {
    cout << "Yes" << endl;
  } else
    cout << "No" << endl;
  return 0;
}

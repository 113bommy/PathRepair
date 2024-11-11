#include <bits/stdc++.h>
using namespace std;
string inverse(string cmd) {
  if (cmd == ">") {
    return "<=";
  }
  if (cmd == ">=") {
    return "<";
  }
  if (cmd == "<") {
    return ">=";
  }
  if (cmd == "<=") {
    return ">";
  }
}
int main() {
  int l = -2000000000, r = 2000000000, n;
  string cmd, ans;
  int x;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> cmd >> x >> ans;
    if (ans == "N") {
      cmd = inverse(cmd);
    }
    if (cmd == ">") {
      l = max(x + 1, l);
    }
    if (cmd == ">=") {
      l = max(x, l);
    }
    if (cmd == "<") {
      r = min(x - 1, r);
    }
    if (cmd == "<=") {
      r = min(x, r);
    }
  }
  if (l > r)
    cout << "Impossible";
  else
    cout << l;
  return 0;
}

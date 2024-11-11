#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int a;
  string s;
  cin >> a;
  for (int i = a + 1; i <= 9123; ++i) {
    set<char> sc;
    s = to_string(i);
    for (char c : s) sc.insert(c);
    if (sc.size() == s.size()) {
      cout << s;
      break;
    }
  }
  return 0;
}

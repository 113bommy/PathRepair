#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    stack<char> a;
    int l = s.size();
    a.push(s[0]);
    for (int i = 1; i < l; i++) {
      if (a.empty()) {
        a.push(s[i]);
        continue;
      }
      if ((s[i] == 'B' && a.top() == 'A') || (s[i] == 'B' && a.top() == 'B'))
        a.pop();
      else
        a.push(s[i]);
    }
    if (a.empty())
      cout << 0;
    else
      cout << a.size() << endl;
  }
}

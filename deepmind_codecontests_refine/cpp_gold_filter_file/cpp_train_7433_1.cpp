#include <bits/stdc++.h>
using namespace std;
stack<char> t;
string s;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> s;
  for (int i = 0; i < s.length(); i++) {
    if (!t.size() || s[i] - t.top()) {
      t.push(s[i]);
    } else {
      t.pop();
    }
  }
  if (t.size()) {
    cout << "No"
         << "\n";
  } else {
    cout << "Yes"
         << "\n";
  }
  return 0;
}

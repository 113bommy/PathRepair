#include <bits/stdc++.h>
using namespace std;
int main() {
  int c = 0;
  stack<int> st;
  string s;
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '(')
      st.push(s[i]);
    else if (st.size() > 0) {
      st.pop();
      c += 2;
    }
    cout << c << endl;
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  stack<pair<int, int>> st;
  for (int i = 0; i < s.size(); i++) {
    if (st.size() == 0) {
      st.push(make_pair(s[i], i));
    } else if (s[i] == '0' && st.top().first == 1) {
      st.pop();
    } else {
      st.push(make_pair(s[i] - '0', i));
    }
  }
  while (!st.empty()) {
    s[st.top().second] = '0';
    st.pop();
  }
  cout << s;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  string s;
  cin >> s;
  vector<long long> vis(s.length(), 1);
  stack<long long> st;
  for (int i = 0; i < s.length(); ++i) {
    if (s[i] == '1')
      st.push(i);
    else {
      if (!st.empty() && s[st.top()] == '1')
        st.pop();
      else
        st.push(i);
    }
  }
  while (!st.empty()) {
    vis[st.top()] = 0;
    st.pop();
  }
  for (int i = 0; i < s.length(); ++i) {
    if (vis[i])
      cout << s[i];
    else if (s[i] == '0')
      cout << s[0];
    else {
      cout << 0;
    }
  }
  return 0;
}

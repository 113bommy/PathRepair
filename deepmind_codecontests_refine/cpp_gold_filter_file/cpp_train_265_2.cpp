#include <bits/stdc++.h>
using namespace std;
int n, i;
string s, c = "#";
stack<char> st, tt;
int main() {
  cin >> n >> s;
  s = '/' + s;
  s = s + '/';
  for (i = 1; i <= s.size() - 3; i++) {
    if (s[i] == s[i + 1] && s[i] != s[i - 1] && s[i] != s[i + 2] &&
        (s[i] == 'o' || s[i] == 'e')) {
      s.insert(i + 1, c);
      i++;
    }
  }
  for (i = 0; i < s.size(); i++) {
    st.push(s[i]);
  }
  tt.push(st.top());
  st.pop();
  while (!st.empty()) {
    if (tt.top() == st.top() &&
        (tt.top() == 'a' || tt.top() == 'e' || tt.top() == 'i' ||
         tt.top() == 'o' || tt.top() == 'u' || tt.top() == 'y'))
      st.pop();
    else {
      tt.push(st.top());
      st.pop();
    }
  }
  while (!tt.empty()) {
    if (tt.top() == '#' || tt.top() == '/')
      tt.pop();
    else {
      cout << tt.top();
      tt.pop();
    }
  }
}

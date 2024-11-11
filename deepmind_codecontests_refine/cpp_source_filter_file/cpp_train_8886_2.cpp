#include <bits/stdc++.h>
using namespace std;
int low(int a) {
  if (a == 1) {
    return 0;
  }
  return 1;
}
int main() {
  int t;
  cin >> t;
  string s;
  cin >> s;
  stack<char> st;
  st.push(s[0]);
  int c = 0;
  for (int i = 1; i < t; i++) {
    if (st.top() != s[i]) {
      c++;
    } else {
      st.push(s[i]);
    }
  }
  cout << c;
}

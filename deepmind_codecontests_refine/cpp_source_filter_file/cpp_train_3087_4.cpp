#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  set<char> st;
  st.insert('a');
  st.insert('e');
  st.insert('i');
  st.insert('y');
  st.insert('o');
  st.insert('u');
  string res = "";
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (st.count(s[i])) {
      cnt++;
      if (cnt == 2) {
        cnt = 0;
      } else {
        res = res + s[i];
      }
    } else {
      cnt = 0;
      res = res + s[i];
    }
  }
  cout << res;
  return 0;
}

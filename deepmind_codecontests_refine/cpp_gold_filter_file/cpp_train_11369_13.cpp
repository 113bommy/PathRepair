#include <bits/stdc++.h>
using namespace std;
char s[1009];
int main() {
  string s;
  cin >> s;
  int n = s.length();
  stack<pair<string, int> > st;
  int i = 0, c = 0;
  while (i < n) {
    string str = "";
    if (s[i + 1] == '/') {
      for (int j = i; j < i + 4; j++) str += s[j];
      i += 4;
      for (int j = 1; j <= 2 * st.top().second; j++) cout << " ";
      cout << str << endl;
      c = st.top().second;
      st.pop();
    } else {
      for (int j = i; j < i + 3; j++) str += s[j];
      i += 3;
      st.push(make_pair(str, c));
      for (int j = 1; j <= 2 * c; j++) cout << " ";
      cout << str << endl;
      c++;
    }
  }
  return 0;
}

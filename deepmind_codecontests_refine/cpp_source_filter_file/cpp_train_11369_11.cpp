#include <bits/stdc++.h>
using namespace std;
int main() {
  stack<char, vector<char> > st;
  string str;
  cin >> str;
  for (int i = 0; i < str.size(); i++) {
    if (str[i] >= 'a' && str[i] <= 'z') {
      if (st.empty() || st.top() != str[i] ||
          (st.top() == str[i] && str[i - 1] == '/')) {
        for (int j = 0; j < 2 * st.size(); j++) cout << " ";
        st.push(str[i]);
        cout << "<" << str[i] << ">" << endl;
      } else {
        st.pop();
        for (int j = 0; j < 2 * st.size(); j++) cout << " ";
        cout << "</" << str[i] << ">" << endl;
      }
    }
  }
  return 0;
}

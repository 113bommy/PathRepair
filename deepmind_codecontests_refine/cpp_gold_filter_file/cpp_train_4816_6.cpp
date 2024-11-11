#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    stack<char> st;
    long long int n;
    string s;
    cin >> n >> s;
    for (long long int i = 0; i < n; i++) {
      if (st.empty()) {
        st.push(s[i]);
      } else if (st.top() == '(' && s[i] == ')') {
        st.pop();
      } else {
        st.push(s[i]);
      }
    }
    cout << st.size() / 2 << endl;
  }
  return 0;
}

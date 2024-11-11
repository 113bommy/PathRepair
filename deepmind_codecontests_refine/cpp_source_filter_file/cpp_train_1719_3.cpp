#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int size = s.length();
  int a[1000002] = {0};
  std::stack<int> st;
  for (int i = 0; i < size; i++) {
    if (s[i] == '(') {
      st.push(i);
    } else {
      if (!st.empty()) {
        int tp = st.top();
        st.pop();
        a[tp] = 1;
        a[i] = 1;
      }
    }
  }
  int temp = 0, mx = 0, count = 0;
  for (int i = 0; i < size; i++) {
    if (a[i] == 1) {
      a[i] += (i - 1 >= 0 ? a[i - 1] : 1);
      mx = max(mx, a[i]);
    }
  }
  for (int i = 0; i < size; i++) {
    if (a[i] == mx && mx != 0) {
      count++;
    }
  }
  if (mx != 0)
    cout << mx << " " << count;
  else
    cout << "0"
         << " "
         << "1";
  return 0;
}

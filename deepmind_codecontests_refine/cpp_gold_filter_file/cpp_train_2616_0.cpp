#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, t, stagemax, mx = 0, i;
  cin >> n;
  stack<int> st;
  for (i = 0; i < n; i++) {
    cin >> t;
    if (st.empty()) {
      st.push(t);
      stagemax = 0;
    } else {
      if (st.top() == t && t >= stagemax) {
        st.pop();
        stagemax = t;
        if (mx < stagemax) {
          mx = stagemax;
        }
      } else {
        st.push(t);
        stagemax = 0;
      }
    }
  }
  if (!st.empty() && st.size() == 1 && st.top() < mx) {
    cout << "NO";
  } else if (st.size() > 1) {
    cout << "NO";
  } else {
    cout << "YES";
  }
  return 0;
}

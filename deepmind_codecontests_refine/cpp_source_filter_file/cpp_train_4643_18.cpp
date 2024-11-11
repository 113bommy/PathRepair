#include <bits/stdc++.h>
using namespace std;
void solve_this() {
  long long int i, n, j, k, chk, l;
  string str;
  cin >> str;
  n = str.size();
  stack<char> st;
  l = 0;
  for (i = 'a'; i <= 'z'; i++) {
    while (!st.empty() && st.top() == i) {
      cout << st.top();
      st.pop();
    }
    chk = 0;
    for (j = n - 1; j >= l; j--) {
      if (str[j] == i) {
        chk = 1;
        break;
      }
    }
    if (chk == 1) {
      for (k = l; k <= j; k++) {
        if (str[k] != i)
          st.push(str[k]);
        else
          cout << (char)i;
      }
      l = j + 1;
    }
  }
  while (!st.empty()) {
    cout << st.top();
    st.pop();
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve_this();
  return 0;
}

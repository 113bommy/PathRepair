#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, p;
  cin >> n >> m >> p;
  string s;
  cin >> s;
  s = "(" + s + ")";
  int l[n + 2], r[n + 2];
  for (int i = 0; i < n + 2; i++) l[i] = i - 1, r[i] = i + 1;
  int v[n + 2];
  stack<int> st;
  for (int i = 0; i < n + 2; i++) {
    if (s[i] == '(')
      st.push(i);
    else {
      v[i] = st.top();
      v[st.top()] = i;
      st.pop();
    }
  }
  for (int i = 0; i < m; i++) {
    char c;
    cin >> c;
    if (c == 'L')
      p = l[p];
    else if (c == 'R')
      p = r[p];
    else {
      if (s[p] == '(') {
        l[r[v[p]]] = l[p];
        r[l[p]] = r[v[p]];
        p = r[l[p]];
        if (p == n + 1) p = l[p];
      } else {
        l[r[p]] = l[v[p]];
        r[l[v[p]]] = r[p];
        p = r[p];
        if (p == n + 1) p = l[p];
      }
    }
  }
  for (int i = 0; i < n + 1; i = r[i]) {
    if (i) cout << s[i];
  }
  cout << endl;
}

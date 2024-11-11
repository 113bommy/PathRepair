#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int n = s.size();
  int c[n];
  int d[n];
  for (int i = 0; i < n; i++) {
    c[i] = -2;
    d[i] = -2;
  }
  stack<pair<int, int>> st;
  for (int i = 0; i < n; i++) {
    if (s[i] == '(') {
      st.push(make_pair(1, i));
    } else if (s[i] == '[') {
      st.push(make_pair(2, i));
    } else if (s[i] == ')') {
      if (st.empty() || st.top().first != 1) {
        c[i] = -1;
        d[i] = -1;
        while (!st.empty()) {
          st.pop();
        }
      } else {
        d[i] = st.top().second;
        st.pop();
        if (d[i] == 0) {
          c[i] = 0;
        } else if (s[d[i] - 1] == '(' || s[d[i] - 1] == '[') {
          c[i] = d[i];
        } else if (c[d[i] - 1] == -1) {
          c[i] = d[i];
        } else {
          c[i] = c[d[i] - 1];
        }
      }
    } else {
      if (st.empty() || st.top().first != 2) {
        c[i] = -1;
        d[i] = -1;
        while (!st.empty()) {
          st.pop();
        }
      } else {
        d[i] = st.top().second;
        st.pop();
        if (d[i] == 0) {
          c[i] = 0;
        } else if (s[d[i] - 1] == '(' || s[d[i] - 1] == '[') {
          c[i] = d[i];
        } else if (c[d[i] - 1] == -1) {
          c[i] = d[i];
        } else {
          c[i] = c[d[i] - 1];
        }
      }
    }
  }
  int pre[n];
  if (s[0] == '[') {
    pre[0] = 1;
  } else {
    pre[0] = 0;
  }
  for (int i = 0; i < n - 1; i++) {
    if (s[i] == '[') {
      pre[i] = pre[i - 1] + 1;
    } else {
      pre[i] = pre[i - 1];
    }
  }
  int maxi = 0;
  int point1 = 0;
  for (int i = 0; i < n - 1; i++) {
    if (c[i] == -2 || c[i] == -1) {
      continue;
    } else {
      int z = 0;
      if (c[i] == 0) {
        z = pre[i];
      } else {
        z = pre[i] - pre[c[i] - 1];
      }
      if (z > maxi) {
        point1 = i;
        maxi = z;
      }
    }
  }
  if (maxi == 0) {
    cout << 0;
    return 0;
  }
  cout << maxi << endl;
  for (int i = c[point1]; i <= point1; i++) {
    cout << s[i];
  }
  return 0;
}

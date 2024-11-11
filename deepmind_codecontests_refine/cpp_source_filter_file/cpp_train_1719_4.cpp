#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  unordered_map<int, int> m;
  stack<pair<char, int>> stk;
  int n = s.length();
  int res = INT_MIN, cnt = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '(') {
      stk.push({'(', i});
    } else {
      if (stk.empty() == false && stk.top().first == '(') {
        stk.pop();
        int j = -1;
        if (stk.empty() == false) j = stk.top().second;
        res = max(res, i - j);
        m[i - j]++;
      } else {
        stk.push({')', i});
      }
    }
  }
  if (res == 0)
    cout << "0 1";
  else {
    cout << res << " " << m[res];
  }
}

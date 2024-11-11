#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  stack<int> stk;
  cin >> s;
  for (int i = 0; i < s.length(); i++)
    if (s[i] == '0') {
      if (!stk.empty()) stk.pop();
    } else
      stk.push(i);
  while (!stk.empty()) {
    s[stk.top()] = '0';
    stk.pop();
  }
  cout << s << endl;
  return 0;
}

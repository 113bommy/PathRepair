#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int flag = 0, foo = 0;
  string s;
  cin >> s;
  stack<char> stk;
  int count = 0;
  for (int i = 0; i < s.length(); i++) {
    if (stk.empty() or stk.top() != s[i]) {
      stk.push(s[i]);
    } else {
      stk.pop();
      count++;
    }
  }
  if (count % 2)
    cout << "No";
  else
    cout << "Yes";
}

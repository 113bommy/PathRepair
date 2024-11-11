#include <bits/stdc++.h>
using namespace std;
bool result(char x) { return (x == '(' || x == '<' || x == '{' || x == '['); }
char result1(char x) {
  if (x == '>') return '<';
  if (x == ']') return '[';
  if (x == '}') return '{';
  if (x == ')') return '(';
}
int main() {
  stack<char> stk;
  string x;
  int res = 0;
  cin >> x;
  for (int i = 0; i < x.length(); i++) {
    if (result(x[i])) {
      stk.push(x[i]);
    } else {
      if (i == 0) {
        stk.push(x[i]);
        break;
      }
      if (stk.empty()) {
        cout << "impossible" << endl;
        return 0;
      }
      char a = result1(x[i]);
      char b = stk.top();
      if (b != a) {
        res++;
      }
      stk.pop();
    }
  }
  if (stk.empty()) {
    cout << res;
  } else {
    cout << "impossible" << endl;
    return 0;
  }
}

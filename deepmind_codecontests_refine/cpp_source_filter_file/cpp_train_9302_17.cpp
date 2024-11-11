#include <bits/stdc++.h>
using namespace std;
void printReverseStack(stack<int> &ans) {
  int x = ans.top();
  ans.pop();
  if (!ans.empty()) printReverseStack(ans);
  cout << x << " ";
}
int main() {
  int n, d, l, x;
  stack<int> ans;
  cin >> n >> d >> l;
  ans.push(d);
  while (ans.size() < n) {
    x = ans.top();
    ans.pop();
    if (x < 0) {
      ans.push(1);
      ans.push(1 - x);
    } else {
      ans.push(l);
      ans.push(l - x);
    }
  }
  if (ans.top() <= 0 || ans.top() > l)
    cout << -1;
  else
    printReverseStack(ans);
  return 0;
}

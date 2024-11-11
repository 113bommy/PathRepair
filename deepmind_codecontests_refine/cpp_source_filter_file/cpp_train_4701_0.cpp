#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  string a;
  cin >> a;
  if (n & 1) {
    cout << ":(";
    return 0;
  }
  int cnt1 = 1;
  int cnt2 = 1;
  if (a[0] == ')') {
    cout << ":(";
    return 0;
  }
  a[0] = '(';
  if (a[a.size()] == '(') {
    cout << ":(";
    return 0;
  }
  a[a.size() - 1] = ')';
  for (int i = 1; i < a.size(); ++i)
    if (a[i] == '(') ++cnt1;
  if (cnt1 > n / 2) {
    cout << ":(";
    return 0;
  }
  for (int i = 0; i < a.size(); ++i) {
    if (a[i] == '?') {
      ++cnt1;
      a[i] = '(';
    }
    if (cnt1 == n / 2) break;
  }
  if (cnt1 < n / 2) {
    cout << ":(";
    return 0;
  }
  for (int i = 0; i < a.size(); ++i)
    if (a[i] == '?') a[i] = ')';
  stack<int> s;
  for (int i = 0; i < a.size(); ++i) {
    if (a[i] == '(')
      s.push(a[i]);
    else {
      if (s.empty()) {
        cout << ":(";
        return 0;
      } else {
        s.pop();
        if (s.empty() && i != a.size() - 1) {
          cout << ":(";
          return 0;
        }
      }
    }
  }
  if (!s.empty()) {
    cout << ":(";
    return 0;
  }
  for (int i = 0; i < a.size(); ++i) cout << a[i];
  return 0;
}

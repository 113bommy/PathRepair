#include <bits/stdc++.h>
using namespace std;
int main() {
  stack<char> s;
  string s1;
  cin >> s1;
  int l = s1.length(), i, j, k;
  char c[l];
  c[l - 1] = s1[l - 1];
  for (i = l - 2; i >= 0; i--) {
    c[i] = min(s1[i], c[i + 1]);
  }
  for (i = 0; i < l; i++) {
    if (!s.empty() && c[i] >= s.top()) {
      cout << s.top();
      s.pop();
    }
    s.push(s1[i]);
  }
  while (!s.empty()) {
    cout << s.top();
    s.pop();
  }
  return 0;
}

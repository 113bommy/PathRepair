#include <bits/stdc++.h>
using namespace std;
string s, u;
stack<char> t;
char arr[100001];
int main() {
  cin >> s;
  arr[s.size() - 1] = s[s.size() - 1];
  for (int i = s.size() - 2; i >= 0; i--) arr[i] = min(arr[i + 1], s[i]);
  for (int i = 0; i < s.size(); i++) {
    while (!t.empty() and t.top() < arr[i]) {
      u += t.top();
      t.pop();
    }
    if (s[i] == arr[i])
      u += s[i];
    else
      t.push(s[i]);
  }
  cout << u;
  while (!t.empty()) {
    cout << t.top();
    t.pop();
  }
  return 0;
}

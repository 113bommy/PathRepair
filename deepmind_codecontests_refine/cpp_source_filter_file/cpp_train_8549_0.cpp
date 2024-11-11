#include <bits/stdc++.h>
using namespace std;
int main() {
  string t;
  cin >> t;
  int n = t.length();
  stack<char> s;
  int k;
  int p;
  for (int i = 0; i < n; i++) {
    p = 1;
    if ((!s.empty()) && (t[i] == s.top())) {
      s.pop();
      k++;
      p = 0;
    }
    if (p) {
      s.push(t[i]);
    }
  }
  if (k % 2 == 0) {
    cout << "NO";
  } else {
    cout << "YES";
  }
}

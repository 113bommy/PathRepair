#include <bits/stdc++.h>
using namespace std;
int n, m, T;
string s;
int ans[500];
int main() {
  cin >> n;
  cin >> s;
  int top = 0;
  int len = 0;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == 'W') {
      if (len != 0) {
        top++;
        ans[top] = len;
      }
      len = 0;
      continue;
    } else {
      len++;
    }
  }
  if (len != 0) {
    top++;
    ans[top] = len;
  }
  cout << top << endl;
  for (int i = 1; i <= top; i++) {
    cout << ans[top] << ' ';
  }
  return 0;
}

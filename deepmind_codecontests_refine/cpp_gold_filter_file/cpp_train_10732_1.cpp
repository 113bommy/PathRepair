#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int a;
  int b;
  cin >> a >> b;
  string s;
  string t;
  cin >> s >> t;
  int j = 0;
  if (a > (b + 1)) {
    cout << "NO";
    return 0;
  }
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '*') {
      j = 1;
    }
  }
  if (j == 0) {
    if (s == t) {
      cout << "YES";
      return 0;
    } else {
      cout << "NO";
      return 0;
    }
  }
  bool mark1 = false;
  bool mark2 = false;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '*') {
      i = s.size();
    } else if (s[i] != t[i]) {
      mark1 = true;
      i = s.size();
    }
  }
  if (mark1 == true) {
    cout << "NO";
    return 0;
  }
  int h = 0;
  for (int i = s.size() - 1; i >= 0; i--) {
    if (s[i] == '*') {
      i = -1;
    } else if (s[i] != t[(b - h) - 1]) {
      cout << "NO";
      return 0;
    }
    h++;
  }
  cout << "YES";
  return 0;
}

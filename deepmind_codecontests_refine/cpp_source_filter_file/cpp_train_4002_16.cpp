#include <bits/stdc++.h>
using namespace std;
int main() {
  bool ok1 = false, ok2 = false, ok3 = false, ok4 = false;
  string s;
  cin >> s;
  if (s.size() >= 5) {
    ok1 = true;
  }
  for (int i = 0; i < s.size(); i++) {
    if ('a' <= s[i] && s[i] >= 'z') {
      ok2 = true;
    }
    if ('A' <= s[i] && s[i] >= 'Z') {
      ok3 = true;
    }
    if ('0' <= s[i] && s[i] >= '9') {
      ok4 = true;
    }
  }
  if (ok1 && ok2 && ok3 && ok4) {
    cout << "Correct" << endl;
  } else {
    cout << "Too weak" << endl;
  }
  return 0;
}

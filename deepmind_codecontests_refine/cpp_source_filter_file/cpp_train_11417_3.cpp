#include <bits/stdc++.h>
using namespace std;
int N;
bool check(string s, int st, int dr) {
  for (int i = st; i <= (dr - st) / 2; i++) {
    if (s[i] != s[dr - i]) {
      return false;
    }
  }
  return true;
}
int main() {
  string s;
  cin >> s;
  if (!check(s, 0, s.length() - 1)) {
    cout << s.length() << endl;
  } else if (check(s, 0, s.length() - 1)) {
    if (check(s, 1, s.length() - 2) && check(s, 2, s.length() - 1)) {
      cout << "0" << endl;
    } else {
      cout << s.length() - 1 << endl;
    }
  }
  return 0;
}

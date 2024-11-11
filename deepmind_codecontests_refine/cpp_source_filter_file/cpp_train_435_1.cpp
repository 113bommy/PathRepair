#include <bits/stdc++.h>
using namespace std;
bool smaller(string a, string b) {
  if (b == "") return false;
  if (a == "") return true;
  if (a[0] < b[0]) return true;
  if (b[0] < a[0]) return false;
  return smaller(a.substr(1), b.substr(1));
}
string best(string s) {
  if (s.length() <= 1) return s;
  int best_index, i = -1;
  char best_char = 127;
  for (i = 0; i <= s.length() - 1; i++) {
    if (s[i] < best_char) {
      best_index = i;
      best_char = s[i];
    }
  }
  if (best_index != 0) {
    char tmp = s[best_index];
    s[best_index] = s[0];
    s[0] = tmp;
    return s;
  } else {
    string res = best(s.substr(1));
    return s[0] + res;
  }
}
int main() {
  int t, T, i;
  cin >> T;
  for (t = 1; t <= T; t++) {
    string s, c;
    cin >> s >> c;
    s = best(s);
    if (smaller(s, c)) {
      cout << s << endl;
    } else {
      cout << "---" << endl;
    }
  }
  return 0;
}

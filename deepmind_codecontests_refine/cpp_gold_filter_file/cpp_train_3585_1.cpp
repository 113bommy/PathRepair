#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int count = 0;
  for (int i = 0; i < s.size(); ++i) {
    if (isupper(s[i])) {
      ++count;
    }
  }
  cout << abs(n / 2 - count) << "\n";
  bool needUpper = false;
  if (count != n / 2) {
    if (count < n / 2) {
      needUpper = true;
    }
    for (int i = 0; i < s.size(); ++i) {
      if (count - n / 2 != 0) {
        if (needUpper && !isupper(s[i])) {
          s[i] = toupper(s[i]);
          count++;
        } else if (!needUpper && isupper(s[i])) {
          s[i] = tolower(s[i]);
          count--;
        }
      } else {
        break;
      }
    }
  }
  cout << s << endl;
}

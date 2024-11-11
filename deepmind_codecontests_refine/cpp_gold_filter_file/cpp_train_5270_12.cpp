#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
bool check(char t) {
  if (t == 'a' || t == 'e' || t == 'i' || t == 'o' || t == 'u') return 0;
  return 1;
}
int main() {
  string s;
  cin >> s;
  int n = s.size();
  int cnt = 0;
  char pr = '#';
  bool bad = 0;
  for (int i = 0; i < n; i++) {
    if (check(s[i])) {
      cnt++;
      if (pr != '#' && pr != s[i]) bad = 1;
      pr = s[i];
    } else {
      cnt = 0;
      pr = '#';
      bad = 0;
    }
    if (bad && cnt > 2) {
      cout << " ";
      pr = s[i];
      cnt = 1;
      bad = 0;
    }
    cout << s[i];
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int test() {
  string s;
  cin >> s;
  int n = s.size();
  bool b = false;
  for (long long i = 0; i < n - 2; i++) {
    if (s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'C') {
      b = true;
      break;
    }
    if (s[i] == 'A' && s[i + 1] == 'C' && s[i + 2] == 'B') {
      b = true;
      break;
    }
    if (s[i] == 'B' && s[i + 1] == 'A' && s[i + 2] == 'C') {
      b = true;
      break;
    }
    if (s[i] == 'B' && s[i + 1] == 'C' && s[i + 2] == 'B') {
      b = true;
      break;
    }
    if (s[i] == 'C' && s[i + 1] == 'B' && s[i + 2] == 'A') {
      b = true;
      break;
    }
    if (s[i] == 'C' && s[i + 1] == 'A' && s[i + 2] == 'B') {
      b = true;
      break;
    }
  }
  if (b)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
int hacker() { return 0; }
int main() {
  while (true) {
    return test();
    cout << "\n\n--";
    hacker();
    cout << "\n\n\n-----------------------------\n\n\n";
  }
  return 0;
}

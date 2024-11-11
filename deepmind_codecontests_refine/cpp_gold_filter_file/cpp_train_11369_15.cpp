#include <bits/stdc++.h>
using namespace std;
bool ok(string s) {
  int sz = s.size();
  for (int i = 0; i < sz; i++)
    if (s[i] == '/') return true;
  return false;
}
int main() {
  char ch;
  string cur;
  int h = 0;
  while (cin >> ch) {
    cur += ch;
    if (ch == '>') {
      if (!ok(cur)) h++;
      for (int i = 1; i < h; i++) cout << "  ";
      cout << cur << endl;
      if (ok(cur)) h--;
      cur = "";
    }
  }
  return 0;
}

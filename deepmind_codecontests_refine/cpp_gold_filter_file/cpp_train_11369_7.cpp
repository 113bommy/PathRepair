#include <bits/stdc++.h>
using namespace std;
void show(int h, char ch, bool b) {
  for (int i = 1; i <= h; i++) cout << " ";
  cout << '<';
  if (!b) cout << '/';
  cout << ch << ">\n";
}
int main() {
  vector<char> v;
  char ch;
  int i = 0, h = 0;
  while (cin >> ch) {
    if (ch != '<' && ch != '>') {
      if (ch == '/')
        i = -32;
      else {
        v.push_back(ch + i);
        i = 0;
      }
    }
  }
  for (i = 0; i < v.size(); i++) {
    if (v[i] > 96) {
      show(h, v[i], true);
      h += 2;
    } else {
      h -= 2;
      show(h, v[i] + 32, false);
    }
  }
  return 0;
}

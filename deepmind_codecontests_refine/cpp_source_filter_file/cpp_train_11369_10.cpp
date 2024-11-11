#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int state = 0;
  int next = 0;
  int curr = 0;
  for (int i = 0; i < s.length(); ++i) {
    curr = next;
    char c = s[i];
    int j = i;
    if (c == '<') {
      if (s[i + 1] == '/') {
        state = 2;
        ++i;
        ++j;
      } else {
        state = 1;
      }
    }
    while (j < s.length() && s[j] != '>') ++j;
    --j;
    string id = s.substr(i + 1, j - i);
    i = j + 1;
    if (state == 1) {
      ++next;
    } else {
      --next;
      --curr;
    }
    for (int i = 0; i < curr; ++i) {
      cout << ' ';
    }
    if (state == 1) {
      cout << "<";
    } else
      cout << "<\\";
    cout << id << ">" << endl;
  }
  return 0;
}

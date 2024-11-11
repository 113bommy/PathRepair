#include <bits/stdc++.h>
using namespace std;
bool special(const string& data) {
  int index = 0;
  while (index < data.size() && data[index] == ' ') index++;
  return index < data.size() && data[index] == '#';
}
int main() {
  string res;
  string data;
  bool simple = false;
  while (getline(cin, data)) {
    if (special(data)) {
      if (simple) {
        for (const auto& ch : res)
          if (ch != ' ') cout << ch;
        cout << '\n';
        res.clear();
        simple = false;
      }
      cout << data << '\n';
    } else {
      res += data;
      simple = true;
    }
  }
  if (simple) {
    for (const auto& ch : res)
      if (ch != ' ') cout << ch;
    cout << '\n';
  }
  return 0;
}

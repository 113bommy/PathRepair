#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int len = s.length();
  int count = 0;
  for (int i = 0; i < len; i++) {
    if (s[i] == '>') {
      for (int j = 0; j < count; j++) cout << " ";
      cout << s.substr(i - 2, 3) << endl;
      count++;
    } else if (s[i] == '/') {
      count--;
      for (int j = 0; j < count; j++) cout << " ";
      cout << s.substr(i - 1, 4) << endl;
      i = i + 2;
    }
  }
  return 0;
}

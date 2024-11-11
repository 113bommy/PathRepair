#include <bits/stdc++.h>
using namespace std;
int main() {
  string str;
  string str1;
  getline(cin >> ws, str);
  getline(cin >> ws, str1);
  int l1 = str1.length();
  int y = 0;
  for (int i = 0; i < l1; i++) {
    if (str1[i] == ' ') continue;
    size_t found = str.find(str1[i]);
    if (found == string::npos) {
      y = 1;
      break;
    } else {
      str.erase(found, 1);
    }
  }
  if (y == 0)
    puts("YES");
  else
    puts("NO");
}

#include <bits/stdc++.h>
using namespace std;
bool isdigit(char c) { return c >= '0' && c <= '9'; }
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string str;
    cin >> str;
    bool type2 = false;
    for (int i = 1; i < str.size(); i++)
      if (str[i] == 'C' && isdigit(str[i - 1])) type2 = true;
    if (!type2) {
      int nr1 = 0;
      int nr2 = 0;
      int i = 0;
      while (!isdigit(str[i]) && i < str.size()) {
        nr1 = (str[i] - 'A' + 1) + nr1 * 26;
        i++;
      }
      while (isdigit(str[i]) && i < str.size()) {
        nr2 = (str[i] - '0') + nr2 * 10;
        i++;
      }
      cout << 'R' << nr2 << 'C' << nr1 << endl;
    } else {
      int nr1 = 0;
      int nr2 = 0;
      int i = 1;
      while (isdigit(str[i]) && i < str.size()) {
        nr1 = (str[i] - '0') + nr1 * 10;
        i++;
      }
      i++;
      while (isdigit(str[i]) && i < str.size()) {
        nr2 = (str[i] - '0') + nr2 * 10;
        i++;
      }
      string str2 = "";
      while (nr2) {
        str2 += char((nr2 - 1) % 26 + 'A');
        nr2 = (nr2) / 26;
      }
      for (int i = 0; i < str2.size(); i++) cout << str2[str2.size() - i - 1];
      cout << nr1 << endl;
    }
  }
  return 0;
}

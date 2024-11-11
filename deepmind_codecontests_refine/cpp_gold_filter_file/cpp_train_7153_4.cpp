#include <bits/stdc++.h>
using namespace std;
map<char, int> m;
bool judge(string str) {
  int count = 0;
  for (int i = 0; i < 3; i++) {
    if (str[i] == '.') break;
    if (str[i] == 'A' && m['A'] == 0) {
      m['A'] = 1;
      count++;
    } else if (str[i] == 'B' && m['B'] == 0) {
      m['B'] = 1;
      count++;
    } else if (str[i] == 'C' && m['C'] == 0) {
      m['C'] = 1;
      count++;
    }
    if (count >= 3) return true;
  }
  return false;
}
int main() {
  string str;
  cin >> str;
  int siz = str.size();
  int count = 0;
  for (int i = 0; i <= siz - 3; i++) {
    m['A'] = 0;
    m['B'] = 0;
    m['C'] = 0;
    string sstr = str.substr(i, 3);
    if (judge(sstr)) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}

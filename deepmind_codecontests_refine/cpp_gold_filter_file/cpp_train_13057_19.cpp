#include <bits/stdc++.h>
using namespace std;
string f(int x) {
  string s = "";
  int k;
  do {
    k = x % 2;
    s = char('0' + k) + s;
    x /= 2;
  } while (x);
  return s;
}
int main() {
  ifstream ifs("t.txt");
  int t;
  cin >> t;
  string s, d = "6 1x12 2x6 3x4 4x3 6x2 12x1";
  for (int i = 0; i < t; i++) {
    cin >> s;
    set<char> st(s.begin(), s.end());
    if (st.size() == 1)
      if (st.count('X')) {
        cout << d << endl;
        continue;
      } else {
        cout << 0 << endl;
        continue;
      }
    vector<string> v;
    int c = 0;
    if (st.count('X')) {
      c++;
      v.push_back("1x12");
    }
    for (int j = 0; j < 6; j++)
      if (s[j] == 'X' && s[j + 6] == 'X') {
        c++;
        v.push_back("2x6");
        break;
      }
    for (int j = 0; j < 4; j++)
      if (s[j] == 'X' && s[j + 4] == 'X' && s[j + 8] == 'X') {
        c++;
        v.push_back("3x4");
        break;
      }
    for (int j = 0; j < 3; j++)
      if (s[j] == 'X' && s[j + 3] == 'X' && s[j + 6] == 'X' &&
          s[j + 9] == 'X') {
        c++;
        v.push_back("4x3");
        break;
      }
    for (int j = 0; j < 2; j++)
      if (s[j] == 'X' && s[j + 2] == 'X' && s[j + 4] == 'X' &&
          s[j + 6] == 'X' && s[j + 8] == 'X' && s[j + 10] == 'X') {
        c++;
        v.push_back("6x2");
        break;
      }
    cout << c << " ";
    for (int j = 0; j < v.size(); j++) cout << v[j] << " ";
    cout << endl;
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
char t[20] = {'8', '#', '#', '3', '6', '9', '4', '7', '0', '5'};
string s;
int main() {
  cin >> s;
  s = " " + s;
  for (int i = 1; i <= (s.size() - 1) / 2 + 1; i++) {
    if (t[s[i] - '0'] != s[s.size() - 1 - i + 1]) {
      cout << "No";
      return 0;
    }
  }
  cout << "Yes";
}

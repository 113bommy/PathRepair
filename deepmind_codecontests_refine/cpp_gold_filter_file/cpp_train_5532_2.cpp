#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int c = 0;
  string res;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '4' || s[i] == '7') c++;
  }
  res = to_string(c);
  for (int i = 0; i < res.size(); i++) {
    if (res[i] != '7' && res[i] != '4') {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES";
}

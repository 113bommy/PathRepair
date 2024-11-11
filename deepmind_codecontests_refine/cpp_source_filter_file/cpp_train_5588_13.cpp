#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  std::ios::sync_with_stdio(false);
  string s;
  cin >> s;
  int ind = s.find_first_of('.');
  if (s[ind - 1] == '9') {
    cout << "GOTO Vasilisa";
  } else {
    if (s[ind + 1] < '5') {
      cout << s.substr(0, ind);
    } else {
      string t = s.substr(0, ind);
      t[ind - 1] = t[ind - 1] - '0' + 1 + '0';
      cout << t;
    }
  }
  return 0;
}

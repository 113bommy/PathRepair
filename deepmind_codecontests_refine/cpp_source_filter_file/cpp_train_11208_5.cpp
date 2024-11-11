#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, flag = 0;
  string s;
  cin >> n >> s;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'x' && s[1] == 'x' && s[2] == 'x') flag++;
  }
  cout << flag << endl;
  return 0;
}

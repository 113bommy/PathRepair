#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> s;
  if (s[3] >= '6') s[3] = '0';
  if (n == 12) {
    if (s[0] != '0' && s[0] != '1' && s[1] == '0')
      s[0] = '1';
    else if (s[0] != '0' && s[0] != '1')
      s[0] = '0';
    if (s[1] > '2' && s[0] == '1' || (s[0] == '0' && s[1] == '0')) s[1] = '2';
  }
  if (n == 24) {
    if (s[0] != 0 && s[0] != '1' && s[0] != '2') s[0] = '0';
    if (s[1] > '3' && s[0] == '2') s[1] = '3';
  }
  cout << s;
  return 0;
}

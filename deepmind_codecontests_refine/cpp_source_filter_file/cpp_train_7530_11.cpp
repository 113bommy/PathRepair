#include <bits/stdc++.h>
using namespace std;
string s;
int xceptor() {
  cin >> s;
  int L = s.length(), mxind = 0;
  char qq = 'z';
  for (int i = 25; i >= 0; i--) {
    qq = 'a' + i;
    for (int j = 0; j < L; j++) {
      if (s[j] == qq && j > mxind) {
        cout << s[j];
        mxind = j;
      }
    }
  }
  return 0;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  return xceptor();
}

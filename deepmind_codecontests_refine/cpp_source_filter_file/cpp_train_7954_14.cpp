#include <bits/stdc++.h>
using namespace std;
string s;
int main() {
  cin >> s;
  int bas = 0;
  for (int i = 0; i < s.size(); ++i)
    if (s[i] == '^') bas = i;
  int cnt1 = 0, cnt2 = 0;
  for (int i = 0; i < bas; ++i)
    if (s[i] != '=') cnt1 = cnt1 + (bas - i) * (s[i] - '0');
  for (int i = bas; i < s.size(); ++i)
    if (s[i] != '=' && s[i] != '^') cnt2 = cnt2 + (i - bas) * (s[i] - '0');
  if (cnt1 > cnt2) {
    cout << "left" << endl;
    return 0;
  }
  if (cnt2 > cnt1) {
    cout << "right" << endl;
    return 0;
  }
  cout << "balance" << endl;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int white = 0;
  int black = 0;
  unordered_map<char, int> mp;
  mp['q'] = 9;
  mp['r'] = 5;
  mp['b'] = 3;
  mp['k'] = 3;
  mp['p'] = 1;
  for (int _ = 0; _ < 64; _++) {
    char c;
    cin >> c;
    if (c == '.') continue;
    if ('a' <= c && c <= 'z')
      black += mp[c];
    else if ('A' <= c && c <= 'Z')
      white += mp[tolower(c)];
  }
  if (white == black)
    cout << "Draw";
  else if (white > black)
    cout << "White";
  else
    cout << "Black";
  return 0;
}

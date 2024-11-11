#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  unordered_map<char, int> mp;
  mp['Q'] = 9;
  mp['q'] = 9;
  mp['R'] = 5;
  mp['r'] = 5;
  mp['B'] = 3;
  mp['b'] = 3;
  mp['N'] = 3;
  mp['n'] = 3;
  mp['P'] = 1;
  mp['p'] = 1;
  char m;
  int w = 0, b = 0;
  for (int i = 1; i <= 8; i++) {
    for (int j = 1; j <= 8; j++) {
      cin >> m;
      if (m != '.') {
        if (m >= 'A' && m <= 'Z')
          w += mp[m];
        else
          b += mp[m];
      }
    }
  }
  if (w > b)
    cout << "White";
  else if (b > w)
    cout << "Black";
  else
    cout << "Draw";
  return 0;
}

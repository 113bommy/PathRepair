#include <bits/stdc++.h>
using namespace std;
map<char, int> m;
int main() {
  m['q'] = 9;
  m['r'] = 5;
  m['b'] = 3;
  m['k'] = 3;
  m['p'] = 1;
  m['Q'] = 9;
  m['R'] = 5;
  m['B'] = 3;
  m['K'] = 3;
  m['P'] = 1;
  long long ans1 = 0, ans2 = 0;
  for (int i = 0; i < 8; i++)
    for (int j = 0; j < 8; j++) {
      char ch;
      cin >> ch;
      if (ch >= 'A' && ch <= 'Z')
        ans1 += m[ch];
      else
        ans2 += m[ch];
    }
  if (ans1 == ans2)
    cout << "Draw";
  else if (ans1 < ans2)
    cout << "Black";
  else
    cout << "White";
  return 0;
}

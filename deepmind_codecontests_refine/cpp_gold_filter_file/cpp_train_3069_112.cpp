#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  map<char, int> w, b;
  w['Q'] = 9;
  w['R'] = 5;
  w['B'] = 3;
  w['N'] = 3;
  w['P'] = 1;
  b['q'] = 9;
  b['r'] = 5;
  b['b'] = 3;
  b['n'] = 3;
  b['p'] = 1;
  int sw = 0, sb = 0;
  char c;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      cin >> c;
      sw += w[c];
      sb += b[c];
    }
  }
  if (sw == sb)
    cout << "Draw\n";
  else if (sw < sb)
    cout << "Black\n";
  else
    cout << "White\n";
  return 0;
}

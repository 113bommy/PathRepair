#include <bits/stdc++.h>
using namespace std;
int main() {
  string a;
  map<char, int> m;
  m['Q'] = m['q'] = 9;
  m['R'] = m['r'] = 5;
  m['B'] = m['b'] = 3;
  m['K'] = m['k'] = 3;
  m['P'] = m['p'] = 1;
  int b = 0, w = 0;
  for (int i = 0; i < 8; i++) {
    cin >> a;
    for (int i = 0; i < 8; i++) {
      if (isupper(a[i])) w += m[a[i]];
      if (islower(a[i])) b += m[a[i]];
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

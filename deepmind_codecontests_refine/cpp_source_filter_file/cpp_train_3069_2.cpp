#include <bits/stdc++.h>
using namespace std;
char sir[9], s;
int w, b;
unordered_map<char, int> m;
int main() {
  int i, j;
  m['Q'] = 9;
  m['R'] = 5;
  m['B'] = 3;
  m['N'] = 3;
  m['K'] = 1;
  m['q'] = 9;
  m['r'] = 5;
  m['b'] = 3;
  m['n'] = 3;
  m['k'] = 1;
  for (i = 1; i <= 8; i++) {
    for (j = 1; j <= 8; j++) {
      cin >> s;
      if (s < 'a') {
        w += m[s];
      } else
        b += m[s];
    }
  }
  if (w > b) {
    cout << "White";
  } else if (w < b) {
    cout << "Black";
  } else
    cout << "Draw";
  return 0;
}

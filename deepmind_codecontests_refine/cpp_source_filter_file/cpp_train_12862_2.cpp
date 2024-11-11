#include <bits/stdc++.h>
using namespace std;
int main(int argc, char** argv) {
  int a, c = 0;
  string l;
  cin >> a;
  char x[1000][5];
  for (int r = 0; r < a; r++) {
    cin >> l;
    for (int o = 0; o < 5; o++) x[r][o] = l.at(o);
  }
  for (int o = 0; o < a; o++) {
    if (x[o][0] == 'O' && x[o][1] == 'O') {
      c++;
      x[o][0] = '+';
      x[o][1] = '+';
      o = a;
    }
    if (x[o][2] == 'O' && x[o][3] == 'O') {
      c++;
      x[o][2] = '+';
      x[o][3] = '+';
      o = a;
    }
  }
  if (c = 0)
    cout << "NO";
  else {
    cout << "YES" << endl;
    for (int o = 0; o < a; o++) {
      for (int k = 0; k < 5; k++) cout << x[o][k];
      cout << endl;
    }
  }
  return 0;
}

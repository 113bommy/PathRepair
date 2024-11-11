#include <bits/stdc++.h>
using namespace std;
int a[2];
int val[1000];
int main() {
  val['Q'] = 9;
  val['R'] = 5;
  val['B'] = 3;
  val['N'] = 3;
  val['P'] = 1;
  val['K'] = 0;
  for (int i = 0; i < 8; i++)
    for (int j = 0; j < 8; j++) {
      char c;
      cin >> c;
      int k;
      if (c >= 'a') {
        k = 1;
        c -= 32;
      } else
        k = 0;
      a[k] += val[c];
    }
  if (a[0] == a[1])
    cout << "Draw" << endl;
  else if (a[0] > a[1])
    cout << "White" << endl;
  else
    cout << "Black" << endl;
}

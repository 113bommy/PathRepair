#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string a, b;
  cin >> a;
  cin >> b;
  int ca = 0, cb = 0, cc = 0;
  for (int i = 0; i < n * 2; i++) {
    if (a[i] == '1' && b[i] == '1')
      cc++;
    else if (a[i] == '1')
      ca++;
    else if (b[i] == '1')
      cb++;
  }
  if (ca > cb + 1 || ca == cb && (cc % 2) || ca == cb + 1 && (cc % 2 == 0))
    cout << "First" << endl;
  else if (cb > ca + 1 && (cc % 2 == 0) || cb > ca + 2)
    cout << "Second" << endl;
  else
    cout << "Draw" << endl;
}

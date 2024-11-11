#include <bits/stdc++.h>
using namespace std;
int main() {
  int goals;
  cin >> goals;
  string x;
  cin >> x;
  string y;
  string l;
  int ycount = 0;
  int xcount = 1;
  for (int i = 0; i < goals - 1; i++) {
    cin >> l;
    if (l == x)
      ++xcount;
    else {
      y = l;
      ++ycount;
    }
  }
  if (xcount > ycount)
    cout << x << "\n";
  else
    cout << l << "\n";
  return 0;
}

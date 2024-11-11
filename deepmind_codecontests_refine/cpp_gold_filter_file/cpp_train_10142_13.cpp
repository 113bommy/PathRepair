#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, awin = 0, bwin = 0;
  cin >> a >> b;
  for (int i = 1; i < 7; i++)
    if (abs(a - i) > abs(b - i))
      bwin++;
    else if (abs(a - i) < abs(b - i))
      awin++;
  cout << awin << " " << abs(6 - awin - bwin) << " " << bwin << endl;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  int cm, ft, in;
  cin >> cm;
  int p = cm % 3;
  cm = cm / 3 + (p == 2 ? 1 : 0);
  ft = cm / 12;
  cm %= 12;
  cout << ft << " " << cm << "\n";
  return 0;
}

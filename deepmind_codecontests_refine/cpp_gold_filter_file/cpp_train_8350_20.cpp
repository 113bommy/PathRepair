#include <bits/stdc++.h>
using namespace std;
int h, m, t, calcul;
int main() {
  cin >> t;
  for (int k = 1; k <= t; k++) {
    cin >> h >> m;
    calcul = (24 - h - 1) * 60 + 60 - m;
    cout << calcul << endl;
  }
}

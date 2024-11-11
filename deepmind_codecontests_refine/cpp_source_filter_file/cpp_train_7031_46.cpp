#include <bits/stdc++.h>
using namespace std;
int p[4];
int main() {
  int lo = 1e9;
  for (int i = 0; i < 4; i++) {
    cin >> p[i];
    lo = min(lo, p[i]);
  }
  int a, b;
  cin >> a >> b;
  lo = min(lo, b);
  cout << (lo - a > 0 ? lo - a : 0) << endl;
}

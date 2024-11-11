#include <bits/stdc++.h>
using namespace std;
int main() {
  int a1, a2, a3, a4, a5, a6;
  cin >> a1 >> a2 >> a3 >> a4 >> a5 >> a6;
  int res = (a1 + a2 + a3) * (a1 + a2 + a3) - a1 * a1 - a5 * a5 - a3 * a3;
  cout << res;
  return 0;
}

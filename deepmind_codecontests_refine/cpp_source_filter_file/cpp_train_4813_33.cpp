#include <bits/stdc++.h>
using namespace std;
int modMin(int a, int b) { return min(a % b, b - a % b); }
void solve() {
  int a, b, c;
  int solA, solB, solC;
  cin >> a >> b >> c;
  int sol = INT_MAX;
  for (int i = 1; i <= c; i++) {
    int solBC = INT_MAX;
    int solBB, solCC;
    for (int j = i; j <= c; j += i) {
      if (solBC > abs(b - j) + modMin(c, j)) {
        solBC = abs(b - j) + modMin(c, j);
        solBB = j;
        solCC = (c % j == modMin(c, j) ? c / j * j : (c / j + 1) * j);
      }
    }
    if (sol > solBC + abs(a - i)) {
      sol = solBC + abs(a - i);
      solA = i;
      solB = solBB;
      solC = solCC;
    }
  }
  cout << sol << endl;
  cout << solA << " " << solB << " " << solC << endl;
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}

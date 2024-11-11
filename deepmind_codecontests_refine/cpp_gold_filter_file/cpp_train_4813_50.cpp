#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cerr.tie(NULL);
  cout.tie(NULL);
  ;
  int tests;
  cin >> tests;
  while (tests--) {
    int a, b, c;
    cin >> a >> b >> c;
    int ans = INT_MAX;
    int A = -1, B = -1, C = -1;
    for (int cA = 1; cA <= 2 * a; ++cA) {
      for (int cB = cA; cB <= 2 * b; cB += cA) {
        for (int i = 0; i < 2; ++i) {
          int cC = cB * (c / cB) + i * cB;
          int result = abs(cA - a) + abs(cB - b) + abs(cC - c);
          if (result < ans) {
            ans = result;
            A = cA;
            B = cB;
            C = cC;
          }
        }
      }
    }
    cout << ans << "\n" << A << " " << B << " " << C << "\n";
  }
  return 0;
}

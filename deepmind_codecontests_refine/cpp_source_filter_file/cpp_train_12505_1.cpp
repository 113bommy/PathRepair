#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int x;
  cin >> x;
  int a, b;
  int k = 0;
  for (b = 1; b < x; b++) {
    for (a = b; a < x; a++) {
      if (((a % b) == 0) && ((a * b) > x) && ((a / b) < x)) {
        k = 1;
        cout << a << " " << b;
        break;
      }
    }
    if (k == 1) break;
  }
  if (k == 0) cout << "-1";
}

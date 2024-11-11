#include <bits/stdc++.h>
using namespace std;
int n, sol, i;
int main() {
  cin >> n;
  sol = 1;
  if (n == 3) cout << 1;
  if (n == 4) cout << 4;
  if (n == 5) cout << 9;
  if (n == 6) cout << 16;
  if (n >= 7) {
    for (i = 2; i <= n - 1; i++) sol += (n - 4);
    sol += 2 * (n - 3);
    cout << sol;
  }
  return 0;
}

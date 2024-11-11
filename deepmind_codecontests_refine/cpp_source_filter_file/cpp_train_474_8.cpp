#include <bits/stdc++.h>
using namespace std;
int sol, n, k;
int main() {
  cin >> n >> k;
  for (int i = 1, p; i <= n; ++i) {
    cin >> p;
    sol += p / k;
    if (p % k == 0) sol++;
  }
  cout << sol / 2 + sol % 2;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    if ((i % 2 != 0) && (i != n))
      cout << " i hate  that"
           << " ";
    if ((i % 2 == 0) && (i != n))
      cout << " i love that"
           << " ";
    if ((i % 2 != 0) && (i == n))
      cout << " i hate  it"
           << " ";
    if ((i % 2 == 0) && (i == n))
      cout << " i love it"
           << " ";
  }
  return 0;
}

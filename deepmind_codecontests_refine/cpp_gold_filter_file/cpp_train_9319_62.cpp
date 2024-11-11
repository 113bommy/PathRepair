#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, j, s1 = 0, s2 = 0;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> j;
    s1 |= j;
  }
  for (i = 0; i < n; i++) {
    cin >> j;
    s2 |= j;
  }
  cout << s1 + s2;
  return 0;
}

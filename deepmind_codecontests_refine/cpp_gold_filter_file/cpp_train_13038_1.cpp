#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n, m, i, a;
  cin >> t;
  for (i = 0; i < t; i++) {
    cin >> n >> m;
    a = (n * m + 1) / 2;
    cout << a << '\n';
  }
  return 0;
}

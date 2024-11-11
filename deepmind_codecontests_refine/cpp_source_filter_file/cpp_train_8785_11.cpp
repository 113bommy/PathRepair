#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int n;
  cin >> n;
  int p = 0, u = n * n;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j * 2 <= n; ++j) cout << (++p) << ' ' << (--u) << ' ';
    cout << '\n';
  }
  return 0;
}

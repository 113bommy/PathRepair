#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, n, a = 1, t = 3;
  cin >> n;
  if (n == 3) {
    cout << a;
    return 0;
  }
  for (i = 4; i <= n; i++) {
    a += t;
    t += 2;
  }
  cout << a;
  return 0;
}

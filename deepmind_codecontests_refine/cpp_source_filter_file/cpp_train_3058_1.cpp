#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, n;
  cin >> a >> b >> n;
  int i;
  for (i = 1; i <= 9; i++) {
    if ((a * 10 + i) % b == 0) break;
  }
  if (i == 10)
    cout << -1 << "\n";
  else {
    cout << a * 10 + i;
    for (i = 1; i < n; i++) cout << "0";
    cout << "\n";
  }
}

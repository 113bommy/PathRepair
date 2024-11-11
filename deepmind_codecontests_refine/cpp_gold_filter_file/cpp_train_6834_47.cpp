#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n > 36)
    cout << -1 << endl;
  else {
    if (n % 2 == 1) cout << 4;
    for (int i = 1; i <= n / 2; i++) cout << 8;
    cout << endl;
  }
  return 0;
}

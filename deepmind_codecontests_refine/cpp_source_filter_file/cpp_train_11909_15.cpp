#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n < 3 || n % 2 == 0)
    cout << -1 << endl;
  else {
    cout << 0;
    for (int i = 1; i < n; ++i) cout << " " << i;
    cout << endl;
    cout << 0;
    for (int i = 1; i < n; ++i) cout << " " << i;
    cout << endl;
    cout << 0;
    for (int i = 1; i < n; ++i) cout << " " << (2 * i) % n;
    cout << endl;
  }
  return 0;
}

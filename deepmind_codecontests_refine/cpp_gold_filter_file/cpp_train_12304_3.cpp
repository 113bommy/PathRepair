#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int a, b;
  cin >> a >> b;
  if (a == 9 && b == 1) {
    cout << 9 << " " << 10 << endl;
    return 0;
  }
  if (a == b - 1) {
    cout << a << " " << b << endl;
    return 0;
  }
  if (a == b) {
    cout << a << "0"
         << " " << b << "1" << endl;
    return 0;
  }
  cout << -1 << endl;
}

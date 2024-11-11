#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ;
  long long i, j, q, n;
  cin >> q;
  while (q--) {
    long long a, b;
    cin >> a >> b;
    long long d = abs(a - b);
    if (a == b) {
      cout << 0 << endl;
    } else if (a < b) {
      if (d % 2)
        cout << 1 << endl;
      else
        cout << 2 << endl;
    } else {
      if (d % 2)
        cout << 2 << endl;
      else
        cout << 1 << endl;
    }
  }
  return 0;
}

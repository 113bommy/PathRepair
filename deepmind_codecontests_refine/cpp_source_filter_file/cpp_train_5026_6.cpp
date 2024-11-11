#include <bits/stdc++.h>
using namespace std;
const int N = 1000000;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (!(a == 0 && d == 0) && (a + b) % 2 == 1)
      cout << "Ya ";
    else
      cout << "Tidak ";
    if (!(b == 0 && c == 0) && (a + b) % 2 == 1)
      cout << "Ya ";
    else
      cout << "Tidak ";
    if (!(a == 0 && d == 0) && (a + b) % 2 == 0)
      cout << "Ya ";
    else
      cout << "Tidak ";
    if (!(b == 0 && c == 0) && (a + b) % 2 == 0)
      cout << "Ya" << endl;
    else
      cout << "Tidak" << endl;
  }
  return 0;
}

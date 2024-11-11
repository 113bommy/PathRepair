#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  int n, q;
  cin >> n >> q;
  while (q--) {
    int x, y;
    cin >> x >> y;
    if ((x + y) % 2 == 0) {
      if (n % 2 == 0) {
        cout << ((x - 1) * n / 2 + (y + 1) / 2);
      } else if (x % 2 == 0) {
        cout << ((x - 1) * n / 2 + 1 + y / 2);
      } else {
        cout << ((x - 1) * n / 2 + (y + 1) / 2);
      }
    } else if (n % 2 == 0) {
      cout << (n * n / 2 + (x - 1) * n / 2 + (y + 1) / 2);
    } else if (x % 2 == 0) {
      cout << (n * n / 2 + 1 + (x - 1) * n / 2 + (y + 1) / 2);
    } else {
      cout << (n * n / 2 + (x - 1) * n / 2 + 1 + y / 2);
    }
    cout << endl;
  }
  return 0;
}

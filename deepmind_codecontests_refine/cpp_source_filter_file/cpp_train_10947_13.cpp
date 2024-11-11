#include <bits/stdc++.h>
using namespace std;
int main() {
  long n;
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int s = 0;
    cin >> n;
    while (n != 1) {
      if (n == 0) {
        s = -1;
        break;
      }
      if (n % 5 == 0) {
        n = 4 * n / 5;
        s++;
      } else if (n % 3 == 0) {
        n = 2 * n / 3;
        s++;
      } else if (n % 2 == 0) {
        n = n / 2;
        s++;
      } else {
        s = -1;
        break;
      }
    }
    cout << s << endl;
  }
}

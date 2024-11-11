#include <bits/stdc++.h>
using namespace std;
int main() {
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int n;
    cin >> n;
    int loop = 0;
    int flag = 0;
    while (n > 1) {
      loop++;
      if (n % 2 == 0) {
        n = n / 2;
      } else if (n % 3 == 0) {
        n = (2 * n) / 3;
      } else if (n % 5 == 0) {
        n = (4 * n) / 5;
      } else
        break;
    }
    if (n == 1)
      cout << loop << endl;
    else
      cout << "-1" << endl;
  }
  return 0;
}

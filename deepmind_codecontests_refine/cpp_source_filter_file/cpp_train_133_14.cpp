#include <bits/stdc++.h>
int rr[] = {0, 0, 1, -1};
using namespace std;
int main() {
  long long int q, q1, i, cnt, f;
  while (cin >> q) {
    if (q == 1) {
      cout << "1" << endl << "0" << endl;
      continue;
    }
    q1 = q;
    for (i = 2, cnt = 0, f = 0; i * i <= q; i++) {
      if (q % i == 0) {
        cnt++;
        q = q / i;
        f = 1;
        if (cnt == 2) break;
        i = 2;
      }
    }
    if (cnt == 0 || cnt == 2) {
      cout << "1" << endl;
      if (f == 0)
        cout << "0" << endl;
      else
        cout << q1 / q << endl;
    } else
      cout << "2" << endl;
  }
  return 0;
}

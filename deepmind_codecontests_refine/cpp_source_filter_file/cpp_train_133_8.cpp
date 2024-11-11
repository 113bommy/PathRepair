#include <bits/stdc++.h>
using namespace std;
int main() {
  long long q, q1;
  while (cin >> q) {
    q1 = q;
    bool flag = false;
    for (long long i = 2; i * i < q; i++) {
      if (q % i == 0) {
        q /= i;
        flag = true;
        break;
      }
    }
    if (flag == false) {
      cout << "1" << endl << "0" << endl;
      ;
      return 0;
    }
    flag = false;
    for (long long i = 2; i * i < q; i++) {
      if (q % i == 0) {
        q /= i;
        cout << "1" << endl << q1 / q << endl;
        return 0;
      }
    }
    cout << "2" << endl;
  }
  return 0;
}

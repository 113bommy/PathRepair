#include <bits/stdc++.h>
using namespace std;
int main() {
  int q;
  cin >> q;
  while (q--) {
    int n;
    cin >> n;
    int one = 0, zero = 0;
    int ar[n];
    for (int i = 0; i < n; i++) {
      cin >> ar[i];
    }
    int flag = 0;
    for (int i = 0; i < n; i++) {
      if (ar[i] > ar[i + 1]) {
        flag = 1;
        break;
      }
    }
    for (int i = 0; i < n; i++) {
      int p;
      cin >> p;
      if (p == 1)
        one = 1;
      else
        zero = 1;
    }
    if (flag == 0 || n == 1)
      cout << "Yes" << endl;
    else if (one == zero)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
}

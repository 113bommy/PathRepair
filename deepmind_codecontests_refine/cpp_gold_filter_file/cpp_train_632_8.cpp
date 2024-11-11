#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, n2, p;
  while (cin >> n >> n2 >> p) {
    long long n1 = n - n2;
    for (int ii = 0; ii < p; ii++) {
      long long k;
      cin >> k;
      if (n1 <= n2) {
        if (k <= 2 * n1)
          cout << (k % 2 == 1 ? "." : "X");
        else
          cout << "X";
      } else {
        if (k <= n1 - n2)
          cout << ".";
        else if ((n1 - n2) % 2 == 0)
          cout << (k % 2 == 1 ? "." : "X");
        else if (n2 == 1)
          cout << (k % 2 == 1 ? "X" : ".");
        else if (k == n1 - n2 + 1)
          cout << ".";
        else if (k == n)
          cout << "X";
        else
          cout << (k % 2 == 1 ? "." : "X");
      }
    }
    cout << endl;
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int a[] = {2, 7, 2, 3, 3, 4, 2, 5, 1, 2};
int main() {
  int n;
  while (cin >> n) {
    if (n < 10) {
      cout << a[n] * 2 << endl;
    } else {
      int p = n / 10;
      int q = n % 10;
      cout << a[p] * a[q] << endl;
    }
  }
}

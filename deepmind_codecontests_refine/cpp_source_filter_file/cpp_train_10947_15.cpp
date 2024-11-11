#include <bits/stdc++.h>
using namespace std;
int main() {
  int nyn;
  cin >> nyn;
  while (nyn--) {
    long n;
    cin >> n;
    int dem = 0;
    while (n % 5 == 0) {
      n = n / 5 * 4, dem++;
    }
    while (n % 3 == 0) {
      n = n / 3 * 2, dem++;
    }
    while (n % 2 == 0) {
      n = n / 2, dem++;
    }
    if (n == 1) {
      cout << dem << endl;
    } else {
      cout << "-1" << endl;
    }
  }
  return 0;
}

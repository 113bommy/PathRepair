#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, summ = 0, count = 0, max = 0, min = 999, *arr, rows, colums;
  bool flag = 0;
  string str;
  int x1, x2, x3;
  cin >> x1 >> x2 >> x3;
  int summ1 = x1 * 2 + x2 * 2;
  int summ2 = x1 + x2 + x3;
  int summ3 = x1 * 2 + x3 * 2;
  int summ4 = x2 * 2 + x3 * 2;
  if (summ1 <= summ2 && summ1 <= summ3 && summ1 <= summ4) {
    cout << summ1;
  } else if (summ2 <= summ1 && summ2 <= summ3 && summ2 <= summ4) {
    cout << summ2;
  } else if (summ3 <= summ1 && summ3 <= summ2 && summ3 <= summ4) {
    cout << summ3;
  } else {
    cout << summ4;
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const double MAX = (1.0 + sqrt(5.0)) / 2;
int a[10];
int fun(int a, int b) {
  if (a > b) swap(a, b);
  int k = b - a;
  k = (int)(k * MAX);
  if (k == a)
    return 0;
  else
    return 1;
}
int main() {
  int n, i, k = 0;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (n == 1) {
    if (a[i] == 0)
      cout << "BitAryo" << endl;
    else
      cout << "BitLGM" << endl;
  }
  if (n == 2) {
    int flag = fun(a[0], a[1]);
    if (!flag)
      cout << "BitAryo" << endl;
    else
      cout << "BitLGM" << endl;
  }
  if (n == 3) {
    if ((a[0] ^ a[1] ^ a[2]) == 0)
      cout << "BitAryo" << endl;
    else
      cout << "BitLGM" << endl;
  }
  return 0;
}

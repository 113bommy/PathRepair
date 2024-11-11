#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n == 1) {
    cout << 1 << endl << 1;
    return 0;
  }
  if (n == 2) {
    cout << 1 << endl << 1;
    return 0;
  }
  if (n == 3) {
    cout << 2 << endl << "1 2";
    return 0;
  }
  cout << n << endl;
  cout << n / 2 + 1 << " ";
  int a = 1, b = n, cnt = 0;
  while (b > a) {
    if (cnt++ % 2 == 0)
      cout << a++ << " ";
    else
      cout << b-- << " ";
  }
}

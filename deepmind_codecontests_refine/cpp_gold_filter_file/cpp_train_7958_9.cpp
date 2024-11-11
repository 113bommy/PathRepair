#include <bits/stdc++.h>
using namespace std;
void calc(int n) {
  if (n == 4) {
    cout << "4 * 3 = 12" << endl;
    cout << "12 * 2 = 24" << endl;
    cout << "24 * 1 = 24" << endl;
  } else if (n == 5) {
    cout << "4 + 3 = 7" << endl;
    cout << "7 + 5 = 12" << endl;
    cout << "12 * 2 = 24" << endl;
    cout << "24 * 1 = 24" << endl;
  } else if (n == 6) {
    cout << "6 - 5 = 1" << endl;
    cout << "1 * 1 = 1" << endl;
    calc(4);
  } else {
    printf("%d - %d = 1\n", n, n - 1);
    cout << "1 * 1 = 1" << endl;
    calc(n - 2);
  }
}
int main() {
  int n;
  cin >> n;
  if (n < 4) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
    calc(n);
  }
  return 0;
}

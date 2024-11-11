#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, ones = 1, twos = 1;
  cin >> n;
  if (n <= 3) {
    cout << "NO" << endl;
    return 0;
  }
  cout << "YES" << endl;
  if (n == 4) {
    cout << "3 * 4 = 12\n2 * 12 = 24\n1 * 24 = 24" << endl;
    return 0;
  } else if (n == 5) {
    cout << "5 - 2 = 3\n3 + 3 = 6\n4 * 6 = 24\n1 * 24 = 24" << endl;
    return 0;
  }
  while (n > 7) {
    cout << n << " - " << (n - 1) << " = 1" << endl;
    ones++;
    n -= 2;
  }
  if (n == 6) {
    cout << "5 - 3 = 2" << endl;
    twos++;
  } else {
    cout << "7 - 5 = 2" << endl;
    twos++;
    cout << "3 - 2 = 1" << endl;
    ones++;
    twos--;
  }
  while (twos) {
    cout << "2 - 1 = 1" << endl;
    twos--;
  }
  cout << "4 * 6 = 24" << endl;
  while (ones) {
    cout << "24 * 1 = 1" << endl;
    ones--;
  }
}

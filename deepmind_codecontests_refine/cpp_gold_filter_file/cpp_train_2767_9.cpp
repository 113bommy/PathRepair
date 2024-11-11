#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, x, res;
  cin >> n >> x;
  n %= 6;
  if (n == 0) {
    cout << x << endl;
    return 0;
  }
  if (x == 0) {
    if (n <= 2) {
      cout << 1 << endl;
    } else if (n <= 4) {
      cout << 2 << endl;
    } else {
      cout << 0 << endl;
      return 0;
    }
  } else if (x == 1) {
    if (n == 1 || n == 4) {
      cout << 0 << endl;
      return 0;
    } else if (n == 3 || n == 6) {
      cout << 1 << endl;
    } else {
      cout << 2 << endl;
      return 0;
    }
  } else {
    if (n == 3 || n == 2) {
      cout << 0 << endl;
      return 0;
    } else if (n == 5 || n == 4) {
      cout << 1 << endl;
      return 0;
    } else {
      cout << 2 << endl;
    }
  }
}

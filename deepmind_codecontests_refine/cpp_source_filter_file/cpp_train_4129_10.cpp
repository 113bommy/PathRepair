#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n = 11, m = 4, a = 3, b = 9;
  cin >> n >> m >> a >> b;
  n--;
  a--;
  b--;
  long long l1 = a / m;
  long long l2 = b / m;
  long long c1 = a % m;
  long long c2 = b % m;
  if (l1 == l2) {
    cout << 1 << endl;
  } else if (c1 == 0 && c2 == m - 1) {
    cout << 1 << endl;
  } else if (c1 == 0 && c2 == n) {
    cout << 1 << endl;
  } else if (l2 - l1 == 1) {
    cout << 2 << endl;
  } else if (c1 == 0) {
    cout << 2 << endl;
  } else if (c2 == m - 1) {
    cout << 2 << endl;
  } else if (c1 - 1 == c2) {
    cout << 2 << endl;
  } else if (b == n) {
    cout << 2 << endl;
  } else {
    cout << 3 << endl;
  }
  return 0;
}

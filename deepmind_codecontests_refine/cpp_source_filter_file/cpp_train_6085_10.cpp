#include <bits/stdc++.h>
using namespace std;
int n, m;
int main() {
  cin >> n >> m;
  if (n == 0) {
    cout << 0 << " " << 1 << endl;
    cout << 0 << " " << m << endl;
    cout << 0 << " " << 0 << endl;
    cout << 0 << " " << m - 1 << endl;
    return 0;
  }
  if (m == 0) {
    cout << 1 << " " << 0 << endl;
    cout << n << " " << 0 << endl;
    cout << 0 << " " << 0 << endl;
    cout << n - 1 << " " << 0 << endl;
    return 0;
  }
  if (n < 5 || m < 5) {
    cout << 0 << " " << 0 << endl;
    cout << n << " " << m << endl;
    if (n >= m) {
      cout << 0 << " " << m << endl;
      cout << n << " " << 0 << endl;
    } else {
      cout << n << " " << 0 << endl;
      cout << 0 << " " << m << endl;
    }
  } else {
    if (m >= n)
      cout << n - 1 << " " << m << endl;
    else
      cout << n << " " << m - 1 << endl;
    cout << 0 << " " << 0 << endl;
    cout << n << " " << m << endl;
    if (m >= n)
      cout << 1 << " " << 0 << endl;
    else
      cout << 0 << " " << 1 << endl;
  }
}

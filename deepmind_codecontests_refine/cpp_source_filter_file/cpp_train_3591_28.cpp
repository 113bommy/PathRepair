#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  if (n <= 2) {
    cout << 1 << endl;
    return 0;
  }
  if (m > n / 2.0) {
    cout << m - 1 << endl;
  } else {
    cout << m + 1 << endl;
  }
}

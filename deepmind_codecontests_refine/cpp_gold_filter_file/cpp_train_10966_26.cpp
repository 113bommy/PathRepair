#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  if (k < 3 * n) {
    cout << (3 * n - k) << endl;
  } else {
    cout << 0 << endl;
  }
  return 0;
}

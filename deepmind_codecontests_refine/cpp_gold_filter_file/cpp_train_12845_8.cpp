#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int most = (n * (n - 1)) / 2;
  if (k >= most) {
    cout << "no solution" << endl;
  } else {
    for (int i = 0; i < n; ++i) {
      cout << i << " " << 999999999 - 5000 * i << endl;
    }
  }
  return 0;
}

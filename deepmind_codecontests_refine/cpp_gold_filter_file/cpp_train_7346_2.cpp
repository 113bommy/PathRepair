#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int k = (sqrtl(8 * n + 1) - 1) / 2;
  int v = n - ((k * (k + 1)) / 2);
  int st = k - v;
  cout << k << endl;
  for (int i = 0; i < k; i++) {
    if (i >= st) {
      cout << (i + 2) << " ";
    } else {
      cout << (i + 1) << " ";
    }
  }
  return 0;
}

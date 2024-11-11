#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  double x;
  cin >> n;
  x = pow(8 * n + 1, 0.5) - 1;
  if (fmod(x, 2) == 0) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}

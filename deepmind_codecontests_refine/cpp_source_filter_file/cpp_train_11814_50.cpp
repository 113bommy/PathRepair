#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, w;
  cin >> n >> w;
  if (n % 2 == 0) {
    cout << n / 2 * w;
  } else if (w % 2 == 0) {
    cout << w / 2 * w;
  } else {
    cout << n * w / 2;
  }
  return 0;
}

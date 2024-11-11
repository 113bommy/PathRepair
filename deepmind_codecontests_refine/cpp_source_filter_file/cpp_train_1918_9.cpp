#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, i, j, a, b, x = 10000000;
  cin >> n >> m >> i >> j >> a >> b;
  int arr[4][2] = {{1, m}, {m, 1}, {n, m}, {1, 1}};
  for (int k = 0; k < 4; k++) {
    if (abs(i - arr[k][0]) % a == 0 && (j - arr[k][1]) % b == 0 &&
        ((i - arr[k][0]) / a - (j - arr[k][1]) / b) % 2 == 0)
      x = min(max(abs(i - arr[k][0]) / a, abs(j - arr[k][1]) / b), x);
  }
  if (x == 10000000 || (x > 0 && (n <= a || m <= b))) {
    cout << "Poor Inna and pony!";
    return 0;
  }
  cout << x;
  return 0;
}

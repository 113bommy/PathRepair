#include <bits/stdc++.h>
const double PI = acos(-1.0);
const int DIR = 4;
const int X[] = {1, 0, -1, 0};
const int Y[] = {0, 1, 0, -1};
using namespace std;
int main() {
  int n, a, b;
  cin >> n >> a >> b;
  for (int i = 0; i * a <= n; i++) {
    if ((n - (i * a)) % b != 0) continue;
    for (int j = 1; j <= i * a; j += a) {
      for (int k = 1; k < a; k++) printf("%d ", j + k);
      printf("%d ", j);
    }
    for (int j = i * a + 1; j <= n; j += b) {
      for (int k = 1; k < b; k++) printf("%d ", j + k);
      printf("%d ", j);
    }
    return 0;
  }
  cout << -1 << endl;
  return 0;
}

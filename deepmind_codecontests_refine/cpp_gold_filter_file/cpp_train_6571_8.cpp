#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  array<int, 2> a[3];
  for (int i = 0; i < 3; ++i) cin >> a[i][0] >> a[i][1];
  sort(a, a + 3);
  if (a[0][1] <= a[1][1] && a[1][1] <= a[2][1]) {
    cout << a[2][0] - a[0][0] + a[2][1] - a[0][1] + 1 << "\n";
    int i = a[0][0], j = a[0][1];
    while (i < a[1][0]) cout << i++ << " " << j << "\n";
    while (j < a[1][1]) cout << i << " " << j++ << "\n";
    while (i < a[2][0]) cout << i++ << " " << j << "\n";
    while (j < a[2][1]) cout << i << " " << j++ << "\n";
    cout << i << " " << j << "\n";
  } else if (a[0][1] >= a[1][1] && a[1][1] >= a[2][1]) {
    cout << a[2][0] - a[0][0] + a[0][1] - a[2][1] + 1 << "\n";
    int i = a[0][0], j = a[0][1];
    while (i < a[1][0]) cout << i++ << " " << j << "\n";
    while (j > a[1][1]) cout << i << " " << j-- << "\n";
    while (i < a[2][0]) cout << i++ << " " << j << "\n";
    while (j > a[2][1]) cout << i << " " << j-- << "\n";
    cout << i << " " << j << "\n";
  } else {
    if (abs(a[2][1] - a[1][1]) < abs(a[0][1] - a[1][1])) {
      cout << a[2][0] - a[0][0] + abs(a[0][1] - a[2][1]) + 1 +
                  abs(a[2][1] - a[1][1])
           << "\n";
      int i = a[0][0], j = a[0][1];
      while (j > a[2][1]) cout << i << " " << j-- << "\n";
      while (j < a[2][1]) cout << i << " " << j++ << "\n";
      while (i < a[2][0]) cout << i++ << " " << j << "\n";
      cout << i << " " << j << "\n";
      while (j < a[1][1]) cout << a[1][0] << " " << ++j << "\n";
      while (j > a[1][1]) cout << a[1][0] << " " << --j << "\n";
    } else {
      cout << a[2][0] - a[0][0] + abs(a[0][1] - a[2][1]) + 1 +
                  abs(a[0][1] - a[1][1])
           << "\n";
      int i = a[0][0], j = a[0][1];
      while (i < a[2][0]) cout << i++ << " " << j << "\n";
      while (j > a[2][1]) cout << i << " " << j-- << "\n";
      while (j < a[2][1]) cout << i << " " << j++ << "\n";
      cout << i << " " << j << "\n";
      j = a[0][1];
      while (j < a[1][1]) cout << a[1][0] << " " << ++j << "\n";
      while (j > a[1][1]) cout << a[1][0] << " " << --j << "\n";
    }
  }
  return 0;
}

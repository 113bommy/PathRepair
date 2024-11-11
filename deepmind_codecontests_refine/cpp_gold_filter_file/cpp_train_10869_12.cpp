#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, j, k, min_pos1, min_pos2, min;
  int a[103];
  cin >> n;
  min = 10000;
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  min = abs(a[0] - a[n - 1]);
  min_pos1 = n;
  min_pos2 = 1;
  for (i = 0; i < n - 1; i++) {
    if (abs(a[i] - a[i + 1]) < min) {
      min_pos1 = i + 1;
      min_pos2 = i + 2;
      min = abs(a[i] - a[i + 1]);
    }
  }
  cout << min_pos1 << " " << min_pos2;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y, count = 0;
  cin >> x >> y;
  int a[3], i = 0;
  for (int i = 0; i < 3; i++) a[i] = y;
  while (a[0] != x || a[1] != x || a[2] != x) {
    count++;
    if (i == 0) {
      a[i] = min(x, a[1] + a[2] - 1);
      i++;
    } else if (i == 1) {
      a[i] = min(x, a[0] + a[1] - 1);
      i++;
    } else {
      a[i] = min(x, a[1] + a[0] - 1);
      i = 0;
    }
  }
  cout << count;
}

#include <bits/stdc++.h>
using namespace std;
int b, v, o;
int x, y, z;
int a[4];
int main() {
  scanf("%d%d%d", &b, &v, &o);
  scanf("%d%d%d", &x, &y, &z);
  a[1] = b - x;
  a[2] = v - y;
  a[3] = o - z;
  sort(a + 1, a + 4);
  if (a[1] >= 0) {
    cout << "Yes";
    return 0;
  }
  if (a[2] >= 0)
    if (a[2] / 2 + a[3] / 2 >= abs(a[1])) {
      cout << "Yes";
      return 0;
    } else {
      cout << "No";
      return 0;
    }
  if (abs(a[1]) * 2 + abs(a[2]) * 2 <= a[3])
    cout << "Yes";
  else
    cout << "No";
  return 0;
}

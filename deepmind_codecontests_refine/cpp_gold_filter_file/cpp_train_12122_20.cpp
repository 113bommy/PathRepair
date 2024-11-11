#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y, c = 0, arr1[1001], arr2[1001], a = 0, b = 0;
  cin >> x >> y;
  for (int i = 0; i < y; i++) cin >> arr1[i];
  for (int i = 0; i < x; i++) {
    if (i == 0)
      c = x + 1;
    else
      c = arr2[b - 1];
    for (int j = arr1[a]; j < c; j++) {
      arr2[b] = arr1[a];
      b++;
    }
    a++;
    if (a == y) break;
  }
  sort(arr2, arr2 + x);
  for (int i = 0; i < x; i++) cout << arr2[i] << " ";
  return 0;
}

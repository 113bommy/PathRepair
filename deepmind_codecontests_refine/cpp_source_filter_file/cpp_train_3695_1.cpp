#include <bits/stdc++.h>
using namespace std;
int n, a, i, m, z, x, y, arr[20000001];
int main() {
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> arr[i];
    if (arr[i] == 1)
      x++;
    else
      y++;
  }
  if (x > y)
    z = x - y;
  else
    z = y - x;
  cout << z;
  return 0;
}

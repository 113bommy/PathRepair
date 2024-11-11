#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  while (n--) {
    int a[5], y;
    long long sum = 0;
    cin >> a[0] >> a[1] >> a[2] >> y;
    sort(a, a + 3);
    int x = a[2] - a[0];
    y -= x;
    if (y >= 0) a[0] += x;
    int z = a[2] - a[1];
    y -= z;
    if (y >= 0) a[1] += z;
    if (y % 3 == 0 && a[0] == a[1] && a[1] == a[2])
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}

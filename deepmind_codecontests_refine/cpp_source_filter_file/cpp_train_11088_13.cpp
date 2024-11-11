#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long test, i, j, xy, flag = 0, n, u, count, d, o1 = 0, o2 = 0, s, e, l,
                            r, x, y, m, z, max1, x1, y1, k, x2, y2, z1, z2, sum,
                            min1;
  string a;
  cin >> n >> a;
  i = 0;
  count = 0;
  x1 = 1;
  while (i < n - 1 && a[i] != a[i + 1]) {
    i++;
    x1++;
  }
  if (i >= n) {
    cout << n << "\n";
    return 0;
  }
  x = i;
  i = n - 1;
  y1 = 1;
  while (i >= 1 && a[i] != a[i - 1]) {
    i--;
    y1++;
  }
  y = i;
  if (y + 1 == x) {
    cout << n << "\n";
    return 0;
  }
  string temp = to_string(a[x]);
  count = 0;
  for (i = x + 1; i < y; i++) {
    if (temp.back() != a[i]) {
      temp += a[i];
      count++;
    }
  }
  cout << count + x1 + y1 << "\n";
  return 0;
}

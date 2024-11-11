#include <bits/stdc++.h>
using namespace std;
int n, d, h;
int main() {
  cin >> n >> d >> h;
  if (2 * h < d || n < d + 1 || n < h + 1 || d < h || (h == 1 && n > 2)) {
    cout << "-1";
    return 0;
  }
  int i = 1;
  for (; i <= h; i++) cout << i << " " << i + 1 << endl;
  if (d != h) {
    i++;
    cout << 1 << " " << i << endl;
    for (; i <= d; i++) cout << i << " " << i + 1 << endl;
    i++;
    for (; i <= n; i++) cout << 1 << " " << i << endl;
  } else {
    int x = i - 1;
    i++;
    for (; i <= n; i++) cout << x << " " << i << endl;
  }
  return 0;
}

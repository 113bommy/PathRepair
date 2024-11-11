#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a[4] = {0}, n, i, j, k, l, m;
  cin >> n;
  if (n == 0) {
    cout << "YES\n";
    cout << 1 << endl << 1 << endl << 3 << endl << 3;
  }
  if (n == 1) {
    cin >> a[0];
    cout << "YES\n";
    cout << a[0] << endl;
    cout << 3 * a[0] << endl;
    cout << 3 * a[0] << endl;
  }
  if (n == 2) {
    cin >> a[0] >> a[1];
    sort(a, a + 2);
    if (a[1] > 3 * a[0]) {
      cout << "NO";
      return 0;
    }
    cout << "YES\n";
    cout << 4 * a[0] - a[1] << endl;
    cout << 3 * a[0];
  }
  if (n == 3) {
    cin >> a[1] >> a[2] >> a[3];
    long long mi, ma, sum, mid;
    for (i = 1; i <= 100000; i++) {
      mi = min(min(i, a[1]), min(a[2], a[3]));
      ma = max(max(i, a[1]), max(a[2], a[3]));
      sum = i + a[1] + a[2] + a[3];
      mid = (sum - mi - ma) * 2;
      ma = (ma - mi) * 4;
      if ((sum == mid) && (sum == ma)) {
        printf("YES\n");
        printf("%d\n", i);
        return 0;
      }
    }
    printf("NO");
  }
  if (n == 4) {
    cin >> a[0] >> a[1] >> a[2] >> a[3];
    sort(a, a + 4);
    if (a[3] != 3 * a[0] || a[2] != 4 * a[0] - a[1])
      cout << "NO\n";
    else
      cout << "YES\n";
  }
}

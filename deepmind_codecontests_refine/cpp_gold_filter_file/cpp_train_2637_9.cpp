#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, num, ans;
  cin >> n;
  int a[] = {0, 0, 0, 0};
  for (int i = 0; i < n; i++) {
    cin >> num;
    a[num - 1] += 1;
  }
  ans = a[1] / 2 + a[2] + a[3];
  if (a[1] % 2 != 0) {
    a[0] -= 2;
    ans += 1;
  }
  if (a[0] > a[2]) {
    a[0] -= a[2];
    ans += a[0] / 4;
    if (a[0] % 4 != 0) ans += 1;
  }
  cout << ans;
  return 0;
}

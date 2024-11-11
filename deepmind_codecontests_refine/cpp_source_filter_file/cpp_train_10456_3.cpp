#include <bits/stdc++.h>
using namespace std;
template <typename X>
X gcd(X a, X b) {
  if (!b)
    return a;
  else
    return gcd(b, a % b);
}
int main() {
  int n, m;
  cin >> n >> m;
  int a[n + 1][m + 1];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  int ans;
  if (n % 2)
    ans = n;
  else {
    int x;
    x /= 2;
    int k = 0;
    bool flag = true;
    while (flag && x > 0) {
      for (int i = 0, j = 2 * x - 1; i < x && j >= x; i++, j--) {
        flag = true;
        while (k < m) {
          if (a[i][k] == a[j][k])
            k++;
          else {
            flag = false;
            break;
          }
        }
        k = 0;
        if (flag == false) {
          x *= 2;
          break;
        }
      }
      if (flag && x % 2 == 0)
        x /= 2;
      else {
        ans = x;
        break;
      }
    }
  }
  printf("%d\n", ans);
}

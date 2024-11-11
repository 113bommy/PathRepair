#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int a[n + 1];
  int p1[n + 1];
  p1[0] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    p1[i] = p1[i - 1] + a[i];
  }
  int b[n + 1];
  int p2[n + 1];
  p2[0] = 0;
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
    p2[i] = p2[i - 1] + b[i];
  }
  int ans = 0;
  int x1, x2, l1, l2;
  x1 = x2 = 1;
  l1 = l2 = 0;
  while (x1 <= n || x2 <= m) {
    int num1 = p1[x1] - p1[l1];
    int num2 = p2[x2] - p2[l2];
    if (num1 == num2) {
      l1 = x1;
      l2 = x2;
      x1++;
      x2++;
      ans++;
    } else if (num1 < num2) {
      x1++;
    } else {
      x2++;
    }
  }
  cout << ans;
}

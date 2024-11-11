#include <bits/stdc++.h>
using namespace std;
int n;
int a[1005];
int judge() {
  for (int i = 1; i <= n; i++) {
    if (a[i] == 0) return 0;
    if (i < n && a[i] > a[i + 1]) return 0;
  }
  return 1;
}
int main() {
  int m, i, j, c;
  cin >> n >> m >> c;
  for (i = 1; i <= m; i++) {
    int x;
    scanf("%d", &x);
    if (x <= c / 2) {
      for (int i = 1; i <= n; i++) {
        if (a[i] == 0 || a[i] > x) {
          a[i] = x;
          cout << i << endl;
          break;
        }
      }
    } else {
      for (int i = n; i >= 1; i--) {
        if (a[i] == 0 || a[i] < x) {
          a[i] = x;
          cout << i << endl;
          break;
        }
      }
    }
    if (judge()) return 0;
  }
  return 0;
}

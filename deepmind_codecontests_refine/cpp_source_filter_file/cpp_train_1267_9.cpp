#include <bits/stdc++.h>
using namespace std;
int n, x, y;
int a[10002];
bool kt1, kt2;
int main() {
  cin >> n >> x >> y;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) {
    int j = i - 1;
    int xx = x;
    int yy = y;
    kt1 = false;
    kt2 = false;
    while (j >= 1 && a[j] > a[i]) {
      j--;
      xx--;
      if (j == 0 || x == 0) break;
    }
    if (j == 0 || xx == 0) kt1 = true;
    j = i + 1;
    while (j <= n && a[j] > a[i]) {
      j++;
      yy--;
      if (j == n + 1 || yy == 0)
        ;
    }
    if (j == n + 1 || yy == 0) kt2 = true;
    if (kt1 && kt2) {
      cout << i;
      break;
    }
  }
  return 0;
}

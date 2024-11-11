#include <bits/stdc++.h>
using namespace std;
int a[200000];
int main() {
  int n, ans;
  while (scanf("%d", &n) != EOF) {
    ans = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      if (a[i] == i) ans++;
    }
    int Max = 0;
    for (int i = 1; i <= n; i++) {
      if (a[i] != i) {
        int tmp = a[i];
        if (a[tmp] != i)
          Max = 1;
        else
          Max = 2;
      }
      if (Max == 2) break;
    }
    ans = ans + Max;
    cout << ans << endl;
  }
  return 0;
}

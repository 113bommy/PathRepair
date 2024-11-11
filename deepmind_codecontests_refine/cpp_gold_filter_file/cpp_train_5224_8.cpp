#include <bits/stdc++.h>
using namespace std;
int n, a[10];
char c[100005];
int main() {
  scanf("%d%s", &n, (c + 1));
  for (int i = 1; i <= n; i++) {
    if (c[i] == 'L') {
      for (int j = 0; j <= 9; j++) {
        if (a[j] == 0) {
          a[j] = 1;
          break;
        }
      }
    } else if (c[i] == 'R') {
      for (int j = 9; j >= 0; j--) {
        if (a[j] == 0) {
          a[j] = 1;
          break;
        }
      }
    } else
      a[c[i] - '0'] = 0;
  }
  for (int i = 0; i < 10; i++) cout << a[i];
}

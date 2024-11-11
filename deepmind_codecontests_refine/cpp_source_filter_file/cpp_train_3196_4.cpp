#include <bits/stdc++.h>
using namespace std;
int n;
char a[1100];
int main() {
  while (~scanf("%d", &n)) {
    int flag = 0;
    scanf("%s", a + 1);
    a[0] = 1, a[n + 1] = 0;
    for (int i = 1; i <= n; i++) {
      if ((a[i] == a[i - 1] && a[i] == a[i + 1] && a[i] == '0') ||
          (a[i] == a[i + 1] && a[i] == '1')) {
        flag = 1;
        break;
      }
    }
    if (flag)
      printf("No\n");
    else
      printf("Yes\n");
  }
  return 0;
}

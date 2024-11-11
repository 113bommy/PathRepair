#include <bits/stdc++.h>
using namespace std;
int T, n, a[200005];
bool flag;
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    flag = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      if (a[i] > 1 && a[i] != a[i - 1]) flag = 1;
    }
    if (flag)
      printf("1\n");
    else
      printf("%d\n", n);
  }
}

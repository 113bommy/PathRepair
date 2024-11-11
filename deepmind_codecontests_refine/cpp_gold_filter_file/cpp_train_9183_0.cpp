#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int a[100005];
  int b[100005];
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &a[i], &b[i]);
  }
  int flag = 1;
  if (n % 2 == 0)
    for (int i = 1; i < n / 2; i++) {
      if (a[i] + a[i + n / 2] != a[i + 1] + a[i + 1 + n / 2] ||
          b[i] + b[i + n / 2] != b[i + 1] + b[i + 1 + n / 2]) {
        flag = 0;
        break;
      }
    }
  else
    flag = 0;
  if (flag)
    printf("YES\n");
  else
    printf("NO\n");
}

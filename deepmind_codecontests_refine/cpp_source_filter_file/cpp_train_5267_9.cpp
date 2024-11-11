#include <bits/stdc++.h>
using namespace std;
int a[100];
int main(void) {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 1; i < k; i++) a[i] = i;
  for (int i = k; i <= n; i++) {
    char op[10];
    scanf("%s", op);
    if (op[0] == 'Y')
      a[i] = i;
    else
      a[i] = a[i - k + 1];
  }
  for (int i = 1; i <= n; i++) {
    printf("%c%c%c", a[i] / 26 + 'A', a[i] % 26 + 'A', i == n ? '\n' : ' ');
  }
  return 0;
}

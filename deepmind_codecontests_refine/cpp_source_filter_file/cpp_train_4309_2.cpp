#include <bits/stdc++.h>
using namespace std;
struct node {};
int a[100100];
int main() {
  int n, i;
  scanf("%d", &n);
  if (n % 4 > 1) {
    puts("-1");
  }
  if (n == 1) {
    puts("1");
  } else {
    for (i = 1; i <= n / 2; i += 2) {
      a[i] = i + 1;
      a[i + 1] = n - i + 1;
      a[n - i + 1] = n - i;
      a[n - i] = i;
    }
    if (n % 2 == 1) {
      a[n / 2 + 1] = n / 2 + 1;
    }
    printf("%d", a[1]);
    for (i = 1; i <= n; i++) printf(" %d", a[i]);
    puts("");
  }
}

#include <bits/stdc++.h>
using namespace std;
int n;
int a[1000005];
int main() {
  cin >> n;
  if (n % 4 != 0 && n % 4 != 1) {
    printf("-1\n");
    return 0;
  }
  for (int i = 1; i < n / 2; i++, ++i) {
    a[i] = i + 1;
    a[i + 1] = n - i + 1;
    a[n] = n - i;
    a[n - 1] = i;
  }
  if (n % 2 == 1) a[(n / 2) + 1] = (n / 2) + 1;
  for (int i = 1; i <= n; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
  return 0;
}

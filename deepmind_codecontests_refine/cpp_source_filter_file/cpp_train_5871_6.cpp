#include <bits/stdc++.h>
using namespace std;
int a[1000];
int n;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < (n << 1) - 1; ++i) {
    scanf("%d", &a[i]);
  }
  sort(a, a + (n << 1) + 1);
  int sum = 0;
  if (n & 1) {
    for (int i = 0; i < (n << 1) - 1; ++i) sum += abs(a[i]);
  } else {
    for (int i = 0; i < (n << 1) - 1; i += 2)
      if (i < (n - 1) << 1)
        sum += abs(a[i] + a[i + 1]);
      else
        sum += a[i];
  }
  printf("%d\n", sum);
  return 0;
}

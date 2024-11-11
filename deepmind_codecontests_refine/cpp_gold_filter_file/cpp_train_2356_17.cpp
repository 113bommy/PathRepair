#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  int a[n];
  int count = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    if (i >= 2)
      if (a[i - 2] > a[i - 1] && a[i] > a[i - 1])
        count++;
      else if (a[i - 2] < a[i - 1] && a[i] < a[i - 1])
        count++;
  }
  printf("%d\n", count);
  return 0;
}

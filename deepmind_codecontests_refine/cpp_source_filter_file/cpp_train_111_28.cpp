#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  int i;
  int a[n];
  int max = -1;
  int sum = 0;
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    if (a[i] > max) max = a[i];
    sum += a[i];
  }
  int l = 0;
  for (i = 0; i < n; i++) {
    l += (max - a[i]);
  }
  int temp = max;
  while (sum > l) {
    temp++;
    l += n;
  }
  printf("%d", temp);
}

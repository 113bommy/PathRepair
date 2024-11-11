#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, maxs = 1000;
  int a[] = {1, 1, 2, 7, 4};
  int b[10];
  for (int i = 0; i < 5; i++) {
    scanf("%d", &x);
    b[i] = x / a[i];
  }
  for (int i = 0; i < 5; i++) maxs = maxs < b[i] ? maxs : b[i];
  printf("%d", maxs);
  return 0;
}

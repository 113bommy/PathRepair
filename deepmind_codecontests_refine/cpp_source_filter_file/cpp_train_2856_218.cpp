#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int a[16] = {1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0};
  int b[16] = {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0};
  int n;
  scanf("%d", &n);
  printf("%d\n", a[n - 1]);
  return 0;
}

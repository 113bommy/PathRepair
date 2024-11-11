#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  int cnt = 0;
  for (int i = 0; i < 2 * n / 3; i++) {
    printf("0 %d\n", i);
    cnt++;
  }
  for (int i = 1; cnt < n; i += 2) {
    printf("3 %d\n", i);
    cnt += 2;
  }
  return 0;
}

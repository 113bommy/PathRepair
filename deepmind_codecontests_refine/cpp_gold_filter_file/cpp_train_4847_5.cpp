#include <bits/stdc++.h>
using namespace std;
int n, ar[1011];
int main() {
  ar[0] = 1;
  ar[1] = 1;
  ar[2] = 3;
  for (int i = 3; i <= 1000; i++) {
    ar[i] = 3 * ar[i - 1];
    ar[i] %= 1000003;
  }
  scanf("%d", &n);
  printf("%d\n", ar[n]);
  return 0;
}

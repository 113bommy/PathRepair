#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, cnt;
  cnt = 0;
  scanf("%d", &n);
  while (n) {
    if (n % 8 == 1) cnt++;
    n /= 8;
  }
  printf("%d\n", cnt);
  return 0;
}

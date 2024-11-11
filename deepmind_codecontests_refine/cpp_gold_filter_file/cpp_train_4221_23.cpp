#include <bits/stdc++.h>
using namespace std;
int n, nr;
char c;
int main() {
  scanf("%d", &n);
  while (n > 0) {
    if (n % 8 == 1) nr++;
    n /= 8;
  }
  printf("%d", nr);
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
  scanf("%d", &n);
  if (n & 1)
    printf("%d\n", n / 2);
  else {
    int x = 2;
    while (n > x) x *= 2;
    printf("%d\n", (x - n) / 2);
  }
  return 0;
}

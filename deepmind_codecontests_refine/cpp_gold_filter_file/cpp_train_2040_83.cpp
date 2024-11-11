#include <bits/stdc++.h>
using namespace std;
int n;
int y = 0;
int main() {
  scanf("%d", &n);
  if (n == 1) {
    puts("0");
  } else {
    printf("%d\n", n % 2 ? n / 2 : n / 2 - 1);
  }
  return 0;
}

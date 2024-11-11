#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, n, x = 0;
  scanf("%d", &n);
  for (i = 0; i < n; ++i) {
    char d[3];
    scanf("%s", d);
    d[1] == '+' ? x++ : x--;
  }
  printf("%d\n", x);
  return 0;
}

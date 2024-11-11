#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a[3] = {0};
  scanf("%d", &n);
  while (n--) {
    char c;
    int s = 0;
    while ((c = getchar()) <= ' ')
      ;
    s += c - '0';
    while ((c = getchar()) > ' ') s += c - '0';
    a[s % 3]++;
  }
  printf("%d\n", a[0] / 2 + min(a[1], a[2]));
  return 0;
}

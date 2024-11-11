#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
  int f[100020];
  for (int i = 0; i < 10020; i++) f[i] = i;
  cin >> n;
  if (n & 1 == 0) {
    puts("-1");
    return 0;
  }
  for (int i = 0; i < n; i++) {
    if (i) putchar(' ');
    printf("%d", i);
  }
  putchar('\n');
  for (int i = 0; i < n; i++) {
    if (i) putchar(' ');
    printf("%d", i);
  }
  putchar('\n');
  for (int i = 0; i < n; i++) {
    if (i) putchar(' ');
    printf("%d", (i * 2) % n);
  }
  putchar('\n');
  return 0;
}

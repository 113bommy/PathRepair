#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
int main() {
  int n;
  long long a, b;
  while (scanf("%d%I64d%I64d", &n, &a, &b) != EOF) {
    long long tmp;
    for (int i = 0; i < n; i++) {
      if (i) putchar(' ');
      scanf("%I64d", &tmp);
      printf("%I64d", (tmp * a) % b / a);
    }
    putchar('\n');
  }
  return 0;
}

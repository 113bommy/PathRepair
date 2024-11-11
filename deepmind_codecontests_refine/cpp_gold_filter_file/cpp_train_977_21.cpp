#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:102400000,102400000")
int n;
int a[100009];
int b[100009], p;
int main() {
  while (scanf("%d", &n) != EOF) {
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    p = 1;
    b[0] = a[1];
    for (int i = 2; i <= n; i++) {
      int k = lower_bound(b, b + p, a[i]) - b;
      if (k == p) p++;
      b[k] = a[i];
    }
    printf("%d\n", p);
  }
}

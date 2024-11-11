#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100007;
int a[MAXN], b[MAXN], c[MAXN];
int main() {
  int n;
  while (~scanf("%d", &n)) {
    if (n % 2 == 0) {
      puts("-1");
      continue;
    }
    int i = 0, j = 1 % n;
    while (i < n) {
      a[i] = i;
      b[i] = j;
      c[i] = (i + j) % n;
      i++;
      j = (j + 1) % n;
    }
    for (i = 0; i < n; i++) printf("%d ", a[i]);
    puts("");
    for (i = 0; i < n; i++) printf("%d ", b[i]);
    puts("");
    for (i = 0; i < n; i++) printf("%d ", c[i]);
    puts("");
  }
  return 0;
}

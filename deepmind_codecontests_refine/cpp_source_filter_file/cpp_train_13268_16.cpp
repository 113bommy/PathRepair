#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  char str[110];
  while (scanf("%d", &n) != EOF) {
    int res = 0;
    for (int i = 0; i < n; i++) {
      int p, q;
      scanf("%d %d", &p, &q);
      if (p < q) res++;
    }
    printf("%d\n", res);
  }
}

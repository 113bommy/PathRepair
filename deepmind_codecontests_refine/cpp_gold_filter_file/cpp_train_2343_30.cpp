#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int w[1500005];
int main() {
  int n, i, j, sum = 0;
  while (~scanf("%d", &n)) {
    sum = 0;
    for (i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
    }
    sort(a + 1, a + 1 + n);
    memset(w, 0, sizeof(w));
    for (i = 1; i <= n; i++) {
      w[a[i]]++;
    }
    for (i = 0; i <= 1500004; i++) {
      w[i + 1] += w[i] / 2;
      if (w[i] % 2 == 1) sum++;
    }
    printf("%d\n", sum);
  }
}

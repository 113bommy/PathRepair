#include <bits/stdc++.h>
using namespace std;
int a[110];
int b[110];
int main() {
  int n, m;
  int maxx;
  int maxx1;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    maxx = 1;
    maxx1 = 0;
    for (int j = 1; j <= m; j++) {
      scanf("%d", &a[j]);
      if (a[j] > maxx1) {
        maxx = j;
        maxx1 = a[j];
      }
    }
    b[maxx]++;
  }
  maxx = 1;
  maxx1 = 0;
  for (int i = 1; i <= m; i++) {
    if (b[i] > maxx1) {
      maxx = i;
      maxx1 = b[i];
    }
  }
  printf("%d\n", maxx);
}

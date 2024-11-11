#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 2e5 + 5;
int a[N];
int n, t, x;
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &x);
      a[x] = i;
    }
    int mi = 0;
    int ma = n + 1;
    for (int i = 1; i <= n; i++) {
      mi = max(mi, a[i]);
      ma = min(ma, a[i]);
      if (mi - ma + 1 == i)
        printf("1");
      else
        printf("0");
    }
    printf("\n");
  }
}

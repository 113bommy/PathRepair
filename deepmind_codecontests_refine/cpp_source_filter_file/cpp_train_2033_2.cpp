#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2000000;
int a[MAXN];
int n, q, d, p;
int main() {
  scanf("%d %d", &n, &q);
  for (int i = 0; i < q; i++) {
    int command, move;
    scanf("%d", &command);
    if (command == 1) {
      scanf("%d", &move);
      d += move;
      if (d < 0)
        d += n;
      else if (d >= n)
        d -= n;
    } else {
      if ((p + d) % 2 == 0) {
        p++;
      } else {
        p--;
      }
    }
  }
  p %= n;
  for (int i = 1; i <= n; i++) {
    if ((i + p) % 2 != 0) {
      a[i] = i + p;
    } else {
      a[i] = i - p;
    }
  }
  for (int i = 1; i <= n; i++) {
    int pos = (i - d + n - 1) % n + 1;
    printf("%d ", (a[pos] + n - 1) % n + 1);
  }
  printf("\n");
  return 0;
}

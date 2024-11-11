#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  scanf("%d", &n);
  int a[100000];
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  int d[3] = {-1, -1, -1};
  int l = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] == 0) {
      for (int j = l; j < i; ++j) {
        if (j == d[0])
          printf("pushStack\n");
        else if (j == d[1])
          printf("pushQueue\n");
        else if (j == d[2])
          printf("pushBack\n");
        else
          printf("pushFront\n");
      }
      printf("%d", (d[0] > 0) + (d[1] > 0) + (d[2] > 0));
      printf("%s%s%s\n", d[0] > 0 ? " popStack" : "",
             d[1] > 0 ? " popQueue" : "", d[2] > 0 ? " popBack" : "");
      d[0] = d[1] = d[2] = -1;
      l = i + 1;
    } else {
      for (int j = 0; j < 3; ++j)
        if (d[j] == -1 || a[i] > a[d[j]]) {
          for (int k = 2; k > j; --k) d[k] = d[k - 1];
          d[j] = i;
          break;
        }
    }
  }
  for (int i = l; i < n; ++i) printf("pushFront\n");
}
int main() {
  solve();
  return 0;
}

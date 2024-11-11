#include <bits/stdc++.h>
using namespace std;
void prepare() {}
int n;
int a[105];
void solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  int r = 0, ri = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] != 1) continue;
    int cur = 1;
    int p = 1;
    for (int j = i + 1; j < n; j++) {
      if (a[j] == p + 1) {
        p = a[j];
        cur++;
      }
    }
    if (r < cur) {
      r = cur;
      ri = i;
    }
  }
  if (r == 1)
    printf("0\n");
  else {
    printf("%d\n", r);
    int p = 0;
    for (int j = ri; j < n; j++) {
      if (a[j] == p + 1) {
        printf("%d ", 2001 + j);
        p = a[j];
      }
    }
  }
}
int main() {
  prepare();
  solve();
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int maxn = 500005;
int n, run, ans;
int a[maxn];
int main() {
  scanf("%d", &n);
  run = 0;
  ans = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    if (i) {
      if (a[i] != a[i - 1]) {
        run++;
        if (run % 2 == 0) {
          a[i - 1] = a[i];
        }
      } else {
        if (run > 1 && run % 2 == 1) {
          for (int j = 0; j < run / 2; j++) {
            a[i - 2 - j] = a[i];
          }
        }
        ans = max(ans, run / 2);
        run = 0;
      }
    }
  }
  ans = max(ans, run / 2);
  if (run > 0 && run % 2 == 0) {
    a[n - 2] = a[n - 1];
  } else if (run > 1 && run % 2 == 1) {
    for (int j = 0; j < run / 2; j++) {
      a[n - 2 - j] = a[n - 1];
    }
  }
  printf("%d\n", ans);
  for (int i = 0; i < n; i++) {
    if (i) printf(" ");
    printf("%d", a[i]);
  }
  puts("");
}

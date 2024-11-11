#include <bits/stdc++.h>
using namespace std;
int a[200001], b[200001];
int main(void) {
  int n;
  while (~scanf("%d", &n)) {
    int i;
    for (i = 0; i < n; i++) {
      scanf("%d", &a[i]);
    }
    for (i = 0; i < n; i++) {
      scanf("%d", &b[i]);
    }
    int j;
    int ans = 0;
    i = j = 0;
    while (i < n && j < n) {
      if (a[i] == b[j]) {
        i++;
        j++;
      } else {
        ans++;
        j++;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int s[50001];
signed main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < (n); i++) {
      scanf("%d", &s[i]);
    }
    for (int i = 1; i < n - 1; i++) {
      if (s[0] + s[i] < s[n - 1]) {
        printf("%d %d %d\n", 1, i + 1, n);
        goto hell;
      }
    }
    printf("-1\n");
  hell : {}
  }
}

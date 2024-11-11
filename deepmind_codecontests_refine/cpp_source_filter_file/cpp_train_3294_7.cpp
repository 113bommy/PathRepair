#include <bits/stdc++.h>
using namespace std;
int mx[103];
int done[103];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
      mx[i] = n + 1;
      done[i] = 0;
    }
    for (int i = 1; i <= k; i++) {
      int a;
      scanf("%d", &a);
      done[a] = 1;
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (done[j]) {
          mx[i] = min(abs(i - j) + 1, mx[i]);
        }
      }
    }
    int an = 0;
    for (int i = 1; i <= n; i++) {
      an = max(an, mx[i]);
    }
    printf("%d\n", an);
  }
}

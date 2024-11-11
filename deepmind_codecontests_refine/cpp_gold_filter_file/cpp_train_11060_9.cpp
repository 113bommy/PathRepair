#include <bits/stdc++.h>
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, sume = 0, sumo = 0;
    scanf("%d", &n);
    int a[n], count = 0, k = n / 2;
    if (k % 2 == 0) {
      printf("YES\n");
      for (int i = 2; count < n / 2; i = i + 2) {
        printf("%d ", i);
        sume += i;
        count++;
      }
      for (int i = 1; count < n - 1; i = i + 2) {
        printf("%d ", i);
        sumo += i;
        count++;
      }
      printf("%d\n", sume - sumo);
    } else {
      printf("NO\n");
    }
  }
}

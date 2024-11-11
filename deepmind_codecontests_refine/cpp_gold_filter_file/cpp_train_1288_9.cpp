#include <bits/stdc++.h>
using namespace std;
int n, m, arr[1000001], k[1000001];
int main() {
  scanf("%d %d", &n, &m);
  if (n / m < 3)
    printf("-1\n");
  else {
    memset(k, 0, sizeof(k));
    int coun = 1;
    for (int i = 1; i <= n; i++) {
      if (i <= m) {
        arr[i] = i;
        k[i]++;
      } else {
        arr[i] = coun;
        k[coun]++;
        if (coun != m) {
          if (k[coun] == (n / m)) coun++;
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      printf("%d", arr[i]);
      if (i == n)
        printf("\n");
      else
        printf(" ");
    }
  }
  return 0;
}

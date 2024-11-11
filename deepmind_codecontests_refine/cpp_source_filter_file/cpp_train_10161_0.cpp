#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  int *a = new int[m];
  int sum = 0;
  int r = -1;
  for (int i = 0; i < m; i++) {
    scanf("%d ", &a[i]);
    sum += a[i];
    if (a[i] == 1) r = i;
  }
  if (n > sum) {
    printf("-1");
    return 0;
  }
  sum = (((sum == n) || ((sum = n + 1) && (m == 2))) && (n % 2)) ? 1 : 0;
  if ((m == 1) && (n != 1)) sum = 1;
  if (sum == 1) {
    printf("-1");
    return 0;
  }
  int *b = new int[n];
  memset(b, 0, n * 4);
  b[0] = r + 1;
  a[r] = 0;
  for (int i = r == -1 ? 0 : 1; i < n; i++) {
    int max = -1;
    int k = -1;
    for (int j = 0; j < m; j++)
      if ((a[j] > max) && ((j + 1) != b[i - 1]) && ((j + 1) != b[(i + 1) % n]))
        max = a[j], k = j;
    if (max == 0) {
      printf("-1");
      return 0;
    }
    b[i] = k + 1;
    a[k]--;
  }
  for (int i = 0; i < n; i++) printf("%d ", b[i]);
  printf("\n");
  return 0;
}

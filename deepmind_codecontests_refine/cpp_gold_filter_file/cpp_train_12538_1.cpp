#include <bits/stdc++.h>
using namespace std;
int num[100005], a[100005], flag1[3000005], flag2[3000005], countx;
void prime() {
  memset(num, 0, sizeof(num));
  num[0] = num[1] = 1;
  for (int i = 2; i <= 100005; i++) {
    if (!num[i]) {
      for (int j = i + i; j <= 100005; j += i) num[j] = 1;
    }
  }
}
int main() {
  int i, j, n;
  prime();
  while (scanf("%d", &n) != EOF) {
    for (i = 1; i <= n; i++) scanf("%d", &a[i]);
    int m = 0;
    countx = 0;
    for (i = 1; i <= n; i++) {
      if (a[i] != i) {
        for (j = i + 1; j <= n; j++)
          if (i == a[j]) break;
        for (int k = i; k < j; k++) {
          if (!num[j - k + 1]) {
            swap(a[k], a[j]);
            flag1[m] = k;
            flag2[m++] = j;
            countx++;
            j = k;
            k = i - 1;
          }
        }
      }
    }
    printf("%d\n", countx);
    for (i = 0; i < m; i++) printf("%d %d\n", flag1[i], flag2[i]);
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int b[100005];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  if (n == 1) {
    printf("YES\n");
    printf("%d\n", m);
    return 0;
  }
  if (n == 2) {
    if (m == 0) {
      printf("NO\n");
      return 0;
    }
    printf("YES\n");
    printf("0 %d\n", m);
    return 0;
  }
  printf("YES\n");
  if (n % 4 == 0) {
    int s = 0;
    for (int i = 1e5 + 4, j = 0; j < (n - 4) / 4; i += 4, j++) {
      s ^= i ^ (i + 1) ^ (i + 2) ^ (i + 3);
      printf("%d %d %d %d ", i, i + 1, i + 2, i + 3);
    }
    if (m == 1 || m == 2 || m == 3)
      printf("4 8 12 %d\n", m);
    else
      printf("1 2 3 %d\n", m);
  } else if (n % 4 == 1) {
    for (int i = 1e5 + 4, j = 0; j < n / 4; i += 4, j++) {
      printf("%d %d %d %d ", i, i + 1, i + 2, i + 3);
    }
    printf("%d\n", m);
  } else if (n % 4 == 2) {
    for (int i = 1e5 + 4, j = 0; j < (n - 4) / 4; i += 4, j++) {
      printf("%d %d %d %d ", i, i + 1, i + 2, i + 3);
    }
    if (m == 0) {
      printf("1 2 4 5 7 0\n");
    } else
      printf("%d %d %d %d %d %d\n", 99996, 99997, 99998, 99999, m, 0);
  } else if (n % 4 == 3) {
    for (int i = 6e5, j = 0; j < (n - 4) / 4; i += 4, j++) {
      printf("%d %d %d %d ", i, i + 1, i + 2, i + 3);
    }
    int k = 30;
    for (; k >= 0; k--)
      if (m >> k & 1) break;
    k++;
    int z = 1 << k;
    printf("%d %d %d\n", z + m, z * 2 + m, 3 * z + m);
  }
}

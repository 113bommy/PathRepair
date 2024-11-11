#include <bits/stdc++.h>
using namespace std;
int n, k, l, r, sum, sk;
int a[1010];
int main() {
  while (scanf("%d%d%d%d%d%d", &n, &k, &l, &r, &sum, &sk) != EOF) {
    if (n != k) {
      int s1, s2;
      s1 = sum - sk;
      s2 = sk;
      int tmp1, tmp2;
      tmp1 = s1 / (n - k);
      tmp2 = s1 - tmp1 * (n - k);
      for (int i = 0; i < n - k; i++) {
        a[i] = tmp1;
      }
      for (int i = 0; i < tmp2; i++) {
        a[i]++;
      }
      tmp1 = s2 / k;
      tmp2 = s2 - tmp1 * k;
      for (int i = n - k; i < n; i++) {
        a[i] = tmp1;
      }
      for (int i = n - k; i < n - k + tmp2; i++) {
        a[i]++;
      }
      for (int i = 0; i < n; i++) {
        if (i == 0) {
          printf("%d", a[i]);
        } else {
          printf(" %d", a[i]);
        }
      }
      printf("\n");
    } else {
      int tmp1 = sum / n;
      int tmp2 = sum - n * tmp1;
      for (int i = 0; i < n; i++) {
        a[i] = tmp1;
      }
      for (int i = 0; i < tmp2; i++) {
        a[i]++;
      }
      for (int i = 0; i < n; i++) {
        if (i == 0) {
          printf("%d", a[i]);
        } else {
          printf(" %d", a[i]);
        }
      }
      printf("\n");
    }
  }
}

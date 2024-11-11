#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  int n, ind;
  scanf("%d", &n);
  int a[n];
  int gcdd;
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  gcdd = a[0];
  for (int i = 1; i < n; i++) gcdd = gcd(gcdd, a[i]);
  int f = 0;
  int odd = 0;
  for (int i = 0; i < n; i++)
    if (a[i] & 1) odd++;
  for (int i = 0; i < n; i++) a[i] /= gcdd;
  if (!odd) {
    printf("%d\n", gcdd);
    int m = gcdd;
    while (m) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < a[i]; j++) printf("%c", i + 97);
      }
      for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < a[i]; j++) printf("%c", i + 97);
      }
      m = m - 2;
    }
    printf("\n");
  } else if (odd == 1) {
    printf("%d\n", gcdd);
    while (gcdd--) {
      for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0)
          for (int j = 0; j < a[i] / 2; j++) printf("%c", i + 97);
        else
          ind = i;
      }
      int k = a[ind];
      for (int j = 0; j < k; j++) printf("%c", ind + 97);
      for (int i = n - 1; i >= 0; i--) {
        if (a[i] % 2 == 0)
          for (int j = 0; j < a[i] / 2; j++) printf("%c", i + 97);
      }
    }
    printf("\n");
  } else {
    printf("0\n");
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < a[i] * gcdd; j++) printf("%c", i + 97);
    }
    printf("\n");
  }
  return 0;
}

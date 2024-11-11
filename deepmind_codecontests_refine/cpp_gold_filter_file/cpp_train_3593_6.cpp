#include <bits/stdc++.h>
using namespace std;
int n, a[100005];
char b[100005];
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  scanf("%d", &n);
  int mark = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    if (a[i] % 2) mark++;
  }
  if (mark >= 2) {
    printf("0\n");
    for (int i = 0; i < n; i++) {
      for (int j = 1; j <= a[i + 1]; j++) printf("%c", 'a' + i);
    }
    printf("\n");
  } else {
    int ci;
    ci = a[1];
    for (int i = 2; i <= n; i++) {
      ci = gcd(ci, a[i]);
    }
    printf("%d\n", ci);
    mark = 0;
    int mark2, sum = 0;
    for (int i = 1; i <= n; i++) {
      a[i] /= ci;
      if (a[i] % 2) {
        mark++;
        mark2 = i;
      }
      sum += a[i];
    }
    int T = 1;
    if (mark >= 2) {
      for (int i = 0; i < n; i++)
        for (int j = 1; j <= a[i + 1]; j++) b[T++] = 'a' + i;
      T--;
    } else {
      T = sum;
      b[sum / 2 + 1] = 'a' + mark2 - 1;
      a[mark2]--;
      int l = 1, r = sum;
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= a[i] / 2; j++) {
          b[l++] = 'a' + i - 1;
          b[r--] = 'a' + i - 1;
        }
      }
    }
    for (int i = 1; i <= ci; i++) {
      if (i % 2)
        for (int j = 1; j <= T; j++) printf("%c", b[j]);
      else
        for (int j = T; j >= 1; j--) printf("%c", b[j]);
    }
    printf("\n");
  }
}

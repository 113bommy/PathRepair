#include <bits/stdc++.h>
using namespace std;
template <class T>
T sqr(const T &a) {
  return a * a;
}
int k, x, n, m;
long long a[200], b[200], c[200], d[200], e[200];
int main() {
  scanf("%d%d%d%d", &k, &x, &n, &m);
  b[1] = b[2] = 1;
  c[1] = c[2] = 1;
  d[1] = 0, d[2] = 1;
  e[1] = 1, e[2] = 2;
  for (int i = 3; i < 60; i++)
    b[i] = b[i - 1] + b[i - 2], c[i] = c[i - 1] + c[i - 2] + (i % 2),
    d[i] = d[i - 1] + d[i - 2] + (1 - i % 2), e[i] = e[i - 1] + e[i - 2] + 1;
  for (int i = 0; i < n / 2 + 1; i++)
    for (int j = 0; j < m / 2 + 1; j++) {
      a[0] = i, a[1] = j;
      for (int l = 2; l < k; l++) a[l] = a[l - 1] + a[l - 2];
      if (a[k - 1] == x) {
        for (int l = 0; l < i; l++) printf("AC");
        for (int l = 0; l < n - 2 * i; l++) printf("X");
        puts("");
        for (int l = 0; l < j; l++) printf("AC");
        for (int l = 0; l < m - 2 * j; l++) printf("X");
        return 0;
      }
      if (a[k - 1] == x - c[k - 3] && 2 * i + 1 <= n && 2 * j + 1 <= m) {
        printf("C");
        for (int l = 0; l < i; l++) printf("AC");
        for (int l = 0; l < n - 2 * i - 1; l++) printf("X");
        puts("");
        for (int l = 0; l < j; l++) printf("AC");
        for (int l = 0; l < m - 2 * j; l++) printf("A");
        return 0;
      }
      if (a[k - 1] == x - b[k - 2] && 2 * i != n && 2 * j != m) {
        for (int l = 0; l < i; l++) printf("AC");
        for (int l = 0; l < n - 2 * i - 1; l++) printf("X");
        printf("A");
        puts("");
        printf("C");
        for (int l = 0; l < j; l++) printf("AC");
        for (int l = 0; l < m - 2 * j - 1; l++) printf("X");
        return 0;
      }
      if (a[k - 1] == x - c[k - 4] && 2 * j + 2 <= m) {
        for (int l = 0; l < i; l++) printf("AC");
        for (int l = 0; l < n - 2 * i; l++) printf("X");
        puts("");
        printf("C");
        for (int l = 0; l < j; l++) printf("AC");
        for (int l = 0; l < m - 2 * j - 2; l++) printf("X");
        printf("A");
        return 0;
      }
      if (a[k - 1] == x - c[k - 2] && 2 * i + 1 <= n && 2 * j + 2 <= m) {
        for (int l = 0; l < i; l++) printf("AC");
        for (int l = 0; l < n - 2 * i - 1; l++) printf("X");
        printf("A");
        puts("");
        printf("C");
        for (int l = 0; l < j; l++) printf("AC");
        for (int l = 0; l < m - 2 * j - 2; l++) printf("X");
        printf("A");
        return 0;
      }
      if (a[k - 1] == x - d[k - 2] && 2 * i + 2 <= n && 2 * j + 1 <= m) {
        printf("C");
        for (int l = 0; l < i; l++) printf("AC");
        for (int l = 0; l < n - 2 * i - 2; l++) printf("X");
        printf("A");
        puts("");
        for (int l = 0; l < j; l++) printf("AC");
        for (int l = 0; l < m - 2 * j - 1; l++) printf("X");
        printf("A");
        return 0;
      }
      if (a[k - 1] == x - e[k - 2] && 2 * i + 2 <= n && 2 * j + 2 <= m) {
        printf("C");
        for (int l = 0; l < i; l++) printf("AC");
        for (int l = 0; l < n - 2 * i - 2; l++) printf("X");
        printf("A");
        puts("");
        printf("C");
        for (int l = 0; l < j; l++) printf("AC");
        for (int l = 0; l < m - 2 * j - 2; l++) printf("X");
        printf("A");
        return 0;
      }
    }
  puts("Happy new year!");
}

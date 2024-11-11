#include <bits/stdc++.h>
void f(int vec[], int n) {
  if (n == 1) {
    vec[0] = 1;
  } else if (n == 2) {
    vec[0] = 3, vec[1] = 4;
  } else if (n % 2 == 0) {
    for (int i = (0); (i) < int(n - 1); ++i) vec[i] = 1;
    vec[n - 1] = (n - 2) / 2;
  } else {
    for (int i = (0); (i) < int(n - 2); ++i) vec[i] = 1;
    vec[n - 2] = 2;
    vec[n - 1] = (n + 1) / 2;
  }
}
int main() {
  int n, m, a[105], b[105];
  while (scanf("%d %d", &n, &m) != EOF) {
    f(a, n), f(b, m);
    for (int i = (0); (i) < int(n); ++i) {
      for (int j = (0); (j) < int(m); ++j) printf("%d ", a[i] * b[j]);
      puts("");
    }
  }
  return 0;
}

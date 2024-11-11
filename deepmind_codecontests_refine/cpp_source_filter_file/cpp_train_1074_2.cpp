#include <bits/stdc++.h>
int s[101];
int cmp(const void* a, const void* b) { return *(int*)a > *(int*)b ? 1 : -1; }
int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    int i;
    double sum = 0.0;
    for (i = 0; i < n; ++i) {
      scanf("%d", &s[i]);
    }
    qsort(s, n, sizeof(int), cmp);
    s[n] = 0;
    for (i = 0; i < n; i += 2) {
      sum = sum + (s[i] * s[i] - s[i + 1] * s[i + 1]) * 3.1415926536;
    }
    printf("%.10lf\n", sum);
  }
  return 0;
}

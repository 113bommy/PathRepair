#include <bits/stdc++.h>
using namespace std;
int Compare(const void *elem1, const void *elem2) {
  return *((int *)(elem1)) - *((int *)(elem2));
}
const int MAXN = 5000;
int a[MAXN], b[MAXN], c[MAXN];
unsigned long long f[2][MAXN];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    c[i] = a[i];
  }
  qsort(c, n, sizeof(int), Compare);
  int k = 0;
  b[k++] = c[0];
  for (int i = 1; i < n; i++)
    if (c[i] != c[i - 1]) b[k++] = c[i];
  memset(f, 0, sizeof(f));
  unsigned long long *fa, *fb;
  fa = (unsigned long long *)f[0];
  fa[0] = abs(a[0] - b[0]);
  for (int j = 1; j < k; j++)
    fa[j] = min((unsigned long long)abs(a[0] - b[j]), fa[j - 1]);
  fb = (unsigned long long *)f[1];
  for (int i = 1; i < n; i++) {
    fb[0] = abs(a[i] - b[0]) + fa[0];
    for (int j = 1; j < k; j++)
      fb[j] = min(fb[j - 1], fa[j] + abs(a[i] - b[j]));
    swap(fa, fb);
  }
  printf("%d", fa[k - 1]);
}

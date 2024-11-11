#include <bits/stdc++.h>
using namespace std;
const int N = 10010 * 2;
int s[N], p[N], a[N], b[N];
int cmp(int i, int j) { return s[i] < s[j]; }
int main() {
  int n, m;
  scanf("%d", &n);
  m = (n + 2) / 3;
  printf("YES\n");
  for (int i = 0; i < n; i++) scanf("%d", &s[i]), p[i] = i;
  sort(p, p + n);
  for (int i = 0; i < m; i++) {
    a[p[i]] = i;
    b[p[i]] = s[p[i]] - i;
  }
  for (int i = m; i < n - m; i++) {
    b[p[i]] = i;
    a[p[i]] = s[p[i]] - i;
  }
  for (int i = n - m; i < n; i++) {
    int tmp = n - i - 1;
    b[p[i]] = tmp;
    a[p[i]] = s[p[i]] - tmp;
  }
  for (int i = 0; i < n; i++) {
    i == 0 ? printf("%d", a[i]) : printf(" %d", a[i]);
  }
  printf("\n");
  for (int i = 0; i < n; i++) {
    i == 0 ? printf("%d", b[i]) : printf(" %d", b[i]);
  }
  printf("\n");
  return 0;
}

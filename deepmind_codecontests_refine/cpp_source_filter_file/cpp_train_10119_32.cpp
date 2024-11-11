#include <bits/stdc++.h>
using namespace std;
int mins, n, k, a[10], last[10];
char str[10][10];
struct s {
  char str1[10];
} na[10];
bool cmp(s c, s d) {
  if (strcmp(c.str1, d.str1) > 0) return true;
  return false;
}
void solve() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k; j++) na[i].str1[j] = str[i][a[j] - 1];
    na[i].str1[k] = '\0';
  }
  sort(na, na + n, cmp);
  int c = atoi(na[0].str1), d = atoi(na[n - 1].str1);
  int t = c - d;
  if (t < mins) mins = t;
}
int main() {
  while (scanf("%d %d", &n, &k) == 2) {
    mins = 10000000;
    for (int i = 0; i < n; i++) {
      scanf("%s", str[i]);
      strcpy(na[i].str1, str[i]);
    }
    if (k == 1) {
      sort(na, na + n, cmp);
      printf("%d\n", na[0].str1[0] - na[n - 1].str1[0]);
      continue;
    }
    for (int i = 0; i < k; i++) a[i] = i + 1;
    do {
      if (!equal(a, a + k, last)) {
        copy(a, a + k, last);
        solve();
      }
    } while (next_permutation(a, a + k));
    printf("%d\n", mins);
  }
  return 0;
}

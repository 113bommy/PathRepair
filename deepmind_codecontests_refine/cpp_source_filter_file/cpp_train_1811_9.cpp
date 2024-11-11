#include <bits/stdc++.h>
using namespace std;
int n, m, mmax, s[5005], f[1000005], smax;
bool flag[1000005];
int comp(const void *a, const void *b) { return *(int *)a - *(int *)b; }
int calcans(void) {
  int ans, i, j, same;
  for (ans = 1;; ans++) {
    for (i = ans, same = 0; i <= smax; i += ans) {
      same += f[i];
      if (same > mmax) break;
    }
    if (same > mmax) continue;
    for (i = same = 0; i < n; i++) {
      if (!flag[s[i] % ans])
        flag[s[i] % ans] = true;
      else
        same++;
      if (same > m) break;
    }
    if (same <= m) return ans;
    for (j = 0; j < i; j++) flag[s[i] % ans] = false;
  }
}
int main() {
  int i, j;
  scanf("%d%d", &n, &m);
  mmax = (m + 1) * m / 2;
  memset(f, 0, sizeof(f));
  memset(flag, 0, sizeof(flag));
  for (i = 0; i < n; i++) scanf("%d", &s[i]);
  qsort(s, n, sizeof(int), comp);
  smax = s[n - 1] - s[0];
  for (i = 0; i < n; i++)
    for (j = i + 1; j < n; j++) f[s[j] - s[i]]++;
  printf("%d\n", calcans());
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int in[100010], a1[100010], a2[100010], min1[100010], min2[100010],
    len1[100010], len2[100010];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    in[x]++;
    in[y + 1]--;
  }
  for (int i = 1; i <= m; i++) {
    a1[i] = a1[i - 1] + in[i];
    a2[m + 1 - i] = a1[i];
  }
  for (int i = 1; i <= m; i++) min1[i] = m + 1;
  min1[1] = a1[1];
  len1[1] = 1;
  for (int i = 2; i <= m; i++) {
    len1[i] = upper_bound(min1, min1 + i, a1[i]) - min1;
    min1[len1[i]] = min(min1[len1[i]], a1[i]);
  }
  for (int i = 1; i <= m; i++) min2[i] = m + 1;
  min2[1] = a2[1];
  len2[1] = 1;
  for (int i = 2; i <= m; i++) {
    len2[i] = upper_bound(min2, min2 + i, a2[i]) - min2;
    min2[len2[i]] = min(min2[len2[i]], a2[i]);
  }
  int ans = 0;
  for (int i = 1; i <= m; i++) ans = max(ans, len1[i] + len2[m + 1 - i] - 1);
  printf("%d\n", ans);
}

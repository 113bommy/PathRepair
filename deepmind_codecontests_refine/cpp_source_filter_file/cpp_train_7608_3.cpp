#include <bits/stdc++.h>
using namespace std;
int n, m, Q, k, len;
int w[14];
int num[(1 << 12) + 10], ans[(1 << 12) + 10];
int ret[(1 << 12) + 10][104];
char s[14];
void DFS(int x, int sum) {
  if (x >= n) {
    for (int i = 0; i < len; i++) {
      if (!num[i]) continue;
      ret[sum][min(ans[i], 100)] += num[i];
    }
    return;
  }
  for (int i = 0; i < len; i++) ans[i] += ((1 << x) & i) ? 0 : w[x];
  DFS(x + 1, sum);
  for (int i = 0; i < len; i++) ans[i] -= ((1 << x) & i) ? 0 : w[x];
  for (int i = 0; i < len; i++) ans[i] += ((1 << x) & i) ? w[x] : 0;
  DFS(x + 1, sum + (1 << x));
  for (int i = 0; i < len; i++) ans[i] -= ((1 << x) & i) ? w[x] : 0;
}
int main() {
  scanf("%d%d%d", &n, &m, &Q);
  len = (1 << n);
  for (int i = 0; i < n; i++) scanf("%d", &w[i]);
  for (int i = 1; i <= m; i++) {
    scanf("%s", s);
    int sum = 0;
    for (int j = 0; j < n; j++) sum = sum + (s[j] == '1' ? 1 : 0) * (1 << j);
    num[sum]++;
  }
  DFS(0, 0);
  for (int i = 1; i <= Q; i++) {
    scanf("%s%d", s, &k);
    int gg = 0;
    int sum = 0;
    for (int j = 0; j < n; j++) sum = sum + (s[j] == '1' ? 1 : 0) * (1 << j);
    for (int j = 0; j <= k; j++) {
      gg += ret[sum][j];
    }
    printf("%d\n", gg);
  }
  return 0;
}

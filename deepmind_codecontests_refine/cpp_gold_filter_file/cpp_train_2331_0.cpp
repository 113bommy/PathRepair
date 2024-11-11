#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e3;
int n, min_val, ncnt, a[N];
bool was[N];
bool comp(int a, int b) { return abs(a) < abs(b); }
void dfs(int cnt) {
  min_val = min(min_val, cnt);
  was[cnt] = true;
  for (int i = 0; i <= cnt; i++)
    for (int j = 0; j <= ncnt; j++) {
      if (i + j <= n && 2 * n - 1 - cnt - ncnt >= n - i - j) {
        if (!was[cnt - i + n - i - j]) dfs(cnt - i + n - i - j);
      }
    }
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < 2 * n - 1; i++) scanf("%d", &a[i]);
  sort(a, a + 2 * n - 1, comp);
  int cnt = 0;
  for (int i = 0; i < 2 * n - 1; i++)
    if (a[i] < 0)
      cnt++;
    else if (a[i] == 0)
      ncnt++;
  min_val = 2 * n - 1;
  dfs(cnt);
  int res = 0;
  for (int i = 0; i < 2 * n - 1; i++)
    if (i < min_val)
      res -= abs(a[i]);
    else
      res += abs(a[i]);
  printf("%d\n", res);
  return 0;
}

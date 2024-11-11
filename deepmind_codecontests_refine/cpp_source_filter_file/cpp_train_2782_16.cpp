#include <bits/stdc++.h>
using namespace std;
char n[20];
int len, cnt[20], le[20];
long long ans, f[20] = {1, 1};
void dfs(int u) {
  if (u == 10) {
    int llen = 0;
    for (int i = 0; i <= 9; i++) llen += le[i];
    long long ret = 0;
    ret += f[llen];
    ret -= le[0] * (f[llen - 1]);
    for (int i = 0; i <= 9; i++) ret /= f[le[i]];
    ans += ret;
    return;
  }
  if (cnt[u] == 0)
    dfs(u + 1);
  else
    for (int i = 1; i <= cnt[u]; i++) le[u] = i, dfs(u + 1);
}
int main() {
  for (int i = 2; i <= 18; i++) f[i] = f[i - 1] * i;
  scanf("%s", n + 1);
  len = strlen(n + 1);
  for (int i = 1; i <= len; i++) cnt[n[i] - '0']++;
  dfs(0);
  printf("%lld\n", ans);
}

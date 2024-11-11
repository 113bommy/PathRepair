#include <bits/stdc++.h>
using namespace std;
int n;
char a[5005][5005];
bool vst[5005];
bool dfs(int s, int k) {
  if (vst[k]) return false;
  vst[k] = true;
  for (int i = 0; i < n; ++i) {
    if (a[k][i] == '1') {
      if (a[i][s] == '1')
        return printf("%d %d %d\n", s + 1, k + 1, i + 1), true;
      if (dfs(s, i)) return true;
    }
  }
  return false;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%s", a[i]);
  int i;
  for (i = 0; i < n; ++i)
    if (dfs(i, i)) break;
  if (i == n) puts("-1");
}

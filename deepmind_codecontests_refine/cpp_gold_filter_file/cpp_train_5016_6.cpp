#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3f;
const int MOD = (int)1e9 + 7;
const int N = (int)2e5 + 7;
int p[N], q[N], pre[N], pos[N];
char ans[N], c[N];
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = (1); i < (n + 1); ++i) scanf("%d", &p[i]);
  for (int i = (1); i < (n + 1); ++i) scanf("%d", &q[i]);
  for (int i = (1); i < (n + 1); ++i) pos[p[i]] = i;
  for (int i = (1); i < (n); ++i) {
    pre[pos[q[i]]] = pos[q[i + 1]];
  }
  pre[pos[q[n]]] = n + 1;
  int mn = n + 1;
  c[n + 1] = 'z' + 1;
  for (int i = (n + 1) - 1; i >= (1); --i) {
    if (i >= mn)
      c[i] = c[i + 1];
    else
      c[i] = max((int)'a', c[i + 1] - 1);
    mn = min(mn, pre[i]);
  }
  for (int i = (1); i < (n + 1); ++i) {
    ans[p[i]] = c[i];
  }
  if ('z' - c[1] + 1 >= k) {
    printf("YES\n");
    printf("%s\n", ans + 1);
  } else {
    printf("NO\n");
  }
  return 0;
}

#include <bits/stdc++.h>
const int N = 5e3 + 5;
const int M = 205;
const int INF = 0x3f3f3f;
using namespace std;
int num[N];
int len[N];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  fill(len + 1, len + n + 1, INF);
  for (int i = 1; i <= m; i++) {
    int v, w;
    scanf("%d%d", &v, &w);
    num[v]++;
    if (v < w)
      len[v] = min(len[v], w - v);
    else
      len[v] = min(len[v], n - v + w);
  }
  for (int i = 1; i <= n; i++)
    if (num[i] == 0) len[i] = 0;
  for (int i = 1; i <= n; i++) {
    int ans = 0;
    for (int j = 1; j <= n; j++) {
      int tmp;
      if (j >= i)
        tmp = j - i;
      else
        tmp = n - i + j;
      tmp += (num[j] - 1) * n + len[j];
      ans = max(tmp, ans);
    }
    printf("%d\n", ans);
  }
  return 0;
}

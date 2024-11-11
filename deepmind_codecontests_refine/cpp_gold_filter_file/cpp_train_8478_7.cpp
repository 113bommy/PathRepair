#include <bits/stdc++.h>
using namespace std;
int g[100001], v[100001], b[100001], bl[100001];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &g[i]);
  for (int i = 1; i <= m; i++) scanf("%d", &v[i]);
  for (int i = 1; i <= m; i++) scanf("%d", &b[i]);
  int cnt = 0;
  for (int i = 1; i <= m; i++) {
    int ans = 0;
    for (int j = (v[i] + cnt - 1) % n + 1; bl[j] < b[i]; j = g[j]) {
      if (bl[j] == 0) ans++;
      bl[j] = b[i];
      b[i]--;
    }
    cnt = ans;
    printf("%d\n", ans);
  }
}

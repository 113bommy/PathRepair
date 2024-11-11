#include <bits/stdc++.h>
using namespace std;
int n, m;
int f[100005], b[100005], idx[100005], a[100005];
int main() {
  cin >> n >> m;
  memset(idx, 0, sizeof(idx));
  for (int i = 0; i < n; i++) cin >> f[i + 1];
  for (int i = 0; i < m; i++) cin >> b[i + 1];
  for (int i = 1; i <= n; i++) {
    if (idx[f[i]] == 0) {
      idx[f[i]] = i;
    } else
      idx[f[i]] = -1;
  }
  bool am;
  for (int i = 1; i <= m; i++) {
    if (idx[b[i]] == -1) am = 1;
    if (idx[b[i]] == 0) {
      printf("Impossible\n");
      return 0;
    }
    a[i] = idx[b[i]];
  }
  if (am) {
    printf("Ambiguity\n");
    return 0;
  }
  for (int i = 1; i <= m; i++) assert(b[i] == f[a[i]]);
  printf("Possible\n");
  printf("%d", a[1]);
  for (int i = 2; i <= m; i++) printf(" %d", a[i]);
  printf("\n");
}

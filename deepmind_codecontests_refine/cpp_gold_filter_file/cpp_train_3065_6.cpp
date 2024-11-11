#include <bits/stdc++.h>
using namespace std;
int n, m, s, e;
int f[330];
vector<int> id[100010];
int main() {
  scanf("%d%d%d%d", &n, &m, &s, &e);
  f[0] = 0;
  for (int i = 1; i <= 300; i++) f[i] = n + 1;
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    id[x].push_back(i);
  }
  int ret = 0;
  for (int i = 1; i <= m; i++) {
    int x;
    scanf("%d", &x);
    for (int j = 300; j >= 0; j--) {
      if (f[j] < n) {
        vector<int>::iterator it =
            upper_bound(id[x].begin(), id[x].end(), f[j]);
        if (it != id[x].end()) {
          f[j + 1] = min(f[j + 1], *it);
          if ((j + 1) * e + i + f[j + 1] <= s) ret = max(ret, j + 1);
        }
      }
    }
  }
  printf("%d", ret);
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int s[110000], len;
int rup[10], rdn[10], cup[10], cdn[10];
int main() {
  for (int i = 0; i < 10; ++i) rdn[i] = cdn[i] = 99999999;
  scanf("%d %d %d %d", &n, &m, &k, &len);
  for (int i = 1; i <= n; ++i)
    for (int j = 1, jj; j <= m; ++j) {
      scanf("%d", &jj);
      rup[jj] = max(rup[jj], i + j);
      rdn[jj] = min(rdn[jj], i + j);
      cup[jj] = max(cup[jj], i + m - j);
      cdn[jj] = min(cdn[jj], i + m - j);
    }
  for (int i = 1; i <= len; ++i) scanf("%d", &s[i]);
  int res = 0;
  for (int i = 2; i <= len; ++i)
    res = max(res,
              max(max(rup[s[i - 1]] - rdn[s[i]], rup[s[i]] - rdn[s[i]]),
                  max(cup[s[i - 1]] - cdn[s[i]], cup[s[i]] - cdn[s[i - 1]])));
  printf("%d\n", res);
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int maxn = 200000 + 25;
int n, t, K, size, c[maxn], F[maxn], cur, ans, L, R;
vector<int> v[maxn];
int main() {
  scanf("%d%d%d", &n, &t, &K);
  size = 1, c[0] = 1, v[0].push_back(1);
  for (int i = 1; i <= t; i++) {
    scanf("%d", &c[i]);
    for (int j = 1; j <= c[i]; j++) v[i].push_back(++size);
  }
  L = c[t], R = c[t];
  for (int i = 1; i <= t; i++) {
    R += c[i - 1] - 1;
    if (c[i] < c[i - 1]) L += c[i - 1] - c[i];
  }
  if ((K < L) || (K > R)) {
    printf("%d\n", -1);
    return 0;
  }
  ans = R;
  for (int i = 1; i <= t; i++)
    for (int j = 0; j <= c[i] - 1; j++) F[v[i][j]] = v[i - 1][0];
  for (int i = t; i >= 1; i--) {
    cur = 0;
    for (int j = 1; j <= c[i] - 1; j++) {
      if (ans == K) break;
      if (cur == c[i - 1] - 1) break;
      F[v[i][j]] = v[i - 1][++cur], ans--;
      if (ans == K) break;
    }
    if (ans == K) break;
  }
  printf("%d\n", n);
  for (int i = 2; i <= n; i++) printf("%d %d\n", i, F[i]);
  return 0;
}

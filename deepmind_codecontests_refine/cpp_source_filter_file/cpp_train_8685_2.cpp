#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 30;
const long long LLINF = 1LL << 62;
const int mod = 1000000007;
int n, m, i, j;
int nv[105], mv[105];
void completearray(int n, int v[]) {
  if (n == 1)
    v[1] = 1;
  else if (n == 2) {
    v[1] = 2;
    v[2] = 3;
  } else if (n % 2 == 0) {
    for (i = 1; i < n; i++) v[i] = 1;
    v[n] = (n / 2 - 1);
  } else {
    for (i = 1; i < n - 1; i++) v[i] = 1;
    v[n - 1] = 2;
    v[n] = (n / 2 + 1);
  }
}
int main() {
  scanf("%d%d", &n, &m);
  completearray(n, nv);
  completearray(m, mv);
  for (i = 1; i <= n; i++, printf("\n"))
    for (j = 1; j <= m; j++) printf("%d ", nv[i] * mv[j]);
  return 0;
}

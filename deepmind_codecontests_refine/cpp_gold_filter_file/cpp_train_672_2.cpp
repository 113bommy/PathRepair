#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int P[N], ar[N];
long long c[N];
vector<int> v[N];
bool used[N];
void init() {
  P[1] = 1;
  int i, j;
  for (i = 1; i < N; ++i)
    for (j = (i * 2); j < N; j += i) P[j] -= P[i];
}
int main() {
  int tt, q, x, n, i, j;
  scanf("%d%d", &n, &q);
  long long ret = 0;
  init();
  for (i = 1; i <= n; ++i) {
    scanf("%d", &ar[i]);
    x = ar[i];
    for (j = 1; j * j <= x; ++j)
      if (x % j == 0) {
        if (P[j] != 0) v[i].push_back(j);
        if ((x / j) != j)
          if (P[x / j] != 0) v[i].push_back(x / j);
      }
  }
  for (i = 0; i < q; ++i) {
    scanf("%d", &x);
    for (j = 0; j < v[x].size(); ++j) {
      tt = v[x][j];
      ret -= c[tt] * (c[tt] - 1) / 2 * P[tt];
      if (used[x])
        --c[tt];
      else
        ++c[tt];
      ret += c[tt] * (c[tt] - 1) / 2 * P[tt];
    }
    used[x] ^= true;
    printf("%I64d\n", ret);
  }
}

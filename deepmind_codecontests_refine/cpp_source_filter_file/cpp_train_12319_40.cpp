#include <bits/stdc++.h>
using namespace std;
const int MAXN = 8900000;
int memo[MAXN], aux[MAXN], v[MAXN], a[MAXN];
int main() {
  memset(memo, -1, sizeof memo);
  memset(aux, -1, sizeof aux);
  memset(v, 0, sizeof v);
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    v[x] = 1, a[i] = x, memo[x] = x;
  }
  for (int i = 23; i >= 0; i--) {
    for (int j = 0; j <= (1 << 23); j++) aux[j] = memo[j];
    memset(memo, -1, sizeof memo);
    for (int j = 0; j <= (1 << 23); j++) {
      if (((1 << i) & j) > 0)
        memo[j] = aux[j ^ (1 << i)];
      else
        memo[j] = max(aux[j], aux[j ^ (1 << i)]);
    }
  }
  for (int i = 1; i <= n; i++) printf("%d ", memo[a[i]]);
}

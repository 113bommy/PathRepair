#include <bits/stdc++.h>
const int magicconst = 73743071;
using namespace std;
int p[100050];
const int MOD = 1000000009;
int f(int v) {
  if (p[v] == -1) return v;
  return p[v] = f(p[v]);
}
int main() {
  memset(p, -1, sizeof p);
  int n, m;
  scanf("%d%d", &n, &m);
  int res = 1;
  for (int i = 0; i < (int)(m); ++i) {
    int q, w;
    scanf("%d%d", &q, &w);
    q--, w--;
    if (f(q) == f(w))
      res = (2 * res) % MOD;
    else
      p[f(q)] = w;
    printf("%d\n", res - 1);
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
int n, Head[N], V[N], cnt, Next[N], ye[N];
long long int ge[N], a[N];
double ovo[N], maxn = 0;
void add(int u, int v) {
  V[cnt] = v;
  Next[cnt] = Head[u];
  Head[u] = cnt++;
}
void dfs(int x, int father) {
  int cc = 0;
  ge[x] = a[x];
  for (int i = Head[x]; i != -1; i = Next[i]) {
    if (V[i] != father) {
      dfs(V[i], x);
      cc++;
      ye[x] += ye[V[i]];
      ge[x] += ge[V[i]];
    }
  }
  if (cc == 0) ye[x] = 1;
  ovo[x] = ge[x] * 1.0 / ye[x];
  maxn = max(maxn, ovo[x]);
}
int main() {
  memset(Head, -1, sizeof(Head));
  scanf("%d", &n);
  for (int i = 2; i <= n; i++) {
    int u;
    scanf("%d", &u);
    add(u, i);
    add(i, u);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
  }
  dfs(1, 0);
  printf("%lld\n", (long long int)ceil(maxn));
}

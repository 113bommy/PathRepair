#include <bits/stdc++.h>
using namespace std;
int n, k, K, a[200005], o[200005], d[200005];
vector<int> v[100005];
bool b[200005];
void cty(int x, int p) {
  if (b[x]) o[x] = 1;
  for (int i = 0; i < v[x].size(); i++) {
    if (p == v[x][i]) continue;
    d[v[x][i]] = d[x] + 1;
    cty(v[x][i], x);
    o[x] += o[v[x][i]];
  }
}
long long dtx(int x, int p, int q) {
  int h = 0, l = 0;
  for (int i = 0; i < v[x].size(); i++) {
    if (p == v[x][i]) continue;
    if (o[v[x][i]] > h) h = o[v[x][i]], l = i;
  }
  if (q - o[x] + h <= o[x] - h) return 1ll * d[x] * 1ll * q;
  return dtx(v[x][l], x, q - o[x] + h - o[x] + h) +
         1ll * d[x] * 2ll * (o[x] - h);
}
int main() {
  scanf("%d%d", &n, &k);
  K = k << 1;
  for (int i = 1; i <= K; i++) scanf("%d", a + i), b[i] = 1;
  for (int i = 1; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    v[x].push_back(y);
    v[y].push_back(x);
  }
  cty(1, 0);
  long long ans = 0;
  for (int i = 1; i <= K; i++) ans += 1ll * d[a[i]];
  printf("%I64d\n", ans - dtx(1, 0, K));
  return 0;
}

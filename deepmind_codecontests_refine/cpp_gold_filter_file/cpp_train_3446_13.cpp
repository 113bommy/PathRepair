#include <bits/stdc++.h>
using namespace std;
long long n, i, w[400000], k, j, m, ans[400000];
long long d[400000];
struct st {
  long long v, b, id;
} p[400000];
bool cmp(st x1, st x2) {
  if (x1.b == x2.b) return x1.v > x2.v;
  return x1.b < x2.b;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  k = sqrt(n);
  for (i = 0; i < n; i++) cin >> w[i];
  cin >> m;
  for (i = 0; i < m; i++) cin >> p[i].v >> p[i].b, p[i].id = i;
  sort(p, p + m, cmp);
  for (i = 0; i < m; i++) {
    int v = p[i].v - 1;
    if (p[i].b <= k) {
      if (i && p[i - 1].b == p[i].b) {
        d[p[i].id] = ans[v];
        continue;
      }
      for (j = n - 1; j >= 0; j--)
        ans[j] = w[j] + ((j + p[i].b < n) ? ans[j + p[i].b] : 0);
      d[p[i].id] = ans[v];
    } else {
      ans[v] = 0;
      for (j = v; j < n; j += p[i].b) ans[v] += w[j];
      d[p[i].id] = ans[v];
    }
  }
  for (i = 0; i < m; i++) cout << d[i] << endl;
  return 0;
}

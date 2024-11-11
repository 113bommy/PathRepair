#include <bits/stdc++.h>
using namespace std;
long long int s, r, l, p[300005], a[300005], d = 1000000;
vector<long long int> v[300005];
long long int dfs(long long int n) {
  long long int i, u, y, x, x1, r1 = 0, l1 = 0;
  for (i = 0; i < v[n].size(); i++) {
    u = v[n][i];
    if (p[u] == 0) {
      p[u] = 1;
      y = dfs(u);
      x = y / d;
      x1 = y % d;
      r1 = r1 + x;
      l1 = l1 + x1;
    }
  }
  if (a[n] == 1)
    r1++;
  else if (a[n] == 2)
    l1++;
  if (r1 == 0 && (l - l1) == 0)
    s++;
  else if ((r - r1) == 0 && l1 == 0)
    s++;
  return (r1 * d + l1);
}
int main() {
  long long int i, j, k, t, m, n;
  scanf("%lld", &n);
  s = 0;
  r = 0;
  l = 0;
  for (i = 0; i < n; i++) {
    scanf("%lld", &a[i + 1]);
    if (a[i + 1] == 1)
      r++;
    else if (a[i + 1] == 2)
      l++;
    p[i + 1] = 0;
  }
  for (i = 1; i < n; i++) {
    scanf("%lld%lld", &j, &k);
    v[j].push_back(k);
    v[k].push_back(j);
  }
  p[1] = 1;
  dfs(1);
  printf("%lld", s);
  return 0;
}

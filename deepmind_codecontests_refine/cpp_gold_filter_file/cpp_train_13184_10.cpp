#include <bits/stdc++.h>
using namespace std;
vector<long long> v[200004], v1[200004];
multiset<long long> s;
int n, m, x, y, i, k, j;
long long z, c, w, q, a[200004];
multiset<long long>::iterator it;
int main() {
  scanf("%d %d", &n, &m);
  for (i = 1; i <= m; i++) {
    scanf("%d %d %I64d", &x, &y, &c);
    c = (1LL) * c * 2;
    v[x].push_back(c);
    v[y].push_back(c);
    v1[x].push_back(y);
    v1[y].push_back(x);
  }
  for (i = 1; i <= n; i++) {
    scanf("%I64d", &z);
    z = (1LL) * z * 1000000 + i;
    s.insert(z);
    a[i] = z;
  }
  for (i = 1; i <= n; i++) {
    z = *s.begin();
    w = (1LL) * z % 1000000;
    z = (1LL) * z / 1000000;
    k = v[w].size();
    k--;
    for (j = 0; j <= k; j++) {
      q = (0LL) + z + v[w][j];
      q = (1LL) * q * 1000000 + v1[w][j];
      if (q < a[v1[w][j]]) {
        it = s.find(a[v1[w][j]]);
        s.erase(it);
        a[v1[w][j]] = (0LL) + q;
        s.insert(a[v1[w][j]]);
      }
    }
    s.erase(s.begin());
  }
  for (i = 1; i <= n; i++) {
    a[i] = (1LL) * a[i] / 1000000;
    printf("%I64d ", a[i]);
  }
  printf("\n");
  return 0;
}

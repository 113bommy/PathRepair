#include <bits/stdc++.h>
using namespace std;
const int INF = 2147483647;
const int N = 200005;
int z, n, p[N], m[N], kol[N], w, alr, bid[N], last, i;
long long res;
set<pair<int, int> > s;
set<pair<int, int> >::iterator pp;
bool cmp(int a, int b) { return m[a] < m[b]; }
int main() {
  scanf("%d", &z);
  while (z--) {
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
      scanf("%d %d", &m[i], &p[i]);
      kol[i] = i;
    }
    sort(kol, kol + n, cmp);
    last = 0;
    for (i = 0; i < n; i++) {
      w = kol[i];
      if (m[w] == last) {
        bid[w] = 0;
        continue;
      }
      bid[w] = max(0, m[w] - i);
      last = m[w];
    }
    s.clear();
    alr = 0;
    res = 0;
    for (i = n - 1; i >= 0; i--) {
      w = kol[i];
      s.insert(pair<int, int>(p[i], w));
      while (alr < bid[w]) {
        pp = s.begin();
        alr++;
        res += pp->first;
        s.erase(pp);
      }
    }
    printf("%lld\n", res);
  }
  return 0;
}

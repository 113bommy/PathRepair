#include <bits/stdc++.h>
using namespace std;
list<int> e[200010];
list<int> f[200010];
list<int>::iterator sit;
list<int>::iterator tit;
long long ans;
struct node {
  int a;
  int b;
  long long c;
};
node rr[200010];
int main() {
  int n, m, q, x, y;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d %d", &x, &y);
    if (x < y) {
      swap(x, y);
    }
    e[x].push_back(y);
    f[y].push_back(x);
    rr[y].a++;
    rr[x].b++;
  }
  for (int i = 1; i <= n; i++) rr[i].c = i;
  for (int i = 1; i <= n; i++) {
    for (sit = e[i].begin(); sit != e[i].end(); sit++) {
      int id = *sit;
      ans += rr[id].b;
    }
  }
  printf("%lld\n", ans);
  scanf("%d", &q);
  for (int i = 1; i <= q; i++) {
    scanf("%d", &x);
    rr[x].c = n + i;
    long long s1 = 0;
    for (sit = f[x].begin(); sit != f[x].end();) {
      int id = *sit;
      if (rr[id].c < rr[x].c) {
        s1++;
        rr[id].b--;
        ans = ans - rr[id].a + rr[id].b;
        rr[id].a++;
        tit = sit;
        tit++;
        f[x].erase(sit);
        sit = tit;
        f[id].push_back(x);
      } else
        sit++;
    }
    ans = ans + (rr[x].a - s1) * (rr[x].b + s1) - (1LL * rr[x].a * rr[x].b);
    rr[x].a -= s1;
    rr[x].b += s1;
    printf("%lld\n", ans);
  }
  return 0;
}

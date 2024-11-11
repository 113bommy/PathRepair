#include <bits/stdc++.h>
#pragma warning(disable : 4786)
using namespace std;
int main() {
  int i, j, k, tests, cs = 0, n;
  cin >> n;
  queue<pair<int, int> > Q;
  int tot = 0, sz = 0;
  int ans = 0;
  for (i = 0; i < n; i++) {
    int t, c;
    scanf("%d%d", &t, &c);
    while (!Q.empty()) {
      pair<int, int> now = Q.front();
      int tt = now.first;
      int cc = now.second;
      if (tot + cc <= t) {
        Q.pop();
        tot += cc;
        sz -= cc;
      } else {
        int x = t - tot;
        sz -= x;
        now.second -= x;
        break;
      }
    }
    Q.push(make_pair(t, c));
    sz += c;
    ans = ((ans) > (sz) ? (ans) : (sz));
    tot = t;
  }
  tot += sz;
  printf("%d %d\n", tot, ans);
  return 0;
}

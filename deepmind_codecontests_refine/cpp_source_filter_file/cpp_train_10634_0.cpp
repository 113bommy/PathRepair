#include <bits/stdc++.h>
using namespace std;
const int inf = 1e18 + 7;
int ind[10000007][2];
int xdd[10000007];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long xd = inf, xd2, iks, de;
  pair<int, int> res;
  int n, a, mx = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a;
    mx = max(mx, a);
    if (!ind[a][0])
      ind[a][0] = i;
    else if (!ind[a][1])
      ind[a][1] = i;
    else
      continue;
    xdd[a]++;
  }
  for (int i = 1; i <= mx; i++) {
    iks = de = inf;
    for (int j = i; j <= mx; j += i) {
      if (de != inf) break;
      if (xdd[j] > 1) {
        if (iks == inf) iks = j;
        if (de == inf) de = j;
      } else if (xdd[j]) {
        if (iks == inf)
          iks = j;
        else if (de == inf)
          de = j;
      }
    }
    if (de == inf) continue;
    xd2 = iks * de / i;
    if (xd2 < xd) {
      xd = xd2;
      res = {ind[iks][0], iks == de ? ind[de][1] : ind[de][0]};
    }
  }
  if (res.first > res.second) swap(res.first, res.second);
  cout << res.first << ' ' << res.second << '\n';
  return 0;
}

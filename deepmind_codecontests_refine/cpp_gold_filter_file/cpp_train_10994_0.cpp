#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
map<int, int> mp, sg;
int dfs(int sta) {
  if (sta == 1) return 0;
  if (sg[sta]) return sg[sta];
  int bound, i;
  for (i = 1; i < 30; i++) {
    if (sta & (1 << i)) bound = i;
  }
  int vis = 0;
  for (i = 1; i <= bound; i++) {
    int tmp = (sta >> i) | (sta & ((1 << i) - 1));
    vis |= 1 << dfs(tmp);
  }
  int res = 0;
  for (i = 30; i >= 0; i--) {
    if ((~vis) & (1 << i)) res = i;
  }
  return sg[sta] = res;
}
int main() {
  int n, i, j, x;
  cin >> n;
  for (i = 0; i < n; i++) {
    scanf("%d", &x);
    for (j = 2; j * j <= x; j++) {
      if (x % j == 0) {
        int cnt = 0;
        while (x % j == 0) {
          x /= j;
          cnt++;
        }
        int v;
        if (!mp[j])
          v = 0;
        else
          v = mp[j];
        v |= 1 << cnt;
        mp[j] = v;
      }
    }
    if (x > 1) {
      int v;
      if (!mp[x])
        v = 0;
      else
        v = mp[x];
      v |= 1 << 1;
      mp[x] = v;
    }
  }
  int ans = 0;
  map<int, int>::iterator it;
  for (it = mp.begin(); it != mp.end(); it++) {
    ans ^= dfs(it->second);
  }
  if (ans)
    printf("Mojtaba");
  else
    printf("Arpa");
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int n, m, k;
bool debug = false;
int h, q, v, e;
char s[7];
map<int, double> mp;
double dfs(int i, double ss) {
  if (ss >= mp[i]) return ss;
  int l = i << 1, r = l + 1;
  return 0.5 *
         (dfs(l, max(ss, mp[i] - mp[l])) + dfs(r, max(ss, mp[i] - mp[r])));
}
int main() {
  scanf("%d%d", &h, &q);
  while (q--) {
    scanf("%s", s);
    if (s[0] == 'a') {
      scanf("%d%d", &v, &e);
      while (v >= 1) {
        mp[v] += e;
        v >>= 1;
      }
    } else {
      printf("%.8lf", dfs(1, 0));
    }
  }
  return 0;
}

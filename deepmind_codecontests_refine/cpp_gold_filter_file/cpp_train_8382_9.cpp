#include <bits/stdc++.h>
using namespace std;
int n, m, num[300005], ind[300005], a, b, check[300005], nxt;
vector<int> s[300005], e[300005];
pair<int, int> foe[300005];
long long ans;
int main() {
  scanf("%d%d", &n, &m);
  for (int l = 0; l < n; l++) scanf("%d", num + l), ind[num[l]] = l;
  for (int l = 0; l < m; l++) {
    scanf("%d%d", &a, &b);
    if (ind[a] > ind[b]) swap(a, b);
    s[a].push_back(l);
    e[b].push_back(l);
    foe[l] = {a, b};
  }
  int i = 0, j = 0;
  while (i < n && j < n) {
    if (s[num[j]].size()) {
      for (int k = 0; k < s[num[j]].size(); k++) check[s[num[j]][k]]++;
    }
    if (e[num[j]].size()) {
      bool c = false;
      int tmp;
      nxt = 0;
      for (int k = 0; k < e[num[j]].size(); k++) {
        tmp = e[num[j]][k];
        if (check[tmp]) {
          check[tmp] = 0;
          c = true;
          nxt = max(nxt, ind[foe[tmp].first]);
        }
      }
      if (c) {
        for (; i <= nxt; i++) {
          ans += j - i;
          for (int k = 0; k < s[num[i]].size(); k++) check[s[num[i]][k]] = 0;
        }
      }
    }
    j++;
  }
  while (i < j) {
    ans += j - i;
    i++;
  }
  printf("%lld", ans);
  return 0;
}

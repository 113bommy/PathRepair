#include <bits/stdc++.h>
const int N = 305;
using namespace std;
map<int, int> mp;
int l[N], c[N];
vector<pair<int, int> > f[N];
int gcd(int a, int b) {
  int q = a % b;
  while (q != 0) {
    a = b;
    b = q;
    q = a % b;
  }
  return b;
}
int main() {
  int n;
  scanf("%d", &n);
  int i, j, k, t;
  for (i = 0; i < n; i++) scanf("%d", &l[i]);
  for (i = 0; i < n; i++) scanf("%d", &c[i]);
  f[0].push_back(make_pair(l[0], c[0]));
  int ans = 100000000;
  if (l[0] == 1) ans = c[i];
  map<int, int>::iterator it;
  for (i = 1; i < n; i++) {
    mp.clear();
    mp[l[i]] = c[i];
    for (j = 0; j < i; j++)
      for (k = 0; k < f[j].size(); k++) {
        t = gcd(l[i], f[j][k].first);
        if (mp.find(t) == mp.end() || mp[t] > c[i] + f[j][k].second)
          mp[t] = c[i] + f[j][k].second;
      }
    for (it = mp.begin(); it != mp.end(); it++) {
      f[i].push_back(make_pair(it->first, it->second));
      if (it->first == 1) ans = min(ans, it->second);
    }
  }
  if (ans == 100000000)
    printf("-1");
  else
    printf("%d", ans);
  return 0;
}

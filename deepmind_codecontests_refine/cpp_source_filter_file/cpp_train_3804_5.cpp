#include <bits/stdc++.h>
using namespace std;
unordered_map<int, int> mp;
vector<tuple<int, int, int> > v;
vector<int> fw[1000005];
vector<int>::iterator it;
vector<pair<int, int> > keb[1000005];
int yo[1000005];
void add(int x, int op, int val) {
  while (x < fw[op].size()) {
    fw[op][x] += val;
    x += x & -x;
  }
}
int sum(int x, int op) {
  int ss = 0;
  while (x > 0) {
    ss += fw[op][x];
    x -= x & -x;
  }
  return ss;
}
int main() {
  int n, a, t, x, i, idx = 0, dum, j;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d%d%d", &a, &t, &x);
    v.emplace_back(t, a, x);
    if (mp[x] == 0) mp[x] = idx++;
    fw[mp[x]].push_back(0);
    keb[mp[x]].emplace_back(t, i);
  }
  for (i = 0; i < idx; i++) {
    fw[i].push_back(0);
    sort(keb[i].begin(), keb[i].end());
    for (j = 0; j < keb[i].size(); j++)
      yo[keb[i][j].second] = j > 0 && keb[i][j].first == keb[i][j - 1].first
                                 ? yo[keb[i][j - 1].second]
                                 : j + 1;
  }
  for (i = 0; i < v.size(); i++) {
    tie(t, a, x) = v[i];
    dum = mp[x];
    if (a == 1)
      add(yo[i], dum, 1);
    else if (a == 2)
      add(yo[i], dum, -1);
    else
      printf("%d\n", sum(yo[i], dum));
  }
}

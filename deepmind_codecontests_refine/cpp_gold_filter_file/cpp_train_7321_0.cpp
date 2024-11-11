#include <bits/stdc++.h>
using namespace std;
const int N = 100000 + 5, M = 100000 + 5;
int n, m;
map<int, int> h;
map<int, int> id1;
map<int, int> fthis, fnext;
vector<pair<int, int> > solution;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    int ci, si;
    scanf("%d%d", &ci, &si);
    h[si] = ci;
    id1[si] = i;
  }
  scanf("%d", &m);
  for (int i = 1; i <= m; ++i) {
    int di, li;
    scanf("%d%d", &di, &li);
    int &f1 = fthis[li], &f2 = fnext[li];
    if (h.count(li) && di >= h[li] && (!f1 || f1 == f2)) f1 = i;
    if (h.count(li + 1) && di >= h[li + 1] && (!f2 || f1 == f2)) f2 = i;
  }
  long long ans = 0;
  set<int> processed;
  for (map<int, int>::iterator it = h.begin(); it != h.end(); ++it) {
    if (processed.count(it->first)) continue;
    int custcnt = 0, shoescnt = 1;
    int twochoice = 0;
    long long totprice = it->second;
    int t = it->first;
    int minprice = it->second, minid = t;
    if (fnext[t - 1]) ++custcnt;
    while (1) {
      if (!fthis[t]) break;
      ++custcnt;
      if (!fnext[t]) break;
      if (fthis[t] != fnext[t]) twochoice = t;
      ++t;
      ++shoescnt;
      processed.insert(t);
      if (h[t] < minprice) {
        minprice = h[t];
        minid = t;
      }
      totprice += h[t];
    }
    if (twochoice || custcnt >= shoescnt) {
      ans += totprice;
      if (custcnt >= shoescnt) {
        if (fnext[it->first - 1])
          for (int i = it->first; i <= t; ++i)
            solution.push_back(make_pair(fnext[i - 1], id1[i]));
        else
          for (int i = it->first; i <= t; ++i)
            solution.push_back(make_pair(fthis[i], id1[i]));
      } else {
        for (int i = it->first; i <= twochoice; ++i)
          solution.push_back(make_pair(fthis[i], id1[i]));
        for (int i = twochoice + 1; i <= t; ++i)
          solution.push_back(make_pair(fnext[i - 1], id1[i]));
      }
    } else {
      ans += totprice - minprice;
      for (int i = it->first; i < minid; ++i)
        solution.push_back(make_pair(fthis[i], id1[i]));
      for (int i = minid + 1; i <= t; ++i)
        solution.push_back(make_pair(fnext[i - 1], id1[i]));
    }
  }
  printf("%I64d\n", ans);
  printf("%d\n", (int)solution.size());
  for (int i = 0; i < (int)solution.size(); ++i)
    printf("%d %d\n", solution[i].first, solution[i].second);
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int N = 100000;
int n, m, ck[N];
pair<pair<int, int>, int> act[N];
pair<pair<int, int>, int> part[N];
int sol[N];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &part[i].first.second, &part[i].first.first);
    part[i].second = i;
  }
  scanf("%d", &m);
  for (int i = 0; i < m; ++i) {
    scanf("%d%d%d", &act[i].first.second, &act[i].first.first, &ck[i]);
    act[i].second = i;
  }
  sort(part, part + m);
  sort(act, act + m);
  int j = 0;
  set<pair<int, int> > q;
  set<pair<int, int> >::iterator it;
  for (int i = 0; i < m; ++i) {
    while (j < n && part[j].first.first <= act[i].first.first) {
      q.insert(make_pair(part[j].first.second, part[j].second));
      ++j;
    }
    int actIdx = act[i].second;
    while (!q.empty() && ck[actIdx] > 0) {
      it = q.lower_bound(make_pair(act[i].first.second, -1));
      if (it != q.end()) {
        sol[it->second] = actIdx;
        --ck[actIdx];
        q.erase(it);
      } else
        break;
    }
  }
  if (!q.empty() || j != n)
    puts("NO");
  else {
    puts("YES");
    for (int i = 0; i < n; ++i) printf("%d ", sol[i] + 1);
  }
  return 0;
}

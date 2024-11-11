#include <bits/stdc++.h>
using namespace std;
const int MOD(1000000007);
const int INF((1 << 30) - 1);
const int MAXN((1 << 16) + 5);
set<pair<int, int> > s;
set<pair<int, int> >::iterator it;
int deg[MAXN], xsum[MAXN];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int d, x;
    scanf("%d%d", &d, &x);
    s.insert(pair<int, int>(d, i));
    deg[i] = d;
    xsum[i] = x;
  }
  vector<pair<int, int> > edge;
  while (!s.empty()) {
    int d = s.begin()->first, i = s.begin()->second, j;
    s.erase(s.begin());
    if (d == 0) continue;
    edge.push_back(pair<int, int>(i, xsum[i]));
    j = xsum[i];
    s.erase(s.find(pair<int, int>(deg[j], j)));
    deg[j]--;
    xsum[j] ^= i;
    s.insert(pair<int, int>(deg[j], j));
  }
  printf("%d\n", edge.size());
  for (int i = 0; i < edge.size(); i++)
    printf("%d %d\n", edge[i].first, edge[i].second);
}

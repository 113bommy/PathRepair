#include <bits/stdc++.h>
using namespace std;
long long ara[300005][2];
vector<pair<long long, int> > v;
long long csum[300005][2];
long long ans[300005];
vector<int> g[300005];
int main() {
  int n, m;
  cin >> n >> m;
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    long long x;
    long long y;
    scanf("%I64d %I64d", &x, &y);
    ara[i][0] = x;
    ara[i][1] = y;
    v.push_back(make_pair(x - y, i));
  }
  for (int i = 0; i < m; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    g[y - 1].push_back(x - 1);
    g[x - 1].push_back(y - 1);
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < v.size(); i++) {
    csum[i + 1][0] = csum[i][0] + ara[v[i].second][0];
    csum[i + 1][1] = csum[i][1] + ara[v[i].second][1];
    sum += ara[v[i].second][1];
  }
  for (int i = 0; i < v.size(); i++) {
    ans[v[i].second] += csum[i][0] + ara[v[i].second][1] * (long long)i;
    ans[v[i].second] +=
        sum - csum[i + 1][1] + ara[v[i].second][0] * (long long)(n - i - 1);
    for (int j = 0; j < g[v[i].second].size(); j++) {
      long long val;
      if (ara[g[v[i].second][j]][0] + ara[v[i].second][1] <=
          ara[g[v[i].second][j]][1] + ara[v[i].second][0]) {
        ans[v[i].second] -= ara[g[v[i].second][j]][0] + ara[v[i].second][1];
      } else {
        ans[v[i].second] -= ara[g[v[i].second][j]][1] + ara[v[i].second][0];
      }
    }
  }
  for (int i = 0; i < n; i++) {
    printf("%I64d ", ans[i]);
  }
  printf("\n");
  return 0;
}

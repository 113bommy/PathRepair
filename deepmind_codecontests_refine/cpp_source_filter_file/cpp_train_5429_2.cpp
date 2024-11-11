#include <bits/stdc++.h>
using namespace std;
int n;
vector<pair<long long int, long long int> > v;
int od(pair<long long int, long long int> pt) {
  if (pt.second >= 0 && pt.first >= 0) return 1;
  if (pt.second >= 0) return 2;
  if (pt.first <= 0) {
    return 3;
  }
  return 4;
}
vector<pair<long long int, long long int> > dw;
long long int cr(pair<long long int, long long int> a,
                 pair<long long int, long long int> b) {
  return a.first * b.second - a.second * b.first;
}
vector<pair<pair<long long int, long long int>, int> > up;
vector<pair<pair<long long int, long long int>, int> > up2;
vector<pair<pair<long long int, long long int>,
            pair<long long int, long long int> > >
    vv;
bool cmp(pair<long long int, long long int> a,
         pair<long long int, long long int> b) {
  return a.first * b.second - a.second * b.first > 0LL;
}
bool cmp2(pair<pair<long long int, long long int>, int> a,
          pair<pair<long long int, long long int>, int> b) {
  return cmp(a.first, b.first);
}
int dp[312][312][5];
inline long long int dfs(int a, int b, int c) {}
vector<pair<double, pair<int, int> > > V;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    v.push_back(make_pair(a, b));
  }
  sort(v.begin(), v.end(), cmp);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      V.push_back({atan2((double)(v[j].second - v[i].second),
                         (double)(v[j].first - v[i].first)),
                   make_pair(i, j)});
      if (V.back().first < 0.0) {
        V.back().first += 3.14159263 * 2.0;
      }
    }
  }
  sort(V.begin(), V.end());
  for (int i = 0; i < n; i++) dp[i][i][0] = 1;
  for (int i = 0; i < V.size(); i++) {
    int from = V[i].second.first;
    int to = V[i].second.second;
    for (int F = 0; F < n; F++) {
      for (int k = 0; k < 5; k++) {
        dp[F][to][k + 1] += dp[F][from][k];
      }
    }
  }
  long long int ans = 0;
  for (int i = 0; i < n; i++) {
    ans += dp[i][i][5];
  }
  printf("%lld\n", ans);
  return 0;
}

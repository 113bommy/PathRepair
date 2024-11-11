#include <bits/stdc++.h>
using namespace std;
int n, m, d;
bool cmp(pair<long long, long long> A, pair<long long, long long> B) {
  if (A.first == B.first) return A.second < B.second;
  return A.first > B.first;
}
void solve() {
  scanf("%d%d%d", &n, &m, &d);
  vector<pair<long long, long long> > Q1, Q2;
  for (int i = 0; i < n; ++i) {
    int c, w;
    scanf("%d%d", &c, &w);
    Q1.push_back({c, w});
  }
  for (int i = 0; i < m; ++i) {
    int c, w;
    scanf("%d%d", &c, &w);
    Q2.push_back({c, w});
  }
  sort(Q1.begin(), Q1.end(), cmp);
  sort(Q2.begin(), Q2.end(), cmp);
  for (int i = 1; i < n; ++i) {
    Q1[i].first += Q1[i - 1].first;
    Q1[i].second += Q1[i - 1].second;
  }
  for (int i = 1; i < m; ++i) {
    Q2[i].first += Q2[i - 1].first;
    Q2[i].second += Q2[i - 1].second;
  }
  long long ans = 0;
  int p = m - 1;
  for (int i = 0; i < n; ++i) {
    while (p >= 0 && Q1[i].second + Q2[p].second > d) p--;
    if (p >= 0 && Q1[i].second + Q2[p].second <= d)
      ans = max(ans, Q1[i].first + Q2[p].first);
  }
  printf("%lld", ans);
}
int main() {
  solve();
  return 0;
}

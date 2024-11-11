#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const int maxn = 3e5 + 10;
int n, m;
long long sum[maxn];
vector<int> pos, neg;
vector<pair<int, int> > ans;
vector<long long> s;
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i) {
    int u, v, d;
    scanf("%d%d%d", &u, &v, &d);
    sum[u] += d;
    sum[v] -= d;
  }
  for (int i = 1; i <= n; ++i) {
    if (sum[i] > 0) pos.push_back(i);
    if (sum[i] < 0) neg.push_back(i);
  }
  int i = 0, j = 0;
  while (i < pos.size() && j < neg.size()) {
    if (sum[pos[i]] + sum[neg[j]] == 0) {
      ans.push_back(make_pair(pos[i], neg[j]));
      s.push_back(sum[pos[i]]);
      ++i;
      ++j;
    } else if (sum[pos[i]] + sum[neg[j]] < 0) {
      sum[neg[j]] += sum[pos[i]];
      ans.push_back(make_pair(pos[i], neg[j]));
      s.push_back(sum[pos[i]]);
      ++i;
    } else {
      sum[pos[i]] += sum[neg[j]];
      ans.push_back(make_pair(pos[i], neg[j]));
      s.push_back(-sum[neg[j]]);
      ++j;
    }
  }
  printf("%d\n", ans.size());
  for (int i = 0; i < ans.size(); ++i)
    printf("%d %d %I64d\n", ans[i].first, ans[i].second, s[i]);
  return 0;
}

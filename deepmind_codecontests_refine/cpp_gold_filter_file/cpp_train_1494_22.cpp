#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 200000 + 10;
vector<pair<int, int> > v;
vector<int> id;
int ptr[MAX_N];
vector<int> rd[MAX_N], dp[MAX_N];
int s[MAX_N];
inline int calc(int col, int l, int r) {
  return s[r] - s[l] - dp[col][id[r]] + dp[col][id[l]];
}
int main() {
  int N, M, K;
  scanf("%d%d%d", &N, &M, &K);
  v.push_back(make_pair(0, 0));
  for (int i = 0; i < N; i++) {
    int c;
    scanf("%d", &c);
    if (v.empty() || v.back().first != c)
      v.push_back(make_pair(c, 1));
    else
      v.back().second++;
  }
  N = v.size() - 1;
  id.push_back(-1);
  for (int i = 1; i <= N; i++) {
    s[i] = s[i - 1] + v[i].second;
    rd[v[i].first].push_back(i);
    dp[v[i].first].push_back(dp[v[i].first].empty()
                                 ? v[i].second
                                 : dp[v[i].first].back() + v[i].second);
    id.push_back((int)rd[v[i].first].size() - 1);
  }
  int ans = 0;
  for (int i = 1; i <= N; i++) {
    int c = v[i].first;
    while (ptr[c] < (int)rd[c].size() && calc(c, rd[c][ptr[c]], i) > K)
      ptr[c]++;
    ans = max(ans, s[i] - s[rd[c][ptr[c]] - 1] - calc(c, rd[c][ptr[c]], i));
  }
  printf("%d\n", ans);
  return 0;
}

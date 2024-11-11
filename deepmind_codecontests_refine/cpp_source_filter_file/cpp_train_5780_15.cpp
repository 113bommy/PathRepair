#include <bits/stdc++.h>
using namespace std;
const long long int N = 100005;
pair<pair<long long int, long long int>, long long int> edges[N];
pair<long long int, long long int> ans[N];
inline bool cmp(pair<pair<long long int, long long int>, long long int> a,
                pair<pair<long long int, long long int>, long long int> b) {
  if (a.first.first == b.first.first) return a.first.second > b.first.second;
  return a.first.first < b.first.first;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long int n, m;
  cin >> n >> m;
  for (long long int i = 0; i < m; i++) {
    long long int x, y;
    cin >> x >> y;
    edges[i] = {{x, y}, i};
  }
  sort(edges, edges + m, cmp);
  long long int ch1 = 0, ch2 = 0;
  for (long long int i = 0; i < m; i++) {
    if (ch2 > ((ch1 * (ch1 - 1)) / 2)) return cout << -1, 0;
    if (edges[i].first.second)
      ch1++;
    else
      ch2++;
  }
  long long int cnt = 0;
  vector<pair<long long int, long long int> > v;
  for (long long int i = 3; i <= ch1; i++) {
    if (cnt == ch2) break;
    for (long long int j = 2; j < i; j++) {
      if (cnt == ch2) break;
      v.push_back({j, i});
      cnt++;
    }
  }
  reverse(v.begin(), v.end());
  cnt = 2;
  for (long long int i = 0; i < m; i++) {
    if (edges[i].first.second)
      ans[edges[i].second] = {1, cnt}, cnt++;
    else
      ans[edges[i].second] = v.back(), v.pop_back();
  }
  for (long long int i = 0; i < m; i++)
    cout << ans[i].first << " " << ans[i].second << '\n';
}

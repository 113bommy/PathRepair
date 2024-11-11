#include <bits/stdc++.h>
using namespace std;
const long long int INF = 1e15;
const long long int MOD = 1e9 + 7;
bool compare(const pair<pair<long long int, long long int>, long long int>& a,
             const pair<pair<long long int, long long int>, long long int>& b) {
  long long int x = b.first.first - a.first.first;
  long long int y = b.first.second - a.first.second;
  if (x != y) {
    return x < y;
  }
  return a.second < b.second;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long int n, m;
  cin >> n >> m;
  vector<pair<pair<long long int, long long int>, long long int>> s(n);
  vector<pair<long long int, long long int>> ps(n + 1);
  for (long long int i = 0; i < (n); ++i) {
    long long int x, y;
    cin >> x >> y;
    s[i] = {{x, y}, i + 1};
    ps[i + 1] = {x, y};
  }
  vector<pair<long long int, long long int>> nopair(m);
  for (long long int i = 0; i < (m); ++i) {
    long long int u, v;
    cin >> u >> v;
    nopair[i] = {u, v};
  }
  sort(s.begin(), s.end(), compare);
  vector<long long int> fst(n + 1), snd(n + 1);
  for (long long int i = 0; i < (n); ++i) {
    fst[i + 1] = fst[i] + s[i].first.first;
    snd[i + 1] = snd[i] + s[i].first.second;
  }
  vector<long long int> ans(n + 1);
  for (long long int i = 0; i < (n); ++i) {
    long long int id = s[i].second;
    if (id == 0) {
      continue;
    }
    ans[id] = snd[i] + fst[n] - fst[i + 1];
    ans[id] += ps[id].first * i + ps[id].second * (n - i - 1);
  }
  for (long long int i = 0; i < (m); ++i) {
    long long int u = nopair[i].first;
    long long int v = nopair[i].second;
    long long int score =
        min(ps[u].first + ps[v].second, ps[u].second + ps[v].first);
    ans[u] -= score;
    ans[v] -= score;
  }
  for (long long int i = 1; i < n; i++) {
    cout << ans[i] << " ";
  }
  cout << ans[n] << endl;
  return 0;
}

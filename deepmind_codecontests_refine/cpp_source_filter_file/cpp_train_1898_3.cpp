#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 2e5 + 10;
vector<int> gr[MAXN];
bool mark[MAXN];
vector<bool> used(MAXN);
void BFS(int v, vector<int> &d) {
  used.assign(MAXN, 0);
  queue<int> q;
  d[v] = 0;
  used[v] = true;
  q.push(v);
  while (!q.empty()) {
    int st = q.front();
    q.pop();
    for (int i = 0; i < gr[st].size(); ++i) {
      int to = gr[st][i];
      if (!used[to]) {
        used[to] = true;
        d[to] = d[st] + 1;
        q.push(to);
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < k; ++i) {
    int a;
    cin >> a;
    mark[a] = true;
  }
  bool flag = false;
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    if (mark[a] && mark[b]) {
      flag = true;
    }
    gr[a].push_back(b);
    gr[b].push_back(a);
  }
  vector<int> d1(n + 1), d2(n + 1);
  BFS(1, d1);
  BFS(n, d2);
  vector<pair<int, int>> kek;
  int ans = d1[n];
  for (int i = 1; i <= n; ++i) {
    if (mark[i]) {
      kek.push_back({d1[i] - d2[i], i});
    }
  }
  sort(kek.begin(), kek.end());
  int suf[k];
  for (int i = k - 1; i >= 0; --i) {
    if (i == k - 1) {
      suf[i] = d2[kek[i].second];
    } else {
      suf[i] = max(kek[i].second, suf[i + 1]);
    }
  }
  int mx = 0;
  for (int i = 0; i < k - 1; ++i) {
    int v = kek[i].second;
    mx = max(mx, d1[v] + suf[i + 1] + 1);
  }
  ans = min(ans, mx);
  cout << ans;
  return 0;
}

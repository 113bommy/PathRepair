#include <bits/stdc++.h>
using namespace std;
void pr(vector<long long> &a) {
  for (auto val : a) cout << val << " ";
  cout << endl;
}
int main() {
  long long n, m;
  cin >> n >> m;
  vector<vector<long long> > v;
  long long a, b;
  for (int i = 1; i <= m; i++) {
    cin >> a >> b;
    v.push_back({a, 1 - b, i});
  }
  sort(v.begin(), v.end());
  vector<vector<long long> > adj(n + 1);
  vector<long long> nextt(n + 1, 0);
  for (int i = 1; i <= n; i++) nextt[i] = i + 1;
  bool isValid = 1;
  long long vertices = 1;
  long long edgesCount = 0;
  long long maxEdges = 0;
  long long cur = 2;
  vector<vector<long long> > ans(m + 1);
  for (auto val : v) {
    if (val[1] == 1) {
      if (edgesCount >= maxEdges) {
        isValid = false;
        break;
      }
      while (nextt[cur] > vertices) {
        cur++;
        if (cur > vertices) cur = 1;
      }
      long long next = nextt[cur];
      adj[cur].push_back(next);
      adj[next].push_back(cur);
      ans[val[2]] = {cur, next};
      edgesCount++;
      nextt[cur]++;
    } else {
      vertices++;
      maxEdges += vertices - 1;
      adj[1].push_back(vertices);
      adj[vertices].push_back(1);
      ans[val[2]] = {1, vertices};
      edgesCount++;
    }
  }
  if (!isValid) {
    cout << -1;
    return 0;
  }
  for (auto val : ans) {
    if (val.size()) cout << val[0] << " " << val[1] << endl;
  }
}

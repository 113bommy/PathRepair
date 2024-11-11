#include <bits/stdc++.h>
using namespace std;
string nums[1005];
string tostr(int a) {
  ostringstream ss;
  ss << a;
  return ss.str();
}
deque<long long> deq;
vector<int> ans[200001];
vector<pair<int, int> > graph[200001];
int p[200001];
int cmax = 0;
void dfs(int v, int d) {
  int c = 0;
  for (int i = 0; i < graph[v].size(); i++) {
    if (c == d) c++;
    int k = graph[v][i].first;
    if (k == p[v]) {
      continue;
    }
    p[k] = v;
    ans[c].push_back(graph[v][i].second);
    dfs(k, c);
    cmax = max(c, cmax);
    c++;
  }
}
set<int> is;
int main() {
  int n, m;
  cin >> n >> m;
  int k;
  for (int i = 0; i < n; i++) {
    cin >> k;
    is.insert(k);
  }
  vector<int> ans;
  for (int kek = 1; kek <= 100000; kek++) {
    if (m >= kek && is.find(kek) == is.end()) {
      ans.push_back(kek);
      m -= kek;
    }
  }
  cout << ans.size() << "\n";
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
  return 0;
}

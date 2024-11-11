#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 7;
int n, d[maxn];
map<pair<int, int>, set<int> > H;
map<pair<int, int>, set<int> > H2;
vector<int> E[maxn];
vector<int> ans;
void dfs(int x, int y, int id) {
  int a = min(x, y);
  int b = max(x, y);
  ans.push_back(x);
  for (auto xx : H2[make_pair(a, b)]) {
    if (xx == id) continue;
    int mid = xx;
    int z = E[mid][0] + E[mid][1] + E[mid][2] - a - b;
    ans.pop_back();
    dfs(x, z, mid);
    ans.pop_back();
    dfs(z, y, mid);
    ans.pop_back();
  }
  ans.push_back(y);
}
void solve() {
  H.clear();
  H2.clear();
  ans.clear();
  cin >> n;
  for (int i = 0; i < n - 2; i++) {
    E[i].clear();
    for (int j = 0; j < 3; j++) {
      int x;
      cin >> x;
      E[i].push_back(x);
    }
    d[i] = 0;
    sort(E[i].begin(), E[i].end());
    H[make_pair(E[i][0], E[i][1])].insert(i);
    H[make_pair(E[i][0], E[i][2])].insert(i);
    H[make_pair(E[i][1], E[i][2])].insert(i);
    H2[make_pair(E[i][0], E[i][1])].insert(i);
    H2[make_pair(E[i][0], E[i][2])].insert(i);
    H2[make_pair(E[i][1], E[i][2])].insert(i);
  }
  for (auto x : H) {
    set<int> p = x.second;
    pair<int, int> GG = x.first;
    for (auto t : p) {
      d[t] += p.size() - 1;
    }
  }
  set<pair<int, int> > Q;
  for (int i = 0; i < n - 2; i++) {
    Q.insert(make_pair(d[i], i));
  }
  vector<int> order;
  while (!Q.empty()) {
    pair<int, int> nowP = *Q.begin();
    int now = nowP.second;
    Q.erase(Q.begin());
    order.push_back(now);
    H[make_pair(E[now][0], E[now][1])].erase(now);
    H[make_pair(E[now][0], E[now][2])].erase(now);
    H[make_pair(E[now][1], E[now][2])].erase(now);
    for (auto x : H[make_pair(E[now][0], E[now][1])]) {
      Q.erase(make_pair(d[x], x));
      d[x]--;
      Q.insert(make_pair(d[x], x));
    }
    for (auto x : H[make_pair(E[now][0], E[now][2])]) {
      Q.erase(make_pair(d[x], x));
      d[x]--;
      Q.insert(make_pair(d[x], x));
    }
    for (auto x : H[make_pair(E[now][1], E[now][2])]) {
      Q.erase(make_pair(d[x], x));
      d[x]--;
      Q.insert(make_pair(d[x], x));
    }
  }
  if (H2[make_pair(E[order[0]][0], E[order[0]][1])].size() > 1) {
    dfs(E[order[0]][0], E[order[0]][1], order[0]);
    ans.push_back(E[order[0]][2]);
  }
  if (H2[make_pair(E[order[0]][0], E[order[0]][2])].size() > 1) {
    dfs(E[order[0]][0], E[order[0]][2], order[0]);
    ans.push_back(E[order[0]][1]);
  }
  if (H2[make_pair(E[order[0]][1], E[order[0]][2])].size() > 1) {
    dfs(E[order[0]][1], E[order[0]][2], order[0]);
    ans.push_back(E[order[0]][0]);
  }
  if (n == 3) {
    cout << "1 2 3" << endl;
  } else {
    for (int i = 0; i < ans.size(); i++) {
      cout << ans[i] << " ";
    }
    cout << endl;
  }
  for (int i = 0; i < order.size(); i++) cout << order[i] + 1 << " ";
  cout << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
}

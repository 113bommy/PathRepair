#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const int mod = 1000000007;
const int inf = 0x3f3f3f3f;
const int maxn = 200005;
int n, m;
int res[maxn];
int Nu[maxn], Nv[maxn], t[maxn];
int pos[maxn];
vector<int> adj[maxn];
vector<int> sorted;
bool topoSort(int n) {
  sorted.clear();
  queue<int> q;
  vector<int> indegree(n + 2, 0);
  for (int i = 1; i <= n; i++) {
    for (auto it : adj[i]) {
      indegree[it]++;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (!indegree[i]) {
      q.push(i);
    }
  }
  int indx = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    sorted.push_back(u);
    indx++;
    pos[u] = indx;
    for (auto v : adj[u]) {
      indegree[v]--;
      if (!indegree[v]) {
        q.push(v);
      }
    }
  }
  return (sorted.size() == n);
}
void task() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    adj[i].clear();
  }
  for (int i = 1; i <= m; i++) {
    cin >> t[i] >> Nu[i] >> Nv[i];
    if (t[i] == 1) adj[Nu[i]].push_back(Nv[i]);
  }
  bool chek = topoSort(n);
  if (!chek) {
    cout << "NO"
         << "\n";
    return;
  }
  cout << "YES"
       << "\n";
  for (int i = 1; i <= m; i++) {
    if (t[i] == 1)
      cout << Nu[i] << ' ' << Nv[i] << "\n";
    else {
      if (pos[Nu[i]] > pos[Nv[i]])
        cout << Nu[i] << ' ' << Nv[i] << "\n";
      else
        cout << Nu[i] << ' ' << Nv[i] << "\n";
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T = 1;
  cin >> T;
  while (T--) {
    task();
  }
  return 0;
}

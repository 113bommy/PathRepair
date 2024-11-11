#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int a[N];
int r[N];
int res[N];
vector<pair<int, int> > adj[N];
int n;
vector<pair<int, long long> > path;
int find(int u) {
  if (u == 1) return 0;
  int low = 0;
  int high = path.size() - 1;
  int ans = -1;
  long long T = path[high].second;
  while (low <= high) {
    int mid = (low + high) / 2;
    long long temp = T - path[mid].second;
    if (temp > a[u]) {
      ans = mid;
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return path[ans].first;
}
void dfs(int u, int p, long long val) {
  path.push_back(make_pair(u, val));
  r[u] = find(u);
  for (auto x : adj[u]) {
    if (x.first != p) {
      dfs(x.first, u, val + x.second);
    }
  }
  path.pop_back();
}
void solve(int u, int p) {
  for (auto x : adj[u]) {
    if (x.first != p) {
      solve(x.first, u);
      res[u] += res[x.first];
    }
  }
}
int main() {
  cin >> n;
  for (int i = 1; i < n + 1; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 2; i < n + 1; i++) {
    int p, w;
    scanf("%d", &p);
    scanf("%d", &w);
    adj[i].push_back(make_pair(p, w));
    adj[p].push_back(make_pair(i, w));
  }
  path.push_back(make_pair(0, -1));
  dfs(1, -1, 0LL);
  for (int i = 1; i <= n; i++) {
    res[i]++;
    res[r[i]]--;
  }
  solve(1, -1);
  for (int i = 1; i < n + 1; i++) {
    printf("%d ", res[i] - 1);
  }
}

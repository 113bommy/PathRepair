#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> edges[300001];
int col[300001];
vector<int> g[300001];
int proc[300001];
vector<int> to_add;
int used[300001];
bool less_vectors(const vector<int>& a, const vector<int>& b) {
  return a.size() > b.size();
}
void dfs(int i) {
  proc[i] = 1;
  for (int k : edges[i]) {
    if (!col[k]) {
      to_add.push_back(k);
    } else {
      used[col[k]] = 1;
    }
  }
  int ans = 1;
  for (int k : to_add) {
    while (used[ans]) {
      ans++;
    }
    col[k] = ans;
    used[ans++] = 1;
  }
  to_add.clear();
  for (int k : edges[i]) used[col[k]] = 0;
  for (int a : g[i]) {
    if (!proc[a]) dfs(a);
  }
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int size;
    cin >> size;
    edges[i].resize(size);
    for (int k = 0; k < size; k++) {
      cin >> edges[i][k];
    }
  }
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    g[a - 1].push_back(b - 1);
    g[b - 1].push_back(a - 1);
  }
  dfs(0);
  int total = 1;
  for (int i = 1; i < m + 1; i++) {
    total = max(total, col[i]);
  }
  cout << total << endl;
  for (int i = 1; i < m + 1; i++) {
    cout << (i - 1 ? " " : "") << (col[i] ? col[i] : 1);
  }
  cout << endl;
  return 0;
}

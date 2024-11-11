#include <bits/stdc++.h>
using namespace std;
vector<int> vec[100005];
long long stat[2], vis[100005];
void dfs(int node, int st) {
  stat[st]++;
  vis[node] = 1;
  for (int i = 0; i < vec[node].size(); i++) {
    int nxt = vec[node][i];
    if (!vis[nxt]) dfs(nxt, !st);
  }
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    vec[a].push_back(b);
    vec[b].push_back(a);
  }
  dfs(1, 0);
  cout << stat[0] * stat[1] - n + 1 << "\n";
}

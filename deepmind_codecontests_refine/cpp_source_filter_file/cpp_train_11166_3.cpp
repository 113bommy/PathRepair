#include <bits/stdc++.h>
using namespace std;
const long long M = 1e9 + 7;
const int N = 1e6 + 7;
vector<int> adj[20];
bool visited[N];
void dfs(int x) {
  visited[x] = true;
  for (auto it : adj[x])
    if (!visited[it]) dfs(it);
}
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    for (long long i = 0; i < (int)20; i++) adj[i].clear();
    memset(visited, 0, sizeof(visited));
    int len;
    scanf("%d", &len);
    string s, t;
    bool flag = true;
    cin >> s >> t;
    for (long long i = 0; i < (int)len; i++) {
      if (s[i] > t[i]) {
        flag = false;
        break;
      }
      if (s[i] != t[i]) {
        adj[s[i] - 'a'].push_back(t[i] - 'a');
        adj[t[i] - 'a'].push_back(s[i] - 'a');
      }
    }
    int ans = 20;
    for (long long i = 0; i < (int)20; i++) {
      if (!visited[i]) {
        dfs(i);
        ans--;
      }
    }
    if (flag)
      printf("%lld\n", ans);
    else {
      printf("-1\n");
    }
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int down[N], sz[N], up[N], n;
vector<pair<int, bool> > adj[N];
void dfs(int s, int p) {
  sz[s] = 1;
  for (auto it : adj[s]) {
    if (it.first != p) {
      dfs(it.first, s);
      sz[s] += sz[it.first];
      if (it.second)
        down[s] += sz[it.first];
      else
        down[s] += down[it.first];
    }
  }
}
void dfs2(int s, int p) {
  for (auto it : adj[s]) {
    if (it.first != p) {
      if (it.second)
        up[it.first] = n - sz[it.first];
      else
        up[it.first] = down[s] - down[it.first] + up[s];
      dfs2(it.first, s);
    }
  }
}
int main() {
  int i;
  scanf("%d", &n);
  for (i = 0; i < n - 1; i++) {
    int a, b, c, te;
    bool flag = true;
    scanf("%d%d%d", &a, &b, &c);
    while (c > 0) {
      if (c % 10 == 4 || c % 10 == 7)
        ;
      else
        flag = false;
      c /= 10;
    }
    adj[a - 1].push_back(make_pair(b - 1, flag));
    adj[b - 1].push_back(make_pair(a - 1, flag));
  }
  long long ans = 0;
  dfs(0, -1);
  dfs2(0, -1);
  for (i = 0; i < n; i++) {
    long long temp = up[i] + down[i];
    ans += temp * (temp - 1);
  }
  cout << ans;
}

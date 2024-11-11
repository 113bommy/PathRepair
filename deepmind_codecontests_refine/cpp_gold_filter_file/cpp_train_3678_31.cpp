#include <bits/stdc++.h>
using namespace std;
const int inft = 1000000009;
const int MAXN = 1000006;
vector<int> V[MAXN];
bool vis[MAXN];
int DFS(int a) {
  int ans = 1;
  vis[a] = 1;
  for (typeof((V[a]).begin()) it = (V[a]).begin(); it != (V[a]).end(); ++it)
    if (!vis[*it]) {
      vis[*it] = 1;
      ans += DFS(*it);
    }
  return ans;
}
void solve() {
  int n, k, m, a, b;
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < (m); ++i) {
    scanf("%d%d", &a, &b);
    a--;
    b--;
    V[a].push_back(b);
    V[b].push_back(a);
  }
  vector<int> S;
  for (int i = 0; i < (n); ++i)
    if (!vis[i]) S.push_back(DFS(i));
  if (S.size() == 1) {
    printf("%d\n", 1 % k);
    return;
  }
  long long ans = 1;
  for (typeof((S).begin()) it = (S).begin(); it != (S).end(); ++it)
    ans = (ans * (*it)) % k;
  for (int i = 0; i < (S.size() - 2); ++i) ans = (ans * n) % k;
  printf("%d\n", (int)ans);
}
int main() {
  int t = 1;
  for (int i = 0; i < (t); ++i) solve();
  return 0;
}

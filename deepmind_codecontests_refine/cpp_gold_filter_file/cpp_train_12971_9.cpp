#include <bits/stdc++.h>
using namespace std;
int N, A[100005], leaf, cnt[2];
vector<int> adj[100005];
int vl[2][10000005];
void dfs(int nd, int par, int fl) {
  vl[fl][A[nd]]++;
  cnt[fl]++;
  if (adj[nd].size() <= 1) leaf = fl;
  for (int i = 0; i < adj[nd].size(); i++) {
    int ch = adj[nd][i];
    if (ch == par) continue;
    dfs(ch, par, fl ^ 1);
  }
}
long long all(long long x) { return (x * x - x) / 2; }
int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) scanf("%d", &A[i]);
  for (int i = 2; i <= N; i++) {
    int p;
    scanf("%d", &p);
    adj[p].push_back(i);
  }
  dfs(1, -1, 0);
  long long ans = 0, cur = 0;
  for (int x = 0; x < 10000005; x++)
    if (vl[leaf][x] & 1) cur ^= x;
  for (int x = 0; x < 10000005; x++) {
    if ((cur ^ x) < 10000005)
      ans += (long long)vl[leaf][x] * vl[leaf ^ 1][cur ^ x];
  }
  if (!cur) {
    ans += all(cnt[0]);
    ans += all(cnt[1]);
  }
  printf("%I64d\n", ans);
}

#include <bits/stdc++.h>
using namespace std;
long long ar[3][100005];
vector<int> G[100005];
vector<int> br;
bool dfs(int u, int par = -1) {
  br.push_back(u);
  int child = 0;
  for (auto& v : G[u]) {
    if (v == par) continue;
    if (!dfs(v, u)) return 0;
    child++;
    if (child > 1) return 0;
  }
  return 1;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = int(0); i < int(n); i++) scanf("%lld", &ar[0][i]);
  for (int i = int(0); i < int(n); i++) scanf("%lld", &ar[1][i]);
  for (int i = int(0); i < int(n); i++) scanf("%lld", &ar[2][i]);
  for (int i = int(1); i < int(n); i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--, v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  for (int i = int(0); i < int(n); i++) {
    if (int(G[i].size()) == 1) {
      if (dfs(i)) break;
      printf("-1\n");
      exit(0);
    }
  }
  vector<int> v = {0, 1, 2};
  vector<int> res;
  long long cost = 0x3f3f3f3f3f3f3f3f;
  do {
    long long tmp = 0;
    for (int i = int(0); i < int(n); i++) {
      tmp += ar[v[i % 3]][br[i]];
    }
    if (tmp < cost) cost = tmp, res = v;
  } while (next_permutation(v.begin(), v.end()));
  printf("%lld\n", cost);
  int ans[n];
  for (int i = int(0); i < int(n); i++) {
    ans[br[i]] = res[i % 3] + 1;
  }
  for (int i = int(0); i < int(n); i++) {
    printf("%d ", ans[i]);
  }
  return 0;
}

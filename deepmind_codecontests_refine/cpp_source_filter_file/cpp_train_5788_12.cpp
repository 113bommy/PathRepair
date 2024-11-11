#include <bits/stdc++.h>
const int mod = 1e9 + 7;
std::vector<int> e[200001];
int q[200001][6], n, k;
long long f[200001][6];
long long res;
bool vis[200001];
void DFS(int s) {
  vis[s] = true;
  q[s][0] = 1;
  int u;
  for (int i = 0; i < e[s].size(); ++i) {
    if (vis[e[s][i]]) continue;
    DFS(e[s][i]);
    u = e[s][i];
    for (int i = 0; i < k; ++i) {
      for (int j = 0; j < k; ++j) {
        res += q[s][i] * f[u][j] + f[s][i] * q[u][j] +
               q[s][i] * q[u][j] * ((i + j + 1) / k + ((i + j + 1) % k > 0));
      }
    }
    for (int i = 0; i < k; ++i) {
      q[s][i] += q[u][(k + i - 1) % k];
      f[s][i] += f[u][(k + i - 1) % k] + q[u][(k + i - 1) % k] * (!i);
    }
  }
}
int main() {
  std::cin >> n >> k;
  int l, r;
  for (int i = 1; i < n; ++i) {
    std::cin >> l >> r;
    e[l].push_back(r);
    e[r].push_back(l);
  }
  DFS(1);
  std::cout << res;
  return 0;
}

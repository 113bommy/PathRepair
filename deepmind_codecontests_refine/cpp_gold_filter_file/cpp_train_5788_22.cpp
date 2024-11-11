#include <bits/stdc++.h>
using namespace std;
int N, K;
long long res = 0;
vector<int> path[200001];
int kagi[200001][5];
long long jumps[200001][5];
void dfs(int pos, int par) {
  int X = path[pos].size();
  int berapa[5];
  long long tmp_jumps[5];
  memset(berapa, 0, sizeof(berapa));
  memset(tmp_jumps, 0, sizeof(tmp_jumps));
  for (int i = 0; i < X; i++) {
    int u = path[pos][i];
    if (u == par) continue;
    dfs(u, pos);
    for (int j = 0; j < K; j++) {
      for (int k = 0; k < K; k++) {
        long long wow = (long long)tmp_jumps[j] * kagi[u][k] +
                        (long long)berapa[j] * jumps[u][k];
        if (j + k > 0) wow += (long long)berapa[j] * kagi[u][k];
        if (j + k > K) wow += (long long)berapa[j] * kagi[u][k];
        res += wow;
      }
    }
    long long bzz = 0;
    for (int j = 0; j < K; j++) {
      if (j)
        bzz += (kagi[u][j] + jumps[u][j]);
      else
        bzz += jumps[u][j];
      berapa[j] += kagi[u][j];
      tmp_jumps[j] += jumps[u][j];
      kagi[pos][j] += kagi[u][j];
      jumps[pos][j] += jumps[u][j];
    }
    res += bzz;
  }
  kagi[pos][0]++;
  int tmp = kagi[pos][K - 1];
  long long tmp2 = jumps[pos][K - 1];
  for (int i = K - 1; i > 0; i--) {
    kagi[pos][i] = kagi[pos][i - 1];
    jumps[pos][i] = jumps[pos][i - 1];
  }
  kagi[pos][0] = tmp;
  jumps[pos][0] = tmp2;
  jumps[pos][0] += kagi[pos][0];
}
int main() {
  scanf("%d%d", &N, &K);
  for (int i = 1; i < N; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    a--;
    b--;
    path[a].push_back(b);
    path[b].push_back(a);
  }
  dfs(0, -1);
  cout << res << endl;
}

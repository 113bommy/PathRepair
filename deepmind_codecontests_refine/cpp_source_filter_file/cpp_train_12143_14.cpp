#include <bits/stdc++.h>
using namespace std;
int N;
bool graph[30][30];
int adj[30];
int x[(1 << 23)];
int y[(1 << 23)];
bitset<(1 << 23)> fast_convolution(bitset<(1 << 23)> X, bitset<(1 << 23)> Y) {
  int i, j;
  for ((i) = 0; (i) < (int)((1 << 23)); (i)++) x[i] = X[i];
  for ((i) = 0; (i) < (int)(23); (i)++)
    for ((j) = 0; (j) < (int)((1 << 23)); (j)++)
      if (!(j & (1 << i))) x[j ^ (1 << i)] += x[j];
  for ((i) = 0; (i) < (int)((1 << 23)); (i)++) x[i] *= x[i];
  for ((i) = 0; (i) < (int)(23); (i)++)
    for ((j) = 0; (j) < (int)((1 << 23)); (j)++)
      if (j & (1 << i)) x[j] -= x[j ^ (1 << i)];
  bitset<(1 << 23)> ans;
  for ((i) = 0; (i) < (int)((1 << 23)); (i)++) ans[i] = (x[i] != 0);
  return ans;
}
bitset<(1 << 23)> convolution(bitset<(1 << 23)> X, bitset<(1 << 23)> Y) {
  int i, j;
  for ((i) = 0; (i) < (int)((1 << 23)); (i)++) x[i] = X[i];
  for ((i) = 0; (i) < (int)(23); (i)++)
    for ((j) = 0; (j) < (int)((1 << 23)); (j)++)
      if (!(j & (1 << i))) x[j ^ (1 << i)] += x[j];
  for ((i) = 0; (i) < (int)((1 << 23)); (i)++) y[i] = Y[i];
  for ((i) = 0; (i) < (int)(23); (i)++)
    for ((j) = 0; (j) < (int)((1 << 23)); (j)++)
      if (!(j & (1 << i))) y[j ^ (1 << i)] += y[j];
  for ((i) = 0; (i) < (int)((1 << 23)); (i)++) x[i] *= y[i];
  for ((i) = 0; (i) < (int)(23); (i)++)
    for ((j) = 0; (j) < (int)((1 << 23)); (j)++)
      if (j & (1 << i)) x[j] -= x[j ^ (1 << i)];
  bitset<(1 << 23)> ans;
  for ((i) = 0; (i) < (int)((1 << 23)); (i)++) ans[i] = (x[i] != 0);
  return ans;
}
bitset<(1 << 23)> dp[25];
int chromatic(void) {
  int i, j;
  if (N == 0) return 0;
  for ((i) = 0; (i) < (int)(N); (i)++)
    for ((j) = 0; (j) < (int)(N); (j)++)
      if (graph[i][j]) adj[i] |= (1 << j);
  bitset<(1 << 23)> B;
  B.reset();
  for ((i) = 0; (i) < (int)((1 << N)); (i)++) {
    bool good = true;
    for ((j) = 0; (j) < (int)(N); (j)++)
      if (i & (1 << j))
        if (i & adj[j]) good = false;
    if (good) B[i] = true;
  }
  int all = (1 << N) - 1;
  dp[1] = B;
  dp[2] = fast_convolution(dp[1], dp[1]);
  dp[4] = fast_convolution(dp[2], dp[2]);
  dp[8] = fast_convolution(dp[4], dp[4]);
  dp[16] = fast_convolution(dp[8], dp[8]);
  bitset<(1 << 23)> C;
  C.reset();
  C[0] = true;
  int ans = 0;
  for (i = 16; i >= 1; i /= 2) {
    bitset<(1 << 23)> D = convolution(C, dp[i]);
    if (!D[all]) {
      C = D;
      ans += i;
    }
  }
  return ans + 1;
}
int V;
string input[60];
bool reach[60][60];
int id[60];
bool used[60];
int main(void) {
  int i, j, k;
  cin >> V;
  for ((i) = 0; (i) < (int)(V); (i)++) cin >> input[i];
  for ((i) = 0; (i) < (int)(V); (i)++)
    for ((j) = 0; (j) < (int)(V); (j)++)
      reach[i][j] = (i == j || input[i][j] == 'A');
  for ((k) = 0; (k) < (int)(V); (k)++)
    for ((i) = 0; (i) < (int)(V); (i)++)
      for ((j) = 0; (j) < (int)(V); (j)++)
        if (reach[i][k] && reach[k][j]) reach[i][j] = true;
  for ((i) = 0; (i) < (int)(V); (i)++)
    for ((j) = 0; (j) < (int)(V); (j)++)
      if (reach[i][j] && input[i][j] == 'X') {
        cout << -1 << endl;
        return 0;
      }
  for ((i) = 0; (i) < (int)(V); (i)++) id[i] = -1;
  N = 0;
  for ((i) = 0; (i) < (int)(V); (i)++)
    if (!used[i]) {
      vector<int> v;
      for ((j) = 0; (j) < (int)(V); (j)++)
        if (reach[i][j]) v.push_back(j);
      if (v.size() >= 2) {
        for ((j) = 0; (j) < (int)(v.size()); (j)++) id[v[j]] = N;
        N++;
      }
      for ((j) = 0; (j) < (int)(v.size()); (j)++) used[v[j]] = true;
    }
  for ((i) = 0; (i) < (int)(V); (i)++)
    for ((j) = 0; (j) < (int)(V); (j)++)
      if (input[i][j] == 'X' && id[i] != id[j] && id[i] >= 0 && id[j] >= 0)
        graph[id[i]][id[j]] = true;
  int ans = V + 1 - chromatic();
  cout << ans << endl;
  return 0;
}

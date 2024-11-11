#include <bits/stdc++.h>
using namespace std;
template <typename T>
ostream &operator<<(ostream &out, const vector<T> &v) {
  out << "{";
  for (const T &a : v) out << a << ", ";
  out << "}";
  return out;
}
template <typename S, typename T>
ostream &operator<<(ostream &out, const pair<S, T> &p) {
  out << "(" << p.first << ", " << p.second << ")";
  return out;
}
const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};
const int mod = 1000000007;
int n, S;
int in[510];
int out[510];
int weight[510];
int strength[510];
int gain[510];
int dp[510][1010];
vector<int> child[510];
bool solved[510];
bool inside(int a, int b) { return in[a] <= in[b] && out[b] <= out[a]; }
bool cmpOut(int a, int b) { return out[a] < out[b]; }
int cdp[510][1010];
void solve(int u) {
  solved[u] = 1;
  for (int v = (0); v < (n); ++v)
    if (u != v && inside(u, v)) {
      child[u].push_back(v);
      if (!solved[v]) solve(v);
    }
  child[u].push_back(n);
  sort((child[u]).begin(), (child[u]).end(), cmpOut);
  for (int i = (1); i < (((int)(child[u]).size())); ++i) {
    int v = child[u][i];
    int k = 0;
    for (int j = (1); j < (i); ++j)
      if (out[child[u][k]] < out[child[u][j]] &&
          out[child[u][j]] <= in[child[u][i]])
        k = j;
    for (int s = (0); s < (S + 1); ++s)
      cdp[i][s] = max(cdp[i - 1][s], cdp[k][s] + dp[v][s]);
  }
  for (int s = (0); s < (S + 1); ++s)
    dp[u][s] = cdp[((int)(child[u]).size()) - 1][s];
  for (int s = (S); s > (weight[u] - 1); --s)
    dp[u][s] = max(dp[u][s], dp[u][min(strength[u], s - weight[u])] + gain[u]);
}
int main() {
  scanf("%d %d", &n, &S);
  ++n;
  in[0] = -5;
  out[0] = 2 * n + 5;
  weight[0] = 0;
  strength[0] = S;
  gain[0] = 0;
  for (int i = (1); i < (n); ++i)
    scanf("%d %d %d %d %d", &in[i], &out[i], &weight[i], &strength[i],
          &gain[i]);
  in[n] = out[n] = -10;
  solve(0);
  printf("%d\n", dp[0][S]);
  return 0;
}

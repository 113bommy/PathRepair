#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long mult[2], randNum[100010];
long long hashV[2][100010], rootHash[2][100010], tmpHash[100010];
set<pair<long long, long long> > dic;
int size[100010];
vector<int> g[100010];
vector<long long> nxtHash[100010];
mt19937 ran(time(nullptr));
inline bool cmp(int a, int b) { return hashV[0][a] < hashV[0][b]; }
inline bool cmp2(int a, int b) { return tmpHash[a] < tmpHash[b]; }
inline long long pow2(long long a, long long b) {
  a %= mod;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % mod;
    b >>= 1;
    a = a * a % mod;
  }
  return res;
}
void dfs(int u, int fa) {
  size[u] = 1;
  for (int v : g[u]) {
    if (v == fa) continue;
    dfs(v, u);
    size[u] += size[v];
  }
  sort(g[u].begin(), g[u].end(), cmp);
  hashV[0][u] = randNum[(int)g[u].size()];
  for (int v : g[u]) {
    if (v == fa) continue;
    hashV[0][u] = hashV[0][u] * pow2(mult[0], size[v]) % mod;
    hashV[0][u] = (hashV[0][u] + hashV[0][v]) % mod;
  }
}
void dfs2(int u, int fa, long long upHash, int upSize) {
  for (int v : g[u]) {
    if (v != fa)
      tmpHash[v] = hashV[0][v];
    else
      tmpHash[v] = upHash;
  }
  sort(g[u].begin(), g[u].end(), cmp2);
  rootHash[0][u] = randNum[(int)g[u].size()];
  for (int v : g[u]) {
    if (v == fa)
      rootHash[0][u] = rootHash[0][u] * pow2(mult[0], upSize) % mod;
    else
      rootHash[0][u] = rootHash[0][u] * pow2(mult[0], size[v]) % mod;
    rootHash[0][u] = (rootHash[0][u] + tmpHash[v]) % mod;
  }
  nxtHash[u].clear();
  for (int v : g[u]) {
    if (v != fa) {
      long long nxt = randNum[(int)g[u].size()];
      for (int nxtv : g[u]) {
        if (nxtv == v) continue;
        if (nxtv == fa)
          nxt = nxt * pow2(mult[0], upSize) % mod;
        else
          nxt = nxt * pow2(mult[0], size[nxtv]) % mod;
        nxt = (nxt + tmpHash[nxtv]) % mod;
      }
      nxtHash[u].push_back(nxt);
    }
  }
  int idx = 0;
  for (int v : g[u]) {
    if (v != fa) {
      dfs2(v, u, nxtHash[u][idx++], upSize + size[u] - size[v]);
    }
  }
}
int main() {
  int n, a, b;
  scanf("%d", &n);
  mult[0] = ran() % mod;
  mult[1] = ran() % mod;
  for (int i = 1; i < n; i++) {
    scanf("%d%d", &a, &b);
    g[a].push_back(b);
    g[b].push_back(a);
    randNum[i] = ran() % mod;
  }
  dfs(1, -1);
  dfs2(1, -1, 0, 0);
  for (int i = 1; i <= n; i++) {
    swap(rootHash[0][i], rootHash[1][i]);
    swap(hashV[0][i], hashV[1][i]);
  }
  swap(mult[0], mult[1]);
  dfs(1, -1);
  dfs2(1, -1, 0, 0);
  for (int i = 1; i <= n; i++)
    if ((int)g[i].size() < 4)
      dic.insert(pair<long long, long long>(rootHash[0][i], rootHash[1][i]));
  printf("%d\n", (int)dic.size());
  return 0;
}

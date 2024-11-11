#include <bits/stdc++.h>
using namespace std;
const int md = 1e9 + 7;
struct edge {
  int id1, id2;
};
edge e[2][11111];
const long long mod = (1e9 + 9) * (1e4 + 7);
const int a = 37, b = 1007, pn = 1e4 + 9, base = 67;
int n[2];
vector<int> adj[2][1111];
int dp[1 << 12], ww[1001][13], root, pr[1001];
bool can[1 << 12];
long long hs[13][13];
long long get_hash(int idx, int id, int pa) {
  long long res;
  vector<long long> now;
  now.clear();
  int i, j, s, p, q, ip;
  for (i = 0; i < adj[idx][id].size(); i++) {
    ip = adj[idx][id][i];
    if (ip == pa) continue;
    long long vl = get_hash(idx, ip, id);
    now.push_back(vl);
    hs[root][ip] = vl;
  }
  sort(now.begin(), now.end());
  res = a;
  for (i = 0; i < now.size(); i++) res = ((res * pn) ^ now[i]) % mod;
  res = (res * b) % mod;
  return res;
}
void got(int id, int pa) {
  int i, j, s, p, q, ip;
  pr[id] = pa;
  for (i = 0; i < adj[0][id].size(); i++) {
    ip = adj[0][id][i];
    if (ip == pa) continue;
    got(ip, id);
  }
}
int match(int id1, int id2, int pa1, int pa2) {
  int i, j, s, p, q, ip1, ip2;
  int pw[13], cnt = 0, ret = 0;
  for (i = 0; i < adj[1][id2].size(); i++) {
    ip2 = adj[1][id2][i];
    if (ip2 == pa2) continue;
    pw[cnt++] = ip2;
  }
  for (i = 0; i < adj[0][id1].size(); i++) {
    ip1 = adj[0][id1][i];
    if (ip1 == pa1) continue;
    for (j = 0; j < adj[1][id2].size(); j++) {
      ip2 = adj[1][id2][j];
      if (ip2 == pa2) continue;
      ww[ip1][ip2] = match(ip1, ip2, id1, id2);
    }
  }
  for (i = 0; i < (1 << cnt); i++) {
    dp[i] = 0;
    can[i] = true;
    for (j = 0; j < cnt && can[i]; j++) {
      if (!(i & (1 << j))) {
        for (s = j + 1; s < cnt && can[i]; s++) {
          if (i & (1 << s)) {
            if (hs[root][pw[j]] == hs[root][pw[s]]) can[i] = false;
          }
        }
      }
    }
  }
  dp[0] = 1;
  for (i = 0; i < adj[0][id1].size(); i++) {
    ip1 = adj[0][id1][i];
    if (ip1 == pa1) continue;
    for (j = (1 << cnt) - 1; j >= 0; j--) {
      if (dp[j] == 0) continue;
      for (s = 0; s < cnt; s++) {
        if (!(j & (1 << s)) && can[j | (1 << s)]) {
          dp[j | (1 << s)] +=
              (int)((long long)dp[j] * (long long)ww[ip1][pw[s]] % md);
          dp[j | (1 << s)] %= md;
        }
      }
    }
  }
  return dp[(1 << cnt) - 1];
}
int main() {
  int i, j, s, p, q, ans = 0;
  for (i = 0; i < 2; i++) {
    scanf("%d", &n[i]);
    for (j = 0; j < n[i] - 1; j++) {
      scanf("%d%d", &e[i][j].id1, &e[i][j].id2);
      e[i][j].id1--;
      e[i][j].id2--;
      adj[i][e[i][j].id1].push_back(e[i][j].id2);
      adj[i][e[i][j].id2].push_back(e[i][j].id1);
    }
  }
  for (i = 0; i < n[1]; i++) {
    root = i;
    hs[i][i] = get_hash(1, i, -1);
  }
  got(0, -1);
  for (i = 0; i < n[1]; i++) {
    for (j = 0; j < i; j++) {
      if (hs[i][i] == hs[j][j]) break;
    }
    if (j >= i) {
      memset(ww, 0, sizeof(ww));
      root = i;
      for (j = 0; j < n[0]; j++) ans = (ans + match(j, i, pr[j], -1)) % md;
    }
  }
  printf("%d\n", ans);
  return 0;
}

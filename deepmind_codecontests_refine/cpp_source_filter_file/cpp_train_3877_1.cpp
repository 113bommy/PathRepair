#include <bits/stdc++.h>
using namespace std;
string inp[20];
int is = 0;
struct AhoCorasick {
  int ch[1005][14], fail[1005], nxt[1005][14], ff[16][1005];
  long long cost[1005], ffc[16][1005];
  long long memo[16384][1005];
  vector<int> bfs;
  int rt = 1, nit = 1;
  AhoCorasick() {
    memset(ch, 0, sizeof(ch));
    memset(fail, 0, sizeof(fail));
    memset(nxt, 0, sizeof(nxt));
    memset(cost, 0, sizeof(cost));
    memset(ff, 0, sizeof(ff));
    memset(ffc, 0, sizeof(ffc));
  }
  void insert(string &T, int c) {
    int t = T.length();
    int n = rt;
    for (int i = (0); i <= (t - 1); i++) {
      int x = T[i] - 'a';
      if (!ch[n][x]) {
        ch[n][x] = ++nit;
      }
      n = ch[n][x];
    }
    cost[n] += c;
  }
  void build() {
    for (int i = (0); i <= (13); i++) {
      if (ch[rt][i]) {
        bfs.push_back(ch[rt][i]);
        fail[ch[rt][i]] = rt;
      }
    }
    for (int j = (0); j <= ((int)bfs.size() - 1); j++) {
      int u = bfs[j];
      for (int i = (0); i <= (13); i++) {
        if (!ch[u][i]) continue;
        int v = ch[u][i];
        int f = fail[u];
        while (f && !ch[f][i]) f = fail[f];
        if (!f)
          fail[v] = rt;
        else
          fail[v] = ch[f][i];
        bfs.push_back(v);
      }
    }
    for (int u = (1); u <= (nit); u++) {
      for (int i = (0); i <= (13); i++) {
        int f = u;
        while (f && !ch[f][i]) f = fail[f];
        if (!f)
          f = rt;
        else
          f = ch[f][i];
        nxt[u][i] = f;
      }
    }
  }
  void push_costs() {
    for (auto u : bfs) cost[u] += cost[fail[u]];
  }
  void transverse(string &T, int id) {
    for (int i = (1); i <= (nit); i++) {
      int t = T.length();
      int n = i;
      long long sum = 0;
      for (int j = (0); j <= (t - 1); j++) {
        int x = T[j] - 'a';
        n = nxt[n][x];
        sum += cost[n];
      }
      ff[id][i] = n;
      ffc[id][i] = sum;
    }
  }
  long long evaluate() {
    for (int i = (0); i <= ((1 << 14) - 1); i++)
      for (int j = (1); j <= (nit); j++) memo[i][j] = -1000000000000000000;
    return dp(0, 1, rt);
  }
  long long dp(int mask, int i, int n) {
    if (i == is) return ffc[i][n];
    if (memo[mask][n] > -1000000000000000000) return memo[mask][n];
    long long res = -1000000000000000000;
    for (int j = (0); j <= (13); j++) {
      if (mask & (1 << j)) continue;
      int u = ff[i][n];
      int v = nxt[u][j];
      res = max(res, dp(mask | (1 << j), i + 1, v) + ffc[i][n] + cost[v]);
    }
    return memo[mask][n] = res;
  }
} ac;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int k;
  cin >> k;
  for (int i = (1); i <= (k); i++) {
    string T;
    int cost;
    cin >> T >> cost;
    ac.insert(T, cost);
  }
  ac.build();
  ac.push_costs();
  string S, T;
  cin >> S;
  int s = S.length();
  for (int i = (0); i <= (s - 1); i++) {
    if (S[i] == '?') {
      ac.transverse(T, ++is);
      T = "";
    } else {
      T += S[i];
    }
  }
  ac.transverse(T, ++is);
  printf("%d\n", ac.evaluate());
  return 0;
}

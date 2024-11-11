#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
int chl[MAXN][2], depth[MAXN], v[MAXN], fin[MAXN], top = 0, root = 0;
int n;
int lookahead;
inline void skip() {
  while (lookahead != '+' && lookahead != '-' && lookahead != '.' &&
         lookahead != '/' && !isdigit(lookahead))
    lookahead = getchar();
}
inline int read() {
  int a = 0;
  while (!isdigit(lookahead)) lookahead = getchar();
  while (isdigit(lookahead)) {
    a = a * 10 + lookahead - '0';
    lookahead = getchar();
  }
  return a;
}
int insert(int &nd, long long ip, int k, int flag, int cur_lev) {
  if (!nd) nd = ++top, depth[nd] = 32 - cur_lev;
  if (32 - cur_lev > k) {
    v[nd] |= flag;
    fin[nd] |= flag;
    return v[nd];
  }
  v[nd] |= insert(chl[nd][ip >> cur_lev & 1], ip, k, flag, cur_lev - 1);
  return v[nd];
}
vector<pair<long long, int> > vec;
int flag = 1;
void dfs(int nd, long long cur_ip, int cur_lev, int cur_v) {
  if (!nd) return;
  cur_v |= fin[nd];
  if (cur_v == 3) flag = 0;
  if (cur_v == 1 && (v[nd] == 2 || v[nd] == 3)) flag = 0;
  if (cur_v == 2 && (v[nd] == 1 || v[nd] == 3)) flag = 0;
  if (v[nd] == 2) {
    vec.push_back(make_pair(cur_ip, 31 - cur_lev));
    return;
  }
  if (cur_lev != -1) {
    dfs(chl[nd][0], cur_ip, cur_lev - 1, cur_v);
    dfs(chl[nd][1], cur_ip | (1ll << cur_lev), cur_lev - 1, cur_v);
  }
}
int main() {
  n = read();
  for (int i = 1; i <= n; i++) {
    skip();
    int flag;
    if (lookahead == '+') {
      flag = 1;
    } else if (lookahead == '-') {
      flag = 2;
    } else
      throw;
    long long ip = 0;
    for (int j = 3; j >= 0; j--) ip = ip | ((long long)read() << (j << 3));
    int t = 32;
    if (lookahead == '/') t = read();
    insert(root, ip, t, flag, 31);
  }
  dfs(root, 0, 31, 0);
  if (flag == 0)
    puts("-1");
  else {
    printf("%d\n", vec.size());
    for (int i = 0; i < vec.size(); i++) {
      long long ip = vec[i].first;
      int k = vec[i].second;
      for (int j = 3; j >= 0; j--)
        printf("%d%c", (ip >> (j << 3)) & 255, j == 0 ? '/' : '.');
      printf("%d\n", k);
    }
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int P = 1e9 + 7;
int add(int a, int b) {
  if ((a += b) >= P) a -= P;
  return a;
}
int sub(int a, int b) {
  if ((a -= b) < 0) a += P;
  return a;
}
int mul(int a, int b) { return 1ll * a * b % P; }
int kpow(int a, int b) {
  int r = 1;
  for (; b; b >>= 1, a = mul(a, a)) {
    if (b & 1) r = mul(r, a);
  }
  return r;
}
const int N = 111;
int r, n;
int sg[N][4];
bool mex[N << 1], vis[N][2];
int calc() {
  for (int j = 0;; ++j)
    if (!mex[j]) {
      return j;
    }
}
void init() {
  for (int i = (0); i < (4); i++) sg[0][i] = 0, sg[1][i] = 1;
  sg[1][3] = 0;
  for (int i = (2); i < (N); i++) {
    memset(mex, 0, sizeof(mex));
    for (int j = (1); j < (i - 1); j++) mex[sg[j][1] ^ sg[i - 1 - j][1]] = 1;
    mex[sg[i - 1][1]] = 1;
    sg[i][0] = calc();
    memset(mex, 0, sizeof(mex));
    for (int j = (1); j < (i - 1); j++) mex[sg[j][3] ^ sg[i - 1 - j][1]] = 1;
    for (int j = (1); j < (i - 1); j++) mex[sg[j][2] ^ sg[i - 1 - j][1]] = 1;
    for (int j = (1); j < (4); j++) mex[sg[i - 1][j]] = 1;
    sg[i][1] = calc();
    memset(mex, 0, sizeof(mex));
    for (int j = (1); j < (i - 1); j++) mex[sg[j][3] ^ sg[i - 1 - j][3]] = 1;
    for (int j = (1); j < (i - 1); j++) mex[sg[j][2] ^ sg[i - 1 - j][2]] = 1;
    mex[sg[i - 1][2]] = 1;
    sg[i][2] = calc();
    memset(mex, 0, sizeof(mex));
    for (int j = (1); j < (i - 1); j++) mex[sg[j][3] ^ sg[i - 1 - j][2]] = 1;
    mex[sg[i - 1][3]] = 1;
    sg[i][3] = calc();
  }
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  init();
  cin >> r >> n;
  for (int i = (1); i < (n + 1); i++) {
    int x, y;
    cin >> x >> y;
    --y;
    vis[x][y] = 1;
    vis[x][y ^ 1] = 1;
    if (x + 1 <= r) vis[x + 1][y ^ 1] = 1;
    if (x - 1 >= 1) vis[x - 1][y ^ 1] = 1;
  }
  int ans = 0, st = 1, ed = 1;
  while (st <= r && ed <= r) {
    while (st <= r && vis[st][0] && vis[st][1]) ++st;
    ed = st;
    while (ed <= r && (!vis[ed][0] || !vis[ed][1])) ++ed;
    --ed;
    if (st <= ed && ed <= r) {
      int t = vis[st][0] + vis[st][1] + vis[ed][0] + vis[ed][1];
      if (vis[st][0] != vis[ed][0] && vis[st][1] != vis[ed][1]) ++t;
      ans ^= sg[ed - st + 1][t];
    }
    st = ed + 1;
  }
  cout << (ans ? "WIN" : "LOSE") << "\n";
  return 0;
}

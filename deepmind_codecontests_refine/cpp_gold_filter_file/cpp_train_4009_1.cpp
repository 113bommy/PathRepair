#include <bits/stdc++.h>
using namespace std;
const int mx = 1 << 16;
int l[505], tot, r[505], f[505], ls[505], zy[505], rs[505], len;
char ch[505];
long long ans, F[mx], G[mx], dp[505][mx];
int solve(int L, int R) {
  int now = ++tot;
  l[now] = L;
  r[now] = R;
  zy[now] = ch[L];
  if (L != R) {
    int ee = 0, i;
    for (i = L; i <= R; ++i) {
      if (ch[i] == '(') ++ee;
      if (ch[i] == ')') --ee;
      if (!ee) break;
    }
    ls[now] = solve(L + 1, i - 1);
    zy[now] = ch[i + 1];
    rs[now] = solve(i + 3, R - 1);
  }
  return now;
}
void FWT1(long long *f, int typ) {
  int i, j, k, rr;
  for (i = 1; i < mx; i <<= 1)
    for (rr = i << 1, j = 0; j < mx; j += rr)
      for (k = 0; k < i; ++k) (f[j + k + i] += f[j + k] * typ) %= 1000000007;
}
void FWT2(long long *f, int typ) {
  int i, j, k, rr;
  for (i = 1; i < mx; i <<= 1)
    for (rr = i << 1, j = 0; j < mx; j += rr)
      for (k = 0; k < i; ++k) (f[j + k] += f[j + k + i] * typ) %= 1000000007;
}
void SOLVE(int now) {
  int i, j, st, X = 0;
  if (l[now] == r[now]) {
    if (zy[now] == '?') {
      for (i = 0; i < 4; ++i) {
        for (st = j = 0; j < 16; ++j)
          if ((j >> i) & 1) st |= 1 << j;
        dp[now][st] = 1;
        for (st = j = 0; j < 16; ++j)
          if (!((j >> i) & 1)) st |= 1 << j;
        dp[now][st] = 1;
      }
    } else if (zy[now] <= 'D') {
      i = 'D' - zy[now];
      for (st = j = 0; j < 16; ++j)
        if ((j >> i) & 1) st |= 1 << j;
      dp[now][st] = 1;
    } else {
      i = 'd' - zy[now];
      for (st = j = 0; j < 16; ++j)
        if (!((j >> i) & 1)) st |= 1 << j;
      dp[now][st] = 1;
    }
    return;
  }
  SOLVE(ls[now]);
  SOLVE(rs[now]);
  if (zy[now] != '&') {
    for (i = 0; i < mx; ++i) F[i] = dp[ls[now]][i];
    for (i = 0; i < mx; ++i) G[i] = dp[rs[now]][i];
    FWT1(F, 1);
    FWT1(G, 1);
    for (i = 0; i < mx; ++i) F[i] = F[i] * G[i] % 1000000007;
    FWT1(F, -1);
    for (i = 0; i < mx; ++i) {
      dp[now][i] += F[i];
    }
  }
  if (zy[now] != '|') {
    for (i = 0; i < mx; ++i) F[i] = dp[ls[now]][i];
    for (i = 0; i < mx; ++i) G[i] = dp[rs[now]][i];
    FWT2(F, 1);
    FWT2(G, 1);
    for (i = 0; i < mx; ++i) F[i] = F[i] * G[i] % 1000000007;
    FWT2(F, -1);
    for (i = 0; i < mx; ++i) {
      (dp[now][i] += F[i]) %= 1000000007;
    }
  }
}
int i, st, fl, x, j, ss[16];
int main() {
  scanf("%s", ch + 1), len = strlen(ch + 1);
  solve(1, len);
  SOLVE(1);
  memset(ss, -1, sizeof(ss));
  cin >> len;
  while (len--) {
    st = 0;
    cin >> st >> x;
    st = st << 1 | x;
    cin >> x;
    st = st << 1 | x;
    cin >> x;
    st = st << 1 | x;
    cin >> ss[st];
  }
  for (i = 0; i < mx; ++i) {
    for (fl = 0, j = 0; j < 16; ++j)
      if (~ss[j] && ss[j] != ((i >> j) & 1)) {
        fl = 1;
        break;
      }
    if (!fl) ans += dp[1][i];
  }
  cout << (ans % 1000000007 + 1000000007) % 1000000007;
}

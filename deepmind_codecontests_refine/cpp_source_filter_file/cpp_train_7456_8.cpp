#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
const int maxn = 1e6 + 5;
int n, aNum, pNum, fst = -1, lst = -1;
int sum[maxn], dp[maxn], p[maxn], nxt[maxn], pre[maxn];
char s[maxn];
pair<int, int> onePackman() {
  int pos;
  pair<int, int> ret;
  for (int i = 1; i <= n; ++i) {
    if (s[i] == 'P') {
      pos = i;
      break;
    }
  }
  if (sum[pos] > sum[n] - sum[pos - 1]) {
    ret.first = sum[pos];
    if (~fst)
      ret.second = pos - fst;
    else
      ret.second = 0;
  } else if (sum[pos] < sum[n] - sum[pos - 1]) {
    ret.first = sum[n] - sum[pos - 1];
    if (~lst)
      ret.second = lst - pos;
    else
      ret.second = 0;
  } else {
    ret.first = sum[n] - sum[pos - 1];
    if ((~fst) && (~lst))
      ret.second = min(pos - fst, lst - pos);
    else if (~fst)
      ret.second = pos - fst;
    else if (~lst)
      ret.second = pos - lst;
    else
      ret.second = 0;
  }
  return ret;
}
bool check(int md) {
  memset(dp, 0, sizeof(dp));
  for (int i = 1; i <= pNum; ++i) {
    int x = p[i], y = p[i - 1];
    int &res = dp[i];
    if (dp[i - 1] >= pre[x])
      res = max(res, max(dp[i - 1], min(x + md, n)));
    else if (dp[i - 1] < x && x - md <= nxt[dp[i - 1]])
      res = max(res, i);
    if (i >= 2 && x - md <= nxt[dp[i - 2]]) res = max(res, min(y + md, n));
  }
  return (dp[pNum] >= lst);
}
int main() {
  scanf("%d", &n);
  scanf("%s", s + 1);
  for (int i = 1; i <= n; ++i) {
    if (s[i] == 'P') {
      p[++pNum] = i;
    } else if (s[i] == '*') {
      aNum++;
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (s[i] == '*') {
      fst = i;
      break;
    }
  }
  for (int i = 1; i <= n; ++i)
    if (s[i] == '*') lst = i;
  nxt[n] = n;
  for (int i = n - 1; i >= 0; i--) {
    if (s[i + 1] == '*')
      nxt[i] = i + 1;
    else
      nxt[i] = nxt[i + 1];
  }
  for (int i = 1; i <= n; i++) {
    if (s[i - 1] == '*')
      pre[i] = i - 1;
    else
      pre[i] = pre[i - 1];
  }
  for (int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + (s[i] == '*');
  if (pNum == 1) {
    pair<int, int> ans = onePackman();
    printf("%d %d\n", ans.first, ans.second);
    return 0;
  }
  int lb = -1, rb = n;
  while (lb + 1 < rb) {
    int md = (lb + rb) >> 1;
    if (check(md))
      rb = md;
    else
      lb = md;
  }
  printf("%d %d\n", aNum, rb);
  return 0;
}

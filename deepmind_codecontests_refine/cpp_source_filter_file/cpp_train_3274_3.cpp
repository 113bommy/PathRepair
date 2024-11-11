#include <bits/stdc++.h>
using namespace std;
inline void __CIN__() {
  ios::sync_with_stdio(false);
  cin.tie(0);
}
char buf;
inline int xint() {
  while (buf = getchar(), buf < '0' || buf > '9')
    ;
  int x = buf - '0';
  for (; buf = getchar(), buf >= '0' && buf <= '9'; x = x * 10 + buf - '0')
    ;
  return x;
}
inline long long xll() {
  while (buf = getchar(), buf < '0' || buf > '9')
    ;
  long long x = buf - '0';
  for (; buf = getchar(), buf >= '0' && buf <= '9'; x = x * 10 + buf - '0')
    ;
  return x;
}
inline string xstring() {
  while (buf = getchar(), buf == ' ' || buf == '\n')
    ;
  string x = "";
  for (x += buf; buf = getchar(), buf != ' ' && buf != '\n'; x += buf)
    ;
  return x;
}
const int base[16] = {2,  3,  5,  7,  11, 13, 17, 19,
                      23, 29, 31, 37, 41, 43, 47, 53};
int pos[105], val[105], N, ans = (int)(1e9 + 7), y[105], tmp[105];
struct Node {
  int d, x;
  bool operator<(const Node &th) const { return x > th.x; }
} Q[55];
void dfs(int now, int k, int ret) {
  if (ret >= ans) {
    return;
  }
  if (k == N) {
    if (ret < ans) {
      for (int i = 0; i < N; ++i) tmp[i] = y[i];
      ans = ret;
    }
    return;
  }
  while (pos[now] & val[k - 1]) --now;
  while (now > 0) {
    y[Q[k].d] = now;
    val[k] = val[k - 1] | pos[now];
    dfs(now, k + 1, ret + abs(now - Q[k].x));
    --now;
    while (pos[now] & val[k - 1]) --now;
  }
  return;
}
int main() {
  memset(pos, 0, sizeof(pos));
  memset(val, 0, sizeof(val));
  for (int i = 0; i < 16; ++i) {
    for (int j = base[i]; j < 55; j += base[i]) pos[j] |= (1 << i);
  }
  N = xint();
  for (int i = 0; i < N; ++i) {
    scanf("%d", &Q[i].x);
    Q[i].d = i;
  }
  sort(Q, Q + N);
  for (int i = 54; i > 0; --i) {
    val[0] = pos[i];
    y[Q[0].d] = i;
    dfs(i, 1, abs(i - Q[0].x));
  }
  for (int i = 0; i < N; ++i) printf("%d%c", tmp[i], " \n"[i == N - 1]);
  return 0;
}

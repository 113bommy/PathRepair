#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
const int maxn = 300005;
int n, mk, a[maxn], b[maxn], lst, used[maxn];
int isget[maxn][2], ansget[maxn][2];
bool vis[maxn][3];
inline int read() {
  int res = 0, f_f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f_f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    res = (res << 3) + (res << 1) + (ch - '0'), ch = getchar();
  return res * f_f;
}
struct AS {
  int x, tp, w;
  AS() {}
  AS(int x, int tp, int w) : x(x), tp(tp), w(w) {}
  bool operator<(const AS B) const { return w > B.w; }
};
priority_queue<AS> Q;
inline long long solve(int m, int d) {
  memset(vis, 0, sizeof(vis));
  memset(isget, 0, sizeof(isget));
  memset(used, 0, sizeof(used));
  while (!Q.empty()) Q.pop();
  for (int i = 1; i <= n; i++) {
    Q.push(AS(i, 0, a[i] << 1));
    Q.push(AS(i, 2, a[i] + b[i]));
  }
  long long ans = 0;
  while (1) {
    if (!m) break;
    AS u = Q.top();
    Q.pop();
    if (vis[u.x][u.tp]) continue;
    if (u.tp == 0) {
      ans += u.w >> 1;
      vis[u.x][0] = true;
      vis[u.x][2] = true;
      m--, used[u.x] = 1, isget[u.x][0] = 1;
      Q.push(AS(u.x, 1, b[u.x] << 1));
    } else if (u.tp == 1) {
      ans += u.w >> 1;
      vis[u.x][1] = true;
      m--, used[u.x] = 2, isget[u.x][1] = 1;
    } else {
      if (m == 1) continue;
      ans += u.w;
      vis[u.x][0] = true;
      vis[u.x][1] = true;
      vis[u.x][2] = true;
      m -= 2, used[u.x] = 2;
      isget[u.x][0] = 1, isget[u.x][1] = 1;
    }
  }
  if (!d) return ans;
  lst = -INF;
  int cur = 0, tp = 0;
  for (int i = 1; i <= n; i++) {
    if (used[i] == 1 && lst < a[i]) {
      isget[cur][tp] = 1, isget[i][0] = 0;
      lst = a[i], cur = i, tp = 0;
    }
    if (used[i] == 2 && lst < b[i]) {
      isget[cur][tp] = 1, isget[i][1] = 0;
      lst = b[i], cur = i, tp = 1;
    }
  }
  return ans - lst;
}
int main() {
  n = read(), mk = read();
  for (int i = 1; i <= n; i++) {
    a[i] = read(), b[i] = read();
    b[i] -= a[i];
    Q.push(AS(i, 0, a[i] << 1));
    Q.push(AS(i, 2, a[i] + b[i]));
  }
  long long ans = solve(mk, 0);
  memcpy(ansget, isget, sizeof(isget));
  if ((n >> 1) > mk) {
    long long cur = solve(mk + 1, 1);
    if (cur < ans) {
      ans = cur;
      memcpy(ansget, isget, sizeof(isget));
    }
  }
  printf("%lld\n", ans);
  for (int i = 1; i <= n; i++) {
    if (ansget[i][1])
      printf("2");
    else if (ansget[i][0])
      printf("1");
    else
      printf("0");
  }
  printf("\n");
  return 0;
}

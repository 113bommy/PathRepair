#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  return x * f;
}
int son[9300000][2], cnt = 1, num[9300000], N, sum, K;
long long ans;
inline void insert(int x) {
  int cur = 1;
  ++num[1];
  for (int i = 34; i >= 0; --i) {
    int v = (1 << i) <= x;
    if (v) x -= (1 << i);
    if (!son[cur][v]) son[cur][v] = ++cnt;
    cur = son[cur][v];
    ++num[cur];
  }
}
inline int query(int x) {
  int cur = 1, res = 0;
  int k = ::K;
  for (int i = 34; i >= 0; --i) {
    int p = (1 << i) <= k, v = (1 << i) <= x;
    if (v) x -= (1 << i);
    if (p) k -= (1 << i);
    if (!p) {
      if (son[cur][!v]) res += num[son[cur][!v]];
      if (son[cur][v])
        cur = son[cur][v];
      else {
        break;
      }
    } else if (son[cur][!v])
      cur = son[cur][!v];
    else
      break;
  }
  if (!son[cur][0] && !son[cur][1]) res += num[cur];
  return res;
}
int main() {
  N = read();
  K = read();
  insert(0);
  for (int i = 1; i <= N; i++) {
    sum ^= read();
    ans += query(sum);
    insert(sum);
  }
  cout << ans << endl;
  return 0;
}

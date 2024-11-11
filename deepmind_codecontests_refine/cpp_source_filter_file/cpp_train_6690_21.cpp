#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  char ch = getchar();
  long long x = 0, f = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while ('0' <= ch && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int fastmi(int i, int b, const int &p) {
  long long ans = 1, now = i;
  while (b) {
    if (b & 1) ans = now * ans % p;
    now = now * now % p;
    b >>= 1;
  }
  return ans;
}
int ra(int low, int hi) { return rand() % (hi - low + 1) + low; }
void assi() {
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);
}
bool flat;
const int N = 1e6 + 7;
int dep[N], n, m;
vector<int> si[N], now[N];
void dfs(int x) {
  if (dep[x] > (n + 1) / 2) {
    printf("PATH\n%d\n%d", dep[x], x);
    flat = 1;
    return;
  }
  now[dep[x]].push_back(x);
  for (int i = 0; i < si[x].size(); i++) {
    int p = si[x][i];
    if (dep[p] == 0) {
      dep[p] = dep[x] + 1;
      dfs(p);
      if (flat) {
        printf(" %d", x);
        return;
      }
    }
  }
}
int main() {
  int t = read();
  while (t--) {
    n = read();
    m = read();
    for (int i = 1; i <= m; i++) {
      int l = read(), r = read();
      si[l].push_back(r);
      si[r].push_back(l);
    }
    for (int i = 1; i <= m; i++)
      if (dep[i] == 0) {
        dep[i] = 1;
        dfs(i);
        if (flat) break;
      }
    if (flat)
      printf("\n");
    else {
      int ans = 0;
      for (int i = 1; i <= n; i++) ans += now[i].size() / 2;
      printf("PAIRING\n%d\n", ans);
      for (int i = 1; i <= n; i++)
        for (int j = 1; j < now[i].size(); j += 2)
          printf("%d %d\n", now[i][j - 1], now[i][j]);
    }
    flat = 0;
    for (int i = 1; i <= n; i++) {
      dep[i] = 0;
      si[i].clear();
      now[i].clear();
    }
  }
}

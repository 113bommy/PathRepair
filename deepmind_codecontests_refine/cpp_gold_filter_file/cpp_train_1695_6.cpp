#include <bits/stdc++.h>
using namespace std;
const int N = 4010;
const int P = 1000000007;
int h[N], nx[N << 2], t[N << 2], num;
int cnt[N];
int n, m;
int s;
int Ans;
int tot;
int f[N][N];
bool vis[N];
void Add(int x, int y) {
  t[++num] = y;
  nx[num] = h[x];
  h[x] = num;
}
void Dfs(int x) {
  vis[x] = 1;
  s++;
  for (int i = h[x]; i; i = nx[i])
    if (!vis[t[i]]) Dfs(t[i]);
}
int Abs(int x) { return x > 0 ? x : -x; }
void DP() {
  memset(f, 0, sizeof(f));
  int cur = 1;
  f[1][0] = 1;
  for (int i = 2; i <= n; i++)
    for (int j = 1; j <= cnt[i]; j++) {
      for (int k = 0; k <= n; k++)
        if (f[cur][k]) {
          int t = f[cur][k];
          f[cur + 1][k] = (f[cur + 1][k] + t) % P;
          f[cur + 1][k + i] = (f[cur + 1][k + i] + t) % P;
          int tmp = Abs(k - i);
          f[cur + 1][tmp] = (f[cur + 1][tmp] + t) % P;
        }
      cur++;
    }
}
void DP1() {
  memset(f, 0, sizeof(f));
  int cur = 0;
  f[0][0] = 1;
  for (int i = 2; i <= n; i++)
    for (int j = 1; j <= cnt[i]; j++) {
      for (int k = 0; k <= n; k++)
        if (f[cur][k]) {
          int t = f[cur][k];
          f[cur + 1][k + i] = (f[cur + 1][k + i] + t) % P;
          int tmp = Abs(k - i);
          f[cur + 1][tmp] = (f[cur + 1][tmp] + t) % P;
        }
      cur++;
    }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    Add(x, y);
    Add(y, x);
  }
  vis[1] = 1;
  for (int i = h[1]; i; i = nx[i])
    if (!vis[t[i]]) {
      s = 0;
      Dfs(t[i]);
      cnt[s + 1]++;
      tot++;
    }
  for (int i = 2; i <= n; i++)
    if (cnt[i]) {
      cnt[i]--;
      DP();
      int sum = 0;
      for (int j = 0; j < i - 1; j++) sum = (sum + f[tot][j]) % P;
      DP1();
      sum = (sum + f[tot - 1][i - 1]) % P;
      cnt[i]++;
      Ans = (Ans + 2ll * sum * cnt[i]) % P;
    }
  DP1();
  Ans = (Ans + f[tot][0]) % P;
  cout << Ans << endl;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int N = 200000;
const int M = 26;
struct AC {
  int t[N][M], fail[N], cnt[N], sz;
  void init() {
    sz = 1;
    memset(t[0], 0, sizeof(t[0]));
  }
  void add(char s[]) {
    int u = 0;
    for (int i = 0; s[i]; i++) {
      int &v = t[u][s[i] - 'a'];
      if (v == 0) {
        v = sz++;
        memset(t[v], 0, sizeof(t[v]));
        cnt[v] = 0;
      }
      u = v;
    }
    cnt[u]++;
  }
  void getfail() {
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (int i = 0; i < M; i++) {
        int v = t[u][i];
        if (v)
          fail[v] = (u != 0) * t[fail[u]][i], q.push(v), cnt[v] += cnt[fail[v]];
        else
          t[u][i] = t[fail[u]][i];
      }
    }
  }
};
char s[N], t[N];
long long f[N], g[N];
AC a, c;
int main() {
  a.init(), c.init();
  scanf("%s", t);
  int n;
  scanf("%d", &n);
  while (n--) {
    scanf("%s", s);
    a.add(s), reverse(s, s + strlen(s)), c.add(s);
  }
  a.getfail(), c.getfail();
  n = strlen(t);
  int u = 0;
  for (int i = 0; i < n; i++) u = a.t[u][t[i] - 'a'], f[i] = a.cnt[u];
  u = 0;
  for (int i = n - 1; i >= 0; i--) u = c.t[u][t[i] - 'a'], g[i] = c.cnt[u];
  long long ans = 0;
  for (int i = 1; i < n; i++) ans += f[i - 1] * g[i];
  printf("%lld\n", ans);
}

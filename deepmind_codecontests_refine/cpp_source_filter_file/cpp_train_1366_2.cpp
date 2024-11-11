#include <bits/stdc++.h>
const int N = 2e5 + 5;
int tr[N << 6][2], num[N][3], cnt, n;
std::vector<std::pair<long long, int> > g[3];
void init(int k) {
  tr[k][0] = tr[k][1] = 0;
  num[k][1] = num[k][0] = num[k][2] = 0;
}
bool insert(long long s, int len, int k) {
  int u = 0;
  if (num[u][0] != k && num[u][0]) return false;
  num[u][k]++;
  for (int i = 31; len; i--, len--) {
    int v = s >> i & 1;
    if (!tr[u][v]) {
      tr[u][v] = ++cnt;
      init(cnt);
    }
    u = tr[u][v];
    if (num[u][0] && num[u][0] != k) return false;
    num[u][k]++;
  }
  num[u][0] = k;
  if (num[u][3 - k]) return false;
  return true;
}
char s[N];
std::vector<std::pair<long long, int> > ans;
void dfs(int u, long long now = 0LL, int dep = 31) {
  if (dep < 0 || !num[u][2]) return;
  for (int i = 0; i < 2; i++)
    if (tr[u][i]) {
      int v = tr[u][i];
      if (num[v][1] && !num[v][2])
        ans.push_back(
            std::pair<long long, int>(now | (1LL * i) << dep, 32 - dep));
      else if (num[v][1])
        dfs(v, now | (1LL * i) << dep, dep - 1);
    }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%s", s);
    int t = (s[0] == '-' ? 1 : 2);
    bool f = 0;
    for (int i = 1; s[i]; i++)
      if (s[i] == '/') f = 1;
    long long a, b, c, d;
    int e;
    if (!f)
      e = 32, sscanf(s + 1, "%lld.%lld.%lld.%lld", &a, &b, &c, &d);
    else
      sscanf(s + 1, "%lld.%lld.%lld.%lld/%d", &a, &b, &c, &d, &e);
    g[t].push_back(
        std::pair<long long, int>(a << 24 | b << 16 | c << 8 | d, e));
  }
  for (std::pair<long long, int> v : g[2]) insert(v.first, v.second, 2);
  for (std::pair<long long, int> v : g[1])
    if (!insert(v.first, v.second, 1)) return !printf("-1");
  if (!num[0][2]) return !printf("1\n0.0.0.0/0");
  dfs(0);
  printf("%d\n", int(ans.size()));
  for (std::pair<long long, int> v : ans)
    printf("%lld.%lld.%lld.%lld/%d\n", v.first >> 24 & 255, v.first >> 16 & 255,
           v.first >> 8 & 255, v.first & 255, v.second);
  return 0;
}

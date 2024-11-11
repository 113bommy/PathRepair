#include <bits/stdc++.h>
using namespace std;
const int MAXSIZE = 10000020;
int bufpos;
char buf[MAXSIZE];
void init() {
  buf[fread(buf, 1, MAXSIZE, stdin)] = '\0';
  bufpos = 0;
}
int readint() {
  int val = 0;
  for (; !isdigit(buf[bufpos]); bufpos++)
    ;
  for (; isdigit(buf[bufpos]); bufpos++) val = val * 10 + buf[bufpos] - '0';
  return val;
}
char readchar() {
  for (; isspace(buf[bufpos]); bufpos++)
    ;
  return buf[bufpos++];
}
int readstr(char* s) {
  int cur = 0;
  for (; isspace(buf[bufpos]); bufpos++)
    ;
  for (; !isspace(buf[bufpos]); bufpos++) s[cur++] = buf[bufpos];
  s[cur] = '\0';
  return cur;
}
const int maxn = 200002;
vector<int> v[maxn], e[maxn];
int a[maxn], f[maxn], sz[maxn], fa[maxn];
void dfs(int u) {
  for (const auto& v : e[u]) {
    if (fa[u] == v) continue;
    fa[v] = u;
    dfs(v);
  }
}
bool label[maxn];
long long now;
int getf(int x) { return f[x] == x ? x : f[x] = getf(f[x]); }
void mer(int x, int y) {
  x = getf(x), y = getf(y);
  now += 1LL * sz[x] * sz[y];
  f[x] = y;
  sz[y] += sz[x];
}
long long ans[maxn];
int main() {
  init();
  int n = readint();
  for (int i = 1; i <= n; i++) f[i] = i, sz[i] = 1;
  for (int i = 1; i <= n; i++) a[i] = readint(), v[a[i]].push_back(i);
  for (int i = 1; i < n; i++) {
    int u = readint(), v = readint();
    e[u].push_back(v);
    e[v].push_back(u);
  }
  dfs(1);
  for (int i = 1; i <= 200000; i++) {
    now = 0;
    for (int j = i; j <= 200000; j += i)
      for (const auto& k : v[j]) {
        now++;
        if (fa[k] && a[fa[k]] % i == 0) mer(k, fa[k]);
      }
    ans[i] = now;
    for (int j = i; j <= 200000; j += i)
      for (const auto& k : v[j]) f[k] = k, sz[k] = 1;
  }
  for (int i = 200000; i; i--)
    for (int j = i * 2; j <= 200000; j += i) ans[i] -= ans[j];
  for (int i = 1; i <= 200000; i++)
    if (ans[i]) printf("%d %lld\n", i, ans[i]);
}

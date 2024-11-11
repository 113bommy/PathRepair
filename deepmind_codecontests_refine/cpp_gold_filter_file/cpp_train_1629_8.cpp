#include <bits/stdc++.h>
using namespace std;
const int N = 200100;
struct EDGE {
  int to, next;
} e[N * 2];
int first[N], n, tot, si[N], maxn[N], k;
long long ans[N];
bool did[N];
char s[N];
long long m[2000000];
vector<int> v;
void addedge(int x, int y) {
  e[tot].to = y;
  e[tot].next = first[x];
  first[x] = tot++;
  e[tot].to = x;
  e[tot].next = first[y];
  first[y] = tot++;
}
void dfs_size(int now, int fa) {
  si[now] = 1;
  maxn[now] = 0;
  for (int i = first[now]; i != -1; i = e[i].next)
    if (e[i].to != fa && !did[e[i].to]) {
      dfs_size(e[i].to, now);
      si[now] += si[e[i].to];
      maxn[now] = max(maxn[now], si[e[i].to]);
    }
}
void dfs_root(int now, int fa, int& root, int& nu, int t) {
  int MA = max(maxn[now], si[t] - si[now]);
  if (MA < nu) {
    nu = MA;
    root = now;
  }
  for (int i = first[now]; i != -1; i = e[i].next)
    if (e[i].to != fa && !did[e[i].to]) dfs_root(e[i].to, now, root, nu, t);
}
void dfs2(int now, int fa, int tlen) {
  for (int i = first[now]; i != -1; i = e[i].next)
    if (e[i].to != fa && !did[e[i].to])
      dfs2(e[i].to, now, tlen ^ (1 << (s[e[i].to] - 'a')));
  v.push_back(tlen);
}
long long dfs3(int now, int fa, int tlen, int root) {
  long long num = 0;
  for (int i = first[now]; i != -1; i = e[i].next)
    if (e[i].to != fa && !did[e[i].to]) {
      num += dfs3(e[i].to, now, tlen ^ (1 << (s[e[i].to] - 'a')), root);
    }
  ans[now] += num;
  for (int k = 0; k < 20; k++) {
    num += m[(1 << k) ^ tlen ^ (1 << (s[root] - 'a'))];
    ans[now] += m[(1 << k) ^ tlen ^ (1 << (s[root] - 'a'))];
  }
  num += m[tlen ^ (1 << (s[root] - 'a'))];
  ans[now] += m[tlen ^ (1 << (s[root] - 'a'))];
  return num;
}
long long dfs4(int now, int fa, int tlen, int root) {
  long long num = 0;
  for (int i = first[now]; i != -1; i = e[i].next)
    if (e[i].to != fa && !did[e[i].to]) {
      num += dfs4(e[i].to, now, tlen ^ (1 << (s[e[i].to] - 'a')), root);
    }
  if (__builtin_popcount(tlen ^ (1 << (s[root] - 'a'))) <= 1) num++;
  ans[now] += num;
  return num;
}
void solve(int now) {
  int root, nu = 1e9;
  dfs_size(now, -1);
  dfs_root(now, -1, root, nu, now);
  did[root] = true;
  for (int i = first[root]; i != -1; i = e[i].next) {
    if (!did[e[i].to]) {
      v.clear();
      dfs2(e[i].to, root, (1 << (s[e[i].to] - 'a')));
      for (int j = 0; j < v.size(); j++) m[v[j]]++;
    }
  }
  long long td = 0;
  for (int i = first[root]; i != -1; i = e[i].next) {
    if (!did[e[i].to]) {
      v.clear();
      dfs2(e[i].to, root, (1 << (s[e[i].to] - 'a')));
      for (int j = 0; j < v.size(); j++) m[v[j]]--;
      td += dfs3(e[i].to, root, (1 << (s[e[i].to] - 'a')), root);
      ans[root] += dfs4(e[i].to, root, (1 << (s[e[i].to] - 'a')), root);
      for (int j = 0; j < v.size(); j++) m[v[j]]++;
    }
  }
  ans[root] += td / 2;
  for (int i = first[root]; i != -1; i = e[i].next) {
    if (!did[e[i].to]) {
      v.clear();
      dfs2(e[i].to, root, (1 << (s[e[i].to] - 'a')));
      for (int j = 0; j < v.size(); j++) m[v[j]]--;
    }
  }
  for (int i = first[root]; i != -1; i = e[i].next)
    if (!did[e[i].to]) solve(e[i].to);
}
void init() {
  memset(first, -1, sizeof(first));
  tot = 0;
}
int main() {
  scanf("%d", &n);
  init();
  for (int i = 0, u, v; i < n - 1; i++) {
    scanf("%d%d", &u, &v);
    addedge(u, v);
  }
  scanf("%s", s + 1);
  solve(1);
  for (int i = 1; i <= n; i++) printf("%lld ", ans[i] + 1);
}

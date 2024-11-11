#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
const int M = 1e6 + 5;
struct edge {
  int a, b;
  int from, to, next, vis;
};
edge e[M];
int head[1 << 20];
int cnt;
void add(int a, int b, int from, int to) {
  e[cnt].a = a;
  e[cnt].b = b;
  e[cnt].from = from;
  e[cnt].to = to;
  e[cnt].next = head[from];
  e[cnt].vis = 0;
  head[from] = cnt;
  cnt++;
}
vector<pair<int, int> > ans;
void dfs(int now) {
  for (int &i = head[now]; i; i = e[i].next) {
    if (e[i].vis == 0) {
      e[i].vis = e[i ^ 1].vis = 1;
      pair<int, int> p = {e[i].a, e[i].b};
      dfs(e[i].to);
      ans.push_back(p);
    }
  }
}
int a[N], b[N], degree[1 << 20];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &a[i], &b[i]);
  }
  for (int i = 20; i >= 0; i--) {
    int mod = 1 << i;
    cnt = 2;
    ans.clear();
    for (int j = 1; j <= n; j++) {
      add(j * 2 - 1, j * 2, a[j] % mod, b[j] % mod);
      add(j * 2, j * 2 - 1, b[j] % mod, a[j] % mod);
      degree[a[j] % mod]++;
      degree[b[j] % mod]++;
    }
    int flag = 1;
    for (int j = 1; j <= n; j++) {
      if (degree[a[j] % mod] & 1) {
        flag = 0;
      } else if (degree[b[j] % mod] & 1) {
        flag = 0;
      }
    }
    if (!flag) {
      for (int j = 1; j <= n; j++) {
        head[a[j] % mod] = head[b[j] % mod] = degree[a[j] % mod] =
            degree[b[j] % mod] = 0;
      }
      continue;
    }
    dfs(e[2].from);
    for (int j = 2; j < cnt; j++) {
      if (e[j].vis == 0) flag = 0;
    }
    if (flag) {
      printf("%d\n", i);
      for (int j = 0; j < ans.size(); j++) {
        printf("%d %d ", ans[j].first, ans[j].second);
      }
      return 0;
    } else {
      for (int j = 1; j <= n; j++) {
        head[a[j] % mod] = head[b[j] % mod] = degree[a[j] % mod] =
            degree[b[j] % mod] = 0;
      }
    }
  }
}

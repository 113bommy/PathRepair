#include <bits/stdc++.h>
using namespace std;
const int MAX = 2000 + 10;
const int NUM = 600 + 10;
const int INF = 1000000000;
const int ALPHA = 27;
int n, K;
string a[MAX];
struct node {
  int ch[ALPHA], num, belong, size;
  node() {
    memset(ch, 0, sizeof ch);
    num = 1;
    size = 0;
  }
} tree[MAX * NUM];
int cnt, Root;
int tot, dp[MAX * 2][MAX];
void insert(string a) {
  int i, now = Root;
  for (i = 0; i < (int)a.size(); ++i) {
    int idx = a[i] - 'a';
    if (!tree[now].ch[idx]) tree[now].ch[idx] = ++cnt;
    now = tree[now].ch[idx];
  }
  ++tree[now].size;
  return;
}
void go(int now) {
  int i, num = 0, j, v;
  for (i = 0; i < ALPHA; ++i)
    if (tree[now].ch[i]) ++num;
  for (i = 0; i < ALPHA; ++i)
    if (tree[now].ch[i]) go(tree[now].ch[i]);
  if (num == 1)
    for (i = 0; i < ALPHA; ++i)
      if ((v = tree[now].ch[i]) && !tree[v].size) {
        tree[now].num += tree[v].num;
        for (j = 0; j < ALPHA; ++j) tree[now].ch[j] = tree[v].ch[j];
        break;
      }
}
void dfs(int u) {
  ++tot;
  tree[u].belong = tot;
  int i, j, a, b, v, k;
  if (tree[u].size) return;
  for (i = 0; i < ALPHA; ++i)
    if (tree[u].ch[i]) {
      dfs(tree[u].ch[i]);
      tree[u].size += tree[tree[u].ch[i]].size;
    }
  a = tree[u].belong;
  for (i = 0; i < ALPHA; ++i)
    if ((v = tree[u].ch[i])) {
      b = tree[v].belong;
      for (k = tree[u].size; k >= 0; --k)
        for (j = 0; j <= tree[v].size; ++j)
          if (k + j <= (int)tree[u].size)
            dp[a][k + j] = max(dp[a][k + j], dp[a][k] + dp[b][j]);
    }
  for (j = 0; j <= tree[u].size; ++j) dp[a][j] += j * (j - 1) / 2 * tree[u].num;
  return;
}
int main() {
  int i;
  cin >> n >> K;
  for (i = 1; i <= n; ++i) {
    cin >> a[i];
    a[i] += 'z' + 1;
    insert(a[i]);
  }
  sort(a + 1, a + n + 1);
  go(0);
  dfs(0);
  printf("%d\n", dp[1][K] - K * (K - 1) / 2);
  return 0;
}

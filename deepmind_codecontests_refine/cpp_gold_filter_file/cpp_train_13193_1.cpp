#include <bits/stdc++.h>
using namespace std;
const int N = 200000;
int miu[N + 5], prime[N + 5], pcnt;
bool not_prime[N + 5];
void shai() {
  miu[1] = 1;
  for (int i = 2; i <= N; i++) {
    if (!not_prime[i]) {
      pcnt++;
      prime[pcnt] = i;
      miu[i] = -1;
    }
    for (int j = 1; prime[j] * i <= N; j++) {
      not_prime[prime[j] * i] = 1;
      if (i % prime[j] == 0) {
        miu[prime[j] * i] = 0;
        break;
      }
      miu[prime[j] * i] = -miu[i];
    }
  }
}
int a[N + 5];
int cnt;
vector<int> val[N + 5];
vector<int> G[N + 5];
int good[N + 5];
int vis[N + 5];
long long h[N + 5];
long long ans[N + 5];
int q[N + 5];
int bfs(int x) {
  int head = 0;
  int tail = 0;
  q[tail++] = x;
  vis[x] = cnt;
  while (head < tail) {
    int z = q[head++];
    for (int i = 0, sz = G[z].size(); i < sz; i++) {
      int y = G[z][i];
      if (good[a[y]] == cnt && vis[y] < cnt) {
        vis[y] = cnt;
        q[tail++] = y;
      }
    }
  }
  return tail;
}
int main() {
  shai();
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    val[a[i]].push_back(i);
  }
  for (int i = 1; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    G[x].push_back(y);
    G[y].push_back(x);
  }
  for (int i = N; i > 0; i--) {
    cnt++;
    for (int j = i; j <= N; j += i) good[j] = cnt;
    for (int j = i; j <= N; j += i)
      for (int k = 0, sz = val[j].size(); k < sz; k++) {
        int x = val[j][k];
        if (vis[x] == cnt) continue;
        int z = bfs(x);
        h[i] += 1ll * z * (z + 1) / 2;
      }
    for (int j = i, k = 1; j <= N; j += i, k++) ans[i] += miu[k] * h[j];
  }
  for (int i = 1; i <= N; i++)
    if (ans[i] > 0) printf("%d %I64d\n", i, ans[i]);
}

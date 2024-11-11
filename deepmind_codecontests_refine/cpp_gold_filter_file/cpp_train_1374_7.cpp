#include <bits/stdc++.h>
using namespace std;
template <typename U, typename V>
void Min(U &a, const V &b) {
  if (a > b) a = b;
}
template <typename U, typename V>
void Max(U &a, const V &b) {
  if (a < b) a = b;
}
template <typename U, typename V>
void add(U &a, const V &b) {
  a = (a + b) % 1000000007;
}
template <typename U>
U gcd(U a, U b) {
  if (a == 0) return b;
  if (b == 0) return a;
  if (a >= b)
    return gcd(a % b, b);
  else
    return gcd(a, b % a);
}
int pow(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = 1LL * ans * a % 1000000007;
    a = 1LL * a * a % 1000000007;
    b >>= 1;
  }
  return ans;
}
int pow(int a, int b, int c) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = 1LL * ans * a % c;
    a = 1LL * a * a % c;
    b >>= 1;
  }
  return ans;
}
vector<int> g[1000005], rg[1000005];
int vis[1000005];
int main() {
  int T, i, j, k, m, n, ca = 0, K;
  scanf("%d", &T);
  for (int it = 0; it < T; it++) {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) rg[i].clear(), g[i].clear(), vis[i] = 0;
    for (int i = 0; i < m; i++) {
      scanf("%d%d", &j, &k);
      j--, k--;
      if (j != k) {
        g[j].push_back(k), vis[k]++;
        rg[k].push_back(j);
      }
    }
    if (n == 1) {
      puts("No");
      continue;
    }
    int first = -1;
    for (int i = 0; i < n; i++)
      if (vis[i] == 0) {
        first = i;
        break;
      }
    if (first != -1) {
      printf("Yes\n%d %d\n", n - 1, 1);
      for (int i = 0; i < n; i++)
        if (first != i) printf("%d ", i + 1);
      puts("");
      printf("%d\n", first + 1);
      continue;
    }
    for (int i = 0; i < n; i++) vis[i] = 0;
    queue<int> q;
    q.push(0);
    m = 0;
    vis[0] = 1;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      m++;
      for (auto &v : g[u]) {
        if (!vis[v]) vis[v] = 1, q.push(v);
      }
    }
    if (m < n) {
      printf("Yes\n%d %d\n", m, n - m);
      for (int i = 0; i < n; i++)
        if (vis[i]) printf("%d ", i + 1);
      puts("");
      for (int i = 0; i < n; i++)
        if (!vis[i]) printf("%d ", i + 1);
      puts("");
      continue;
    }
    for (int i = 0; i < n; i++) vis[i] = 0;
    q.push(0);
    vis[0] = 1;
    m = 0;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      m++;
      for (auto &v : rg[u]) {
        if (!vis[v]) vis[v] = 1, q.push(v);
      }
    }
    if (m == n) {
      puts("No");
      continue;
    }
    printf("Yes\n%d %d\n", n - m, m);
    for (int i = 0; i < n; i++)
      if (!vis[i]) printf("%d ", i + 1);
    puts("");
    for (int i = 0; i < n; i++)
      if (vis[i]) printf("%d ", i + 1);
    puts("");
  }
}

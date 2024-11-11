#include <bits/stdc++.h>
using namespace std;
template <class T1>
T1 GCD(T1 A, T1 B) {
  if (B == 0)
    return A;
  else
    return GCD(B, A % B);
}
template <class T2>
T2 mulmod(T2 a, T2 b) {
  T2 x = 0, y = a % 1000000007;
  while (b) {
    if (b % 2 == 1) {
      x = (x + y) % 1000000007;
    }
    y = (2 * y) % 1000000007;
    b = b / 2;
  }
  return x % 1000000007;
}
template <class T3>
T3 power(T3 a, T3 b) {
  T3 x = 1, y = a % 1000000007;
  while (b) {
    if (b % 2 == 1) {
      x = mulmod(x, y) % 1000000007;
    }
    y = mulmod(y, y) % 1000000007;
    b = b / 2;
  }
  return x % 1000000007;
}
template <class T4>
bool cmp(T4 x, T4 y) {
  return x > y ? 1 : 0;
}
std::vector<int> adj[2 * 100000 + 10];
long long int cnt[2 * 100000 + 10], sz[2 * 100000 + 10], mx[2 * 100000 + 10];
long long int a[2 * 100000 + 10];
int order[2 * 100000 + 10];
int nn = 1;
bool flag;
void dfs(int u, int p) {
  for (int i = 0; i < adj[u].size(); i++) {
    if (adj[u][i] == p) continue;
    dfs(adj[u][i], u);
    cnt[u] += cnt[adj[u][i]];
    sz[u] += sz[adj[u][i]];
  }
  cnt[u] += a[u];
  sz[u]++;
  order[nn] = u;
  nn++;
}
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int x, y;
  for (int i = 1; i < n; i++) {
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  dfs(1, 0);
  long long int ns = -1000000000000000;
  mx[1] = a[order[1]];
  for (int i = 2; i <= n; i++) {
    if (cnt[order[i]] > mx[i - 1])
      mx[i] = cnt[order[i]];
    else
      mx[i] = mx[i - 1];
  }
  for (int i = 2; i <= n; i++) {
    if ((i - sz[order[i]]) != 0) {
      flag = true;
      ns = max(ns, cnt[order[i]] + mx[i - sz[order[i]]]);
    }
  }
  if (!flag)
    cout << "Impossible";
  else
    cout << ns;
  return 0;
}

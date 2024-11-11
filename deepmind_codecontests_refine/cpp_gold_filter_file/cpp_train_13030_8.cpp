#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (!b) return a;
  return gcd(b, a % b);
}
long long int lcm(long long int a, long long int b) {
  return (a * b) / gcd(a, b);
}
template <typename T>
T pow(T a, T b, long long m) {
  T ans = 1;
  while (b > 0) {
    if (b % 2 == 1) ans = (ans * a) % m;
    b /= 2;
    a = (a * a) % m;
  }
  return ans % m;
}
vector<long long int> ar[200001];
long long int vis[200001], vis1[200001];
long long int in[200001], low[200001];
long long int timer;
long long int z = 0;
map<pair<long long int, long long int>, long long int> mp;
void dfsbridge(long long int x, long long int p) {
  vis[x] = 1;
  in[x] = timer;
  low[x] = timer;
  timer++;
  for (long long int ch : ar[x]) {
    if (ch == p) continue;
    if (vis[ch] == 0) {
      dfsbridge(ch, x);
      if (low[ch] > in[x]) {
        z = 1;
        break;
      }
      low[x] = min(low[x], low[ch]);
    } else {
      low[x] = min(low[x], in[ch]);
    }
  }
}
void dfs(long long int x, long long int p) {
  vis1[x] = 1;
  for (long long int ch : ar[x]) {
    if (ch == p) continue;
    if (vis1[ch] == 0) {
      printf("%lld %lld\n", x, ch);
      dfs(ch, x);
    } else if (mp[{ch, x}] == 0 && mp[{x, ch}] == 0) {
      printf("%lld %lld\n", x, ch);
      mp[{ch, x}] = 1;
    }
  }
}
int main() {
  long long int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    long long int u, v;
    cin >> u >> v;
    ar[u].push_back(v);
    ar[v].push_back(u);
  }
  dfsbridge(1, -1);
  if (z == 1)
    printf("0\n");
  else {
    dfs(1, -1);
  }
}

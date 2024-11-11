#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;
int n, m, p;
long long a[600000];
int u[600000];
vector<int> edge[600000];
map<long long, vector<pair<int, int>>> mq;
long long two[600000];
int find(int x) { return u[x] == x ? x : u[x] = find(u[x]); }
int main() {
  int i, j, k, l;
  cin >> n >> m >> p;
  two[0] = 1;
  for (i = 1; i <= 500000; i++) two[i] = two[i - 1] * 2 % 1000000007;
  for (i = 0; i < n; i++) scanf("%lld", &a[i]);
  for (i = 0; i < m; i++) {
    int x, y;
    scanf("%d%d", &x, &y), x--, y--;
    long long u = a[x] ^ a[y];
    mq[u].emplace_back(x, y);
  }
  for (i = 0; i < n; i++) u[i] = i;
  long long ans = 0;
  for (auto e : mq) {
    set<int> vs;
    int cnt = 0;
    for (auto f : e.second) {
      vs.insert(f.first);
      vs.insert(f.second);
      if (find(f.first) != find(f.second)) {
        cnt--;
        u[find(f.first)] = find(f.second);
      }
    }
    cnt += vs.size();
    ans += two[n - vs.size()] * two[cnt];
    ans %= 1000000007;
    ans = (ans + 1000000007) % 1000000007;
    for (auto f : e.second) {
      u[f.first] = f.first;
      u[f.second] = f.second;
    }
  }
  ans += (two[p] - mq.size()) * two[n] % 1000000007;
  ans = (ans + 1000000007) % 1000000007;
  cout << ans << endl;
  return 0;
}

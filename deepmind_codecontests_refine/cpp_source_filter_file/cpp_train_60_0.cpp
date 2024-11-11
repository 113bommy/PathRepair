#include <bits/stdc++.h>
const double Pi = acos(-1.0);
using namespace std;
const int maxN = 100005;
const long long inf = (long long)1e18;
int n;
long long b[maxN];
long long k[maxN];
long long req[maxN];
vector<int> G[maxN];
void dfs(int cur) {
  for (int i = 0; i < (int)G[cur].size(); i++) {
    int nxt = G[cur][i];
    dfs(nxt);
    if (req[nxt] < 0) {
      if (inf / k[nxt] < -req[nxt]) {
        puts("NO");
        exit(0);
      }
      req[cur] += k[nxt] * req[nxt];
    } else
      req[cur] += req[nxt];
  }
}
int main(int argc, char** argv) {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%lld", &b[i]);
  long long a;
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a);
    req[i] = b[i] - a;
  }
  int x;
  for (int i = 2; i <= n; i++) {
    scanf("%d %lld", &x, &k[i]);
    G[x].push_back(i);
  }
  dfs(1);
  puts((req[1] < 0) ? "NO" : "YES");
  return 0;
}

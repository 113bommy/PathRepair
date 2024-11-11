#include <bits/stdc++.h>
using namespace std;
long double ans;
long long n, depth[100010];
vector<long long> edge[100010];
inline long long read() {
  long long x = 0, tmp = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') tmp = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = (x << 3) + (x << 1) + ch - 48;
    ch = getchar();
  }
  return tmp * x;
}
void dfs(long long m, long long before) {
  depth[m] = depth[before] + 1;
  for (long long i = 0; i < edge[m].size(); i++) {
    long long Next = edge[m][i];
    if (Next == before) continue;
    dfs(Next, m);
  }
}
int main() {
  n = read();
  for (long long i = 1; i < n; i++) {
    long long x = read(), y = read();
    edge[x].push_back(y);
    edge[y].push_back(x);
  }
  dfs(1, 0);
  for (long long i = 1; i <= n; i++) ans += 1.0 / depth[i];
  printf("%.10Lf\n", ans);
  return 0;
}

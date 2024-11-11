#include <bits/stdc++.h>
using namespace std;
const long maxn = 105;
long cht;
vector<long> edges[maxn];
long n, m;
long mark[maxn];
void dfs(long u, long pred) {
  mark[u] = 1;
  if (edges[u].size() != 0) {
    for (long choice = 0; choice < edges[u].size(); choice++) {
      long next = edges[u][choice];
      if ((mark[next] == 1) && (next != pred)) cht++;
      if (mark[next] == 0) dfs(next, u);
    }
  }
}
int main() {
  scanf("%ld%ld", &n, &m);
  long q;
  for (q = 1; q <= n; q++) edges[q].resize(0);
  for (q = 1; q <= m; q++) {
    long t1, t2;
    scanf("%ld%ld", &t1, &t2);
    edges[t1].push_back(t2);
    edges[t2].push_back(t1);
  }
  cht = 0;
  for (q = 1; q <= n; q++) mark[q] = 0;
  long count = 0;
  for (q = 1; q <= n; q++)
    if (mark[q] == 0) {
      dfs(q, -1);
      count++;
    }
  cht = cht / 2;
  if ((cht != 1) || (count > 1))
    printf("NO");
  else
    printf("FHTAGN!");
}

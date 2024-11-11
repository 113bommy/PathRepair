#include <bits/stdc++.h>
using namespace std;
long long int n, number[100002], coun, cnodes[100002];
vector<pair<long long int, long long int> > graph[100002];
long long int cn(long long int node) {
  long long int i, cnt = 1, j;
  for (i = 0; i < graph[node].size(); i++) {
    j = graph[node][i].first;
    cnt += cn(j);
  }
  cnodes[node] = cnt;
  return cnt;
}
void dfs(long long int node, long long int cnt) {
  long long int i, j, c;
  if (cnt > number[node])
    coun += cnodes[node];
  else {
    for (i = 0; i < graph[node].size(); i++) {
      j = graph[node][i].first;
      c = graph[node][i].second;
      dfs(j, max(cnt + c, c));
    }
  }
}
int main() {
  long long int i, a, b, c;
  scanf("%lld", &n);
  for (i = 0; i < n; i++) scanf("%lld", &number[i]);
  for (i = 0; i < n - 1; i++) {
    scanf("%lld", &a);
    scanf("%lld", &b);
    a--;
    graph[a].push_back(make_pair(i + 1, b));
  }
  coun = 0;
  cn(0);
  dfs(0, 0);
  printf("%lld\n", coun);
  return 0;
}

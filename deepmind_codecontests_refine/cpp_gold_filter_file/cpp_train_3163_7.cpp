#include <bits/stdc++.h>
using namespace std;
vector<int> L[100100];
long long v[100100];
pair<long long, long long> dfs(int x, int p) {
  pair<long long, long long> ret(0, 0);
  for (vector<int>::iterator it = L[x].begin(); it < L[x].end(); it++)
    if (*it != p) {
      pair<long long, long long> k = dfs(*it, x);
      ret.first = max(ret.first, k.first);
      ret.second = max(ret.second, k.second);
    }
  v[x] += ret.first - ret.second;
  if (v[x] > 0) ret.second += v[x];
  if (v[x] < 0) ret.first -= v[x];
  return ret;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    a--, b--;
    L[a].push_back(b);
    L[b].push_back(a);
  }
  for (int i = 0; i < n; i++) scanf("%I64d", v + i);
  pair<long long, long long> k = dfs(0, 0);
  printf("%I64d\n", k.first + k.second);
}

#include <bits/stdc++.h>
using namespace std;
vector<int> v[300010];
vector<pair<int, unsigned long long> > ope[300010];
int n;
unsigned long long c[300010];
unsigned long long ans[300010];
int lowbit(int x) { return x & (-x); }
unsigned long long query(int x) {
  unsigned long long res = 0;
  while (x) {
    res += c[x];
    x -= lowbit(x);
  }
  return res;
}
void add(int x, unsigned long long v) {
  while (x <= n) {
    c[x] += v;
    x += lowbit(x);
  }
}
void dfs(int id, int fa, int dep) {
  int len1 = ope[id].size();
  for (int i = 0; i < len1; i++) {
    pair<int, unsigned long long> temp = ope[id][i];
    int d = temp.first;
    unsigned long long x = temp.second;
    add(dep, x);
    add(min(dep + d + 1, n), -x);
  }
  ans[id] = query(dep);
  int len2 = v[id].size();
  for (int i = 0; i < len2; i++) {
    int temp = v[id][i];
    if (temp == fa) continue;
    dfs(temp, id, dep + 1);
  }
  for (int i = 0; i < len1; i++) {
    pair<int, unsigned long long> temp = ope[id][i];
    int d = temp.first;
    unsigned long long x = temp.second;
    add(dep, -x);
    add(min(dep + d + 1, n), x);
  }
}
int main() {
  int m, x, y;
  unsigned long long z;
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++) {
    scanf("%d%d", &x, &y);
    v[x].push_back(y);
    v[y].push_back(x);
  }
  scanf("%d", &m);
  while (m--) {
    scanf("%d%d%lld", &x, &y, &z);
    ope[x].push_back(make_pair(y, z));
  }
  dfs(1, 1, 1);
  for (int i = 1; i <= n; i++) printf("%lld ", ans[i]);
  printf("\n");
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int N = 100100;
bool did[N];
int to[N], n;
vector<int> v;
void dfs(int x, int sz) {
  did[x] = true;
  if (!did[to[x]])
    dfs(to[x], sz + 1);
  else {
    v.push_back(sz);
    return;
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &to[i]);
  for (int i = 1; i <= n; i++)
    if (!did[i]) dfs(i, 1);
  sort(v.begin(), v.end());
  long long ans = 0;
  if (v.size() >= 2) {
    ans += 1ll * (v[v.size() - 1] + v[v.size() - 2]) *
           (v[v.size() - 1] + v[v.size() - 2]);
    for (int i = 0; i < v.size() - 2; i++) ans += 1ll * v[i] * v[i];
  } else {
    for (int i = 0; i < v.size(); i++) ans += 1ll * v[i] * v[i];
  }
  printf("%lld\n", ans);
}

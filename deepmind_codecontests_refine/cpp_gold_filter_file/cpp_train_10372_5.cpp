#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, p[N];
vector<long long> v;
bool vis[N];
int main() {
  memset(vis, 0, sizeof(vis));
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", p + i);
  for (int i = 1; i <= n; i++) {
    long long cnt = 1;
    if (vis[i]) continue;
    vis[i] = 1;
    int x = p[i];
    while (x != i) {
      vis[x] = 1;
      x = p[x];
      cnt++;
    }
    v.push_back(cnt);
  }
  if (v.size() >= 2) {
    sort(v.begin(), v.end());
    long long ans = v[v.size() - 1] + v[v.size() - 2];
    ans = ans * ans;
    for (int i = 0; i < v.size() - 2; i++) {
      ans += v[i] * v[i];
    }
    printf("%I64d\n", ans);
  } else {
    printf("%I64d\n", v[0] * v[0]);
  }
  return 0;
}

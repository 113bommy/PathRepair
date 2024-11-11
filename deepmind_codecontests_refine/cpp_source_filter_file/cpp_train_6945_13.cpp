#include <bits/stdc++.h>
int x[200010], check[200010];
long long int ans[200010];
long long int size[200010];
int next[200010];
int find(int k) {
  if (next[k] == k)
    return k;
  else
    return next[k] = find(next[k]);
}
std::vector<int> V[200010];
int height[200010];
long long int func(int k, int prev, int h) {
  height[k] = h;
  long long int ans = x[k];
  for (int i = 0; i < V[k].size(); i++) {
    if (V[k][i] == prev) continue;
    ans += func(V[k][i], k, h + 1);
  }
  return size[k] = ans;
}
std::pair<int, int> edge[200010];
int main() {
  int a;
  scanf("%d", &a);
  for (int i = 1; i <= a; i++) scanf("%d", &x[i]);
  for (int i = 1; i <= a; i++) next[i] = i;
  int b;
  scanf("%d", &b);
  for (int i = 1; i <= b; i++) {
    int c, d;
    scanf("%d%d", &c, &d);
    edge[i] = std::make_pair(c, d);
    if (find(c) == find(d))
      check[i] = 1, ans[i] = 0;
    else {
      V[c].push_back(d);
      V[d].push_back(c);
      next[find(c)] = find(d);
    }
  }
  func(1, 0, 1);
  long long int sum = 0;
  for (int i = 1; i <= a; i++) sum += x[i];
  if (sum != 0) {
    printf("Impossible");
    return 0;
  }
  for (int i = 1; i <= b; i++) {
    if (check[i] == 0) {
      long long int s, t;
      int c = edge[i].first;
      int d = edge[i].second;
      if (height[d] < height[c])
        ans[i] = size[c];
      else
        ans[i] = -size[d];
    }
  }
  printf("Possible\n");
  for (int i = 1; i <= b; i++) printf("%lld\n", ans[i]);
}

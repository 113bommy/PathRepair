#include <bits/stdc++.h>
int root[2][200001];
int weight[2][200001];
int mark[2][200001];
int getRoot(int a, int type) {
  int result = 0;
  result = root[type][a];
  while (result != root[type][result]) result = root[type][result];
  root[type][a] = result;
  return result;
}
void connect(int a, int b, int type) {
  int ra = getRoot(a, type);
  int rb = getRoot(b, type);
  if (weight[type][ra] >= weight[type][rb]) {
    root[type][rb] = ra;
    weight[type][ra] += weight[type][rb];
  } else {
    root[type][ra] = rb;
    weight[type][rb] += weight[type][ra];
  }
}
int main() {
  long long ans = 0;
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 2; j++) {
      root[j][i] = i;
      weight[j][i] = 1;
    }
  }
  for (int i = 1; i < n; i++) {
    int from, to, type;
    scanf("%d%d%d", &from, &to, &type);
    connect(from, to, type);
  }
  for (int i = 1; i <= n; i++) {
    for (int type = 0; type < 2; type++) {
      if (!mark[type][getRoot(i, type)]) {
        int root = getRoot(i, type);
        mark[type][getRoot(i, type)] = 1;
        ans += weight[type][root] * (weight[type][root] - 1);
      }
    }
    ans += (weight[0][getRoot(i, 0)] - 1) * (weight[1][getRoot(i, 1)] - 1);
  }
  printf("%lld\n", ans);
}

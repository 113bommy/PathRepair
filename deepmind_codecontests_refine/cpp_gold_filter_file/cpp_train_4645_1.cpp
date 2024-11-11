#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 100;
int n, father[N], f[31][N], l[N], now, mx, lg[N], er[31], d1, d2;
vector<int> v1, v2;
int getLCA(int x, int y) {
  int u = x, v = y, k;
  if (l[u] > l[v]) swap(u, v);
  k = lg[l[v] - l[u]] + 1;
  while (k >= 0) {
    if (l[v] - er[k] >= l[u]) v = father[f[k][v]];
    k--;
  }
  k = lg[l[u]] + 1;
  while (k >= 0) {
    if (f[k][u] != f[k][v]) {
      u = father[f[k][u]];
      v = father[f[k][v]];
    }
    k--;
  }
  return u;
}
int main() {
  er[0] = 1;
  lg[0] = -1;
  for (int i = 1; i <= 3e5; i++) lg[i] = lg[i / 2] + 1;
  for (int i = 1; i <= 30; i++) er[i] = er[i - 1] * 2;
  scanf("%d", &n);
  father[1] = 1;
  f[0][1] = 1;
  v1.push_back(1);
  for (int i = 2; i <= n + 1; i++) {
    scanf("%d", &now);
    l[i] = l[now] + 1;
    father[i] = now;
    f[0][i] = i;
    for (int j = 1; j <= 30; j++) f[j][i] = f[j - 1][father[f[j - 1][i]]];
    if (!v1.empty()) d1 = l[i] + l[v1[0]] - 2 * l[getLCA(i, v1[0])];
    if (!v2.empty()) d2 = l[i] + l[v2[0]] - 2 * l[getLCA(i, v2[0])];
    if (d1 > mx || d2 > mx) {
      mx = max(d1, d2);
      if (mx == d1) {
        for (int j = 0; j < v2.size(); j++)
          if (l[i] + l[v2[j]] - 2 * l[getLCA(i, v2[j])] == mx)
            v1.push_back(v2[j]);
        v2.clear();
        v2.push_back(i);
      } else {
        for (int j = 0; j < v1.size(); j++)
          if (l[i] + l[v1[j]] - 2 * l[getLCA(i, v1[j])] == mx)
            v2.push_back(v1[j]);
        v1.clear();
        v1.push_back(i);
      }
    } else if (d1 == mx || d2 == mx) {
      if (d1 == mx)
        v2.push_back(i);
      else
        v1.push_back(i);
    }
    printf("%d\n", v1.size() + v2.size());
  }
  return 0;
}

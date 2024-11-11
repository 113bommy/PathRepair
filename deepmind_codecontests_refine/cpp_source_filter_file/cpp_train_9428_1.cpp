#include <bits/stdc++.h>
using namespace std;
int as[100001];
int bs[100001];
int vs[100001][2];
int foods[100001];
void dfs(int cur, int f) {
  foods[cur] = f;
  if (!foods[vs[cur][0]]) dfs(vs[cur][0], f ^ 3);
  if (!foods[vs[cur][1]]) dfs(vs[cur][1], f ^ 3);
}
int main() {
  memset(foods, 0, sizeof(foods));
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", as + i, bs + i);
    vs[as[i]][0] = bs[i];
    vs[bs[i]][0] = as[i];
  }
  for (int i = 1; i <= 2 * n; i += 2) {
    vs[i][1] = i + 1;
    vs[i + 1][1] = i;
  }
  for (int i = 1; i <= 2 * n; ++i) {
    if (!foods[i]) dfs(i, 1);
  }
  for (int i = 0; i < n; ++i) {
    cout << foods[as[i]] << " " << foods[bs[i]] << endl;
  }
}

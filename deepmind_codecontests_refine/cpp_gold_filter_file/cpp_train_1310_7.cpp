#include <bits/stdc++.h>
using namespace std;
int n, m, i;
long long res, k;
int x[1000100], y[1000100], a[1000100];
bool c[1000100];
vector<int> b[1000100];
void dfs(int x) {
  c[x] = false;
  for (int i = 0; i < b[x].size(); i++)
    if (c[b[x][i]]) dfs(b[x][i]);
}
int main() {
  scanf("%d %d", &n, &m);
  k = 0;
  for (i = 1; i <= m; i++) {
    scanf("%d %d", &x[i], &y[i]);
    if (x[i] == y[i])
      k++;
    else {
      a[x[i]]++;
      a[y[i]]++;
      b[x[i]].push_back(y[i]);
      b[y[i]].push_back(x[i]);
    }
  }
  memset(c, true, sizeof(c));
  dfs(x[1]);
  for (i = 1; i <= m; i++)
    if (c[x[i]] == true) {
      printf("0");
      return 0;
    }
  for (i = 1; i <= m; i++)
    if (x[i] != y[i]) res += (a[x[i]] - 1) + (a[y[i]] - 1);
  res = res / 2;
  res += k * (k - 1) / 2;
  res += (m - k) * k;
  printf("%lld", res);
}

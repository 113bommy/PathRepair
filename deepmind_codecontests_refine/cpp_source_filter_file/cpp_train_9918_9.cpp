#include <bits/stdc++.h>
using namespace std;
int b[501000];
int f[1010000];
vector<int> g[1001000];
void dfs(int x, int id) {
  f[x] = id + 1;
  for (auto i : g[x]) {
    if (!f[i]) dfs(i, id ^ 1);
  }
}
int main() {
  int n, x;
  scanf("%d", &n);
  if (n % 2 == 0) {
    printf("First\n");
    for (int i = 1; i <= n; i++) printf("%d ", i);
    for (int i = 1; i <= n; i++) printf("%d ", i);
    printf("\n");
    fflush(stdout);
    scanf("%d", &x);
    return 0;
  }
  printf("Second\n");
  fflush(stdout);
  for (int i = 1; i <= 2 * n; i++) {
    scanf("%d", &x);
    if (b[x])
      g[x].push_back(b[x]), g[b[x]].push_back(x);
    else
      b[x] = i;
  }
  for (int i = 1; i <= n; i++) g[i].push_back(i + n), g[i + n].push_back(i);
  for (int i = 1; i <= 2 * n; i++)
    if (!f[i]) dfs(i, 0);
  long long sum = 0, ok = 1;
  for (int i = 1; i <= 2 * n; i++)
    if (f[i]) sum += i;
  if (sum % (2 * n)) ok = 2;
  for (int i = 1; i <= 2 * n; i++)
    if (f[i] == ok) printf("%d ", i);
  printf("\n");
  fflush(stdout);
  scanf("%d", &x);
}

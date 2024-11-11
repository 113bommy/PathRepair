#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e6 + 5;
int A[MAXN + 5];
bool vis[MAXN + 5];
int n;
int dfs(int now) {
  int sum = 0;
  while (!vis[now]) {
    vis[now] = true;
    sum++;
    now = A[now];
  }
  return sum - 1;
}
int main() {
  memset(vis, false, sizeof(vis));
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
  int sum = 0;
  for (int i = 1; i <= n; i++)
    if (!vis[i]) sum += dfs(i);
  int check = 0;
  if (n % 2 == 0) {
    if (sum % 2 == 0)
      check = 1;
    else
      check = 2;
  } else {
    if (sum % 2 == 0)
      check = 2;
    else
      check = 1;
  }
  if (check == 1)
    printf("Petr\n");
  else
    printf("Um_nik\n");
}

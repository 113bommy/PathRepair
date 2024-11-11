#include <bits/stdc++.h>
using namespace std;
int A[1000 + 10], B[1000 + 10];
bool vis[1000 + 10];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", A + i);
  A[0] = -1;
  for (int i = 1; i <= n; i++) scanf("%d", B + i);
  B[0] = -2;
  vector<int> ID;
  for (int i = 1; i <= n; i++)
    if (A[i] != B[i]) ID.push_back(i);
  if (!ID.size()) ID.push_back(0);
  if (ID.size() == 1) ID.push_back(0);
  swap(A[ID[0]], B[ID[0]]);
  bool flag = 1;
  memset(vis, 0, sizeof(vis));
  for (int i = 1; i <= n; i++) {
    if (vis[A[i]]) {
      flag = 0;
      break;
    }
    vis[A[i]] = 1;
  }
  if (!flag) swap(A[ID[0]], B[ID[0]]), swap(A[ID[1]], B[ID[1]]);
  flag = 1;
  int id = 0;
  memset(vis, 0, sizeof(vis));
  for (int i = 1; i <= n; i++) {
    if (A[i] != B[i]) {
      flag = 0;
      id = i;
    }
    vis[A[i]] = 1;
  }
  if (!flag) {
    for (int i = 1; i <= n; i++)
      if (!vis[i]) A[id] = i;
  }
  for (int i = 1; i <= n; i++) printf("%d ", A[i]);
  return 0;
}

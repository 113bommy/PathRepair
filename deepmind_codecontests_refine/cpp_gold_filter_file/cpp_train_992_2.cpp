#include <bits/stdc++.h>
using LL = long long;
const int N = 200000 + 5;
int A[N], n;
int vis[N], tim;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", A + i);
  }
  std::vector<int> bad;
  for (int i = 1; i <= n; ++i) {
    if (vis[i] == 0) {
      tim++;
      for (int u = i;; u = A[u]) {
        vis[u] = tim;
        if (vis[A[u]] == tim) {
          bad.emplace_back(u);
          break;
        } else if (vis[A[u]]) {
          break;
        }
      }
    }
  }
  for (int i = 0; i < (int)bad.size(); ++i) {
    if (A[bad[i]] == bad[i]) {
      std::rotate(bad.begin(), bad.begin() + i, bad.end());
      break;
    }
  }
  int cost = (int)bad.size() - (A[bad[0]] == bad[0]);
  for (int x : bad) A[x] = bad[0];
  printf("%d\n", cost);
  for (int i = 1; i <= n; ++i) {
    printf("%d%c", A[i], " \n"[i == n]);
  }
}

#include <bits/stdc++.h>
using namespace std;
int G[100010];
int R[100010];
const int MAX = 100000;
set<int> si;
void init() {
  G[0] = R[0] = 0;
  for (int i = 1; i <= MAX; i++) {
    si.clear();
    int sum = 0;
    for (int t = 2;; t++) {
      sum += t - 1;
      if (sum >= i) break;
      if ((i - sum) % t == 0) {
        int x = (i - sum) / t;
        int nx = x + t - 1;
        si.insert(R[nx] ^ R[x - 1]);
      }
    }
    int ret = 0;
    while (si.find(ret) != si.end()) ret++;
    G[i] = ret;
    R[i] = G[i] ^ R[i - 1];
  }
}
int main() {
  init();
  while (true) {
    int n;
    int take = scanf("%d", &n);
    if (take == -1) break;
    if (G[n] == 0) {
      puts("-1");
    } else {
      int ans = -1;
      int sum = 0;
      for (int t = 2;; t++) {
        sum += (t - 1);
        if (sum >= n) break;
        if ((n - sum) % t == 0) {
          int x = (n - sum) / t;
          if (x <= 0) continue;
          int nx = x + t - 1;
          if (R[nx] ^ R[x - 1] == 0) {
            ans = t;
            break;
          }
        }
      }
      assert(ans >= 2);
      printf("%d\n", ans);
    }
  }
  return 0;
}

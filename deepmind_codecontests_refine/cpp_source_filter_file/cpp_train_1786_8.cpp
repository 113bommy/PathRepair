#include <bits/stdc++.h>
using namespace std;
int n, k;
int main() {
  int t = 1;
  scanf("%d %d", &n, &k);
  vector<bool> used(n, 0);
  int res = (n - 1) * 3;
  vector<bool> used1(3 * (n - 1), 0);
  for (int i = 0; i < k; i++) {
    int v;
    scanf("%d", &v);
    v--;
    used[v] = true;
    if (v && used[v - 1]) {
      res -= 1 - used1[3 * v - 1];
      used1[3 * v - 1] = true;
    }
    if (v < n - 1 && used[v + 1]) {
      res -= 1 - used1[3 * v + 1];
      used1[3 * v + 1] = true;
    }
    if (used[v]) {
      res -= 1 - used1[3 * v];
      used1[3 * v] = true;
    }
  }
  printf("%d", res);
  return 0;
}

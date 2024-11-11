#include <bits/stdc++.h>
using namespace std;
const int maxn = 10000;
int degree[maxn + 5];
int Cn_i(int n, int i) {
  int up = 1;
  int down = 1;
  for (int t = n; t >= n - i + 1; t--) {
    up = up * t;
  }
  for (int t = i; t >= 1; t--) {
    down = down * t;
  }
  return up / down;
}
int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    for (int i = 0; i < n; i++) degree[i] = 0;
    for (int i = 0; i < n - 1; i++) {
      int a, b;
      scanf("%d%d", &a, &b);
      degree[a]++;
      degree[b]++;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (degree[i] >= 2) {
        ans += Cn_i(degree[i], 2);
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}

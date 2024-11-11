#include <bits/stdc++.h>
const int MAX_N = 510;
int g[MAX_N * MAX_N];
int a[MAX_N];
int gcd(int a, int b) {
  while (b != 0) {
    int t = a % b;
    a = b;
    b = t;
  }
  return a;
}
int main() {
  int n;
  scanf("%d", &n);
  std::map<int, int> used;
  for (int i = 0; i < n * n; ++i) {
    scanf("%d", &g[i]);
    ++used[g[i]];
  }
  std::sort(g, g + n * n);
  int last = n * n - 1;
  for (int i = 0; i < n; ++i) {
    while (last >= 0) {
      if (used[g[last]] > 0) {
        printf("%d ", g[last]);
        a[i] = g[last];
        --used[g[last]];
        for (int j = 0; j < i; ++j) {
          used[gcd(g[last], a[j])] -= 2;
        }
        --last;
        break;
      }
      --last;
    }
  }
  return 0;
}

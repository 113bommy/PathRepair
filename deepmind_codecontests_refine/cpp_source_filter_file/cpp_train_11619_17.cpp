#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, l, r, x;
  int e[10000 + 10];
  cin >> n >> m;
  for (int i = 0; i < n; i++) scanf("%d", &e[i]);
  for (int i = 0; i < m; i++) {
    scanf("%d %d %d", &l, &r, &x);
    int c = 0;
    int k = x - l + 1;
    while (l <= r) {
      if (e[l - 1] <= e[x - 1]) c++;
      l++;
    }
    if (c == k)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}

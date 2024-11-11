#include <bits/stdc++.h>
using namespace std;
int t[110], w[110];
int main() {
  int n, cnt = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d%d", &t[i], &w[i]);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i != j) {
        if (t[i] == w[j]) {
          cnt++;
          break;
        }
      }
    }
  }
  printf("%d", n - cnt);
  return 0;
}

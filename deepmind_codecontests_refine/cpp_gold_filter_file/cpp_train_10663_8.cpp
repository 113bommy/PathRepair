#include <bits/stdc++.h>
using namespace std;
int main() {
  int s = 1e6;
  vector<bool> b(s + 1);
  int n, t;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &t);
    b[t] = true;
  }
  printf("%d\n", n);
  int hs = s / 2;
  int left = 0;
  for (int i = 1; i <= hs; ++i) {
    int j = s - i + 1;
    if (b[i] && b[j])
      ++left;
    else if (b[i] && !b[j])
      printf("%d ", j);
    else if (!b[i] && b[j]) {
      b[i] = true;
      printf("%d ", i);
    }
  }
  for (int i = 1; i <= hs && left > 0; ++i) {
    if (b[i]) continue;
    int j = s - i + 1;
    printf("%d %d ", i, j);
    --left;
  }
  return 0;
}

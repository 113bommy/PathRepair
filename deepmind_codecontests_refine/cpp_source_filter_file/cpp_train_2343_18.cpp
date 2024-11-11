#include <bits/stdc++.h>
using namespace std;
int w[1000010], b[1000010];
int main() {
  int n, i, j = 0, ans = 0;
  for (i = 0; i < 1000011; i++) b[i] = 0;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &w[i]);
    b[w[i]]++;
  }
  for (i = 0; i < 1000010; i++) {
    if (b[i] > 1) {
      b[i + 1] += (b[i] / 2);
      b[i] = b[i] % 2;
    }
  }
  for (i = 0; i < 1000011; i++) ans += b[i];
  printf("%d", ans);
  return 0;
}

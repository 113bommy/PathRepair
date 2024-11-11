#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  int maxsum = -2e9;
  int maxdif = -2e9;
  int minsum = 2e9;
  int mindif = 2e9;
  int c;
  scanf("%d", &c);
  for (int i = 0; i < c; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    maxsum = max(maxsum, x + y);
    maxdif = max(maxdif, x - y);
    minsum = min(minsum, x + y);
    mindif = min(mindif, x - y);
  }
  int ind = -1, best = 2e9;
  int h;
  scanf("%d", &h);
  for (int i = 0; i < h; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    int sum = x + y;
    int dif = x - y;
    int d1 = abs(maxsum - sum);
    int d2 = abs(minsum - sum);
    int d3 = abs(maxdif - dif);
    int d4 = abs(mindif - dif);
    int k = max(max(d1, d2), max(d3, d4));
    if (k < best) {
      best = k;
      ind = i;
    }
  }
  printf("%d\n%d\n", best, ind + 1);
}

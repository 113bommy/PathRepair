#include <bits/stdc++.h>
using namespace std;
int num = 0;
int ou[2000100];
int le[2000100];
bool vis[2000100];
void init() {
  memset(vis, 0, sizeof(vis));
  vis[1] = 1;
  int m = (int)sqrt(2000100 + 0.5);
  for (int i = 2; i <= m; i++) {
    if (!vis[i])
      for (int j = i * i; j <= 2000100 - 10; j += i) {
        vis[j] = true;
      }
  }
  le[1] = 0;
  for (int i = 2; i <= 2000100 - 100; i++) le[i] = le[i - 1] + (!vis[i]);
  for (int i = 1; i <= 9; i++) ou[i] = i;
  ou[10] = 9;
  for (int i = 11; i < 2000100 - 10; i++) {
    int k = i, s = 0;
    while (k) {
      s = s * 10;
      s = s + k % 10;
      k = k / 10;
    }
    ou[i] = ou[i - 1] + (s == i);
  }
}
int main() {
  init();
  int q, w;
  while (~scanf("%d%d", &q, &w)) {
    int ans = 1, i;
    for (i = 1; i < 2000100 - 1000; i++) {
      if (le[i] * w <= ou[i] * q) ans = i;
    }
    printf("%d\n", ans);
  }
  return 0;
}

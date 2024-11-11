#include <bits/stdc++.h>
using namespace std;
const int maxn = 200000 + 10;
int num[maxn];
int rig[maxn];
int lef[maxn];
int main() {
  int n;
  while (~scanf("%d", &n)) {
    for (int i = 1; i <= n; i++) scanf("%d", &num[i]);
    int fl = -2 * maxn, fr = 2 * maxn;
    for (int i = 1; i <= n; i++) {
      if (num[i] == 0) fl = i;
      lef[i] = fl;
    }
    for (int i = n; i > 0; i--) {
      if (num[i] == 0) fr = i;
      rig[i] = fr;
    }
    for (int i = 1; i <= n; i++)
      printf(i == 1 ? "%d" : " %d", min(abs(rig[i] - i), abs(lef[i] - i)));
    printf("\n");
  }
}

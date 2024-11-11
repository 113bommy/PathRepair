#include <bits/stdc++.h>
using namespace std;
map<int, int> mp;
int a[100010];
int main() {
  int i = 0, j = 0;
  int n, m;
  while (scanf("%d%d", &n, &m) != EOF) {
    mp.clear();
    int f;
    for (i = 1; i <= n; ++i) {
      scanf("%d", &f);
      if (mp.find(f) != mp.end()) {
        mp[f] = -2;
      } else {
        mp[f] = i;
      }
    }
    int b;
    bool flag1 = false;
    bool flag2 = false;
    for (i = 1; i <= m; ++i) {
      scanf("%d", &b);
      if (!flag1) {
        if (mp.find(b) == mp.end()) {
          flag1 = true;
        } else if (-2 == mp[b]) {
          flag2 = true;
        } else {
          a[i] = mp[b];
        }
      }
    }
    if (flag1) {
      printf("Impossible\n");
    } else if (flag2) {
      printf("Ambiguity\n");
    } else {
      printf("Possible\n");
      for (int i = 1; i <= m; ++i) {
        printf("%d ", a[i]);
      }
      printf("\n");
    }
  }
  return 0;
}

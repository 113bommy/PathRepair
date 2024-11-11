#include <bits/stdc++.h>
using namespace std;
int n, m, aa, b;
int a[300];
int main() {
  while (scanf("%d%d", &n, &aa) != EOF) {
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    map<int, int> mp;
    int l = 1, now = 0;
    if (a[1] == aa) {
      printf("-1\n");
      continue;
    }
    for (int i = 2; i <= n;) {
      if (a[i] == aa) {
        int r = i;
        for (int j = l; j < r; j++) {
          if (mp[a[j]] == -1) continue;
          if (mp[a[j]] < now)
            mp[a[j]] = -1;
          else
            mp[a[j]]++;
        }
        int j = i;
        while (a[j] == aa && j <= n) {
          j++;
          now++;
        }
        l = j;
        i = j;
      } else
        i++;
    }
    int f = 0;
    for (int i = 1; i <= 1000000; i++) {
      if (mp[i] >= now && i != aa) {
        f = i;
        break;
      }
    }
    if (f == 0)
      printf("-1\n");
    else
      printf("%d\n", f);
  }
  return 0;
}

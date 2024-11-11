#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, s;
  while (~scanf("%d%d", &n, &s)) {
    int a[1010], b[1010];
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    if (a[1] == 0) {
      puts("NO");
      continue;
    }
    if (a[s] == 1) {
      puts("YEs");
      continue;
    }
    bool flag = false;
    if (b[s] == 1) {
      for (int i = s + 1; i <= n; i++) {
        if (a[i] == 1 && b[i] == 1) {
          flag = true;
          puts("yes");
          break;
        }
      }
    }
    if (flag == false) puts("no");
  }
}

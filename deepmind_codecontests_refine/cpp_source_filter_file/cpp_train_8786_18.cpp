#include <bits/stdc++.h>
using namespace std;
const int maxn = 100 + 10;
int a[maxn];
int main() {
  int n, x, y;
  int tot;
  while (~scanf("%d", &n)) {
    tot = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      tot += a[i];
    }
    cin >> x >> y;
    int tmp = 0;
    bool flag = 0;
    int fen = 0;
    for (int i = 1; i <= n; i++) {
      tmp += a[i];
      if (tmp >= x && tmp <= y && (tot - tmp) >= x && tmp <= y) {
        flag = 1;
        fen = i + 1;
        break;
      }
    }
    if (flag) {
      printf("%d\n", fen);
    } else {
      printf("0\n");
    }
  }
  return 0;
}

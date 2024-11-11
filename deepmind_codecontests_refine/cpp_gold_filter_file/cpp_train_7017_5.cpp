#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, i, color[1000021], c1, c2, c3, cnt;
  scanf("%d %d", &n, &m);
  for (i = 1; i <= m; i++) {
    scanf("%d %d %d", &c1, &c2, &c3);
    cnt = color[c1] + color[c2] + color[c3];
    if (color[c1] == 0) {
      cnt = cnt % 3 + 1;
      color[c1] = cnt;
    }
    if (color[c2] == 0) {
      cnt = cnt % 3 + 1;
      color[c2] = cnt;
    }
    if (color[c3] == 0) {
      cnt = cnt % 3 + 1;
      color[c3] = cnt;
    }
  }
  for (i = 1; i <= n; i++) cout << color[i] << " ";
}

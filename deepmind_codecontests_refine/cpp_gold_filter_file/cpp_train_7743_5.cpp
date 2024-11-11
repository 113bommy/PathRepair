#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y, i, ma = 0, cnt = 0;
  char g;
  scanf("%d %d", &x, &y);
  getchar();
  for (i = 0; i < x; i++) {
    g = getchar();
    if (g == '#') {
      cnt++;
      if (i == x - 1) {
        if (cnt > ma) ma = cnt;
      }
    } else if (g == '.') {
      if (cnt > ma) ma = cnt;
      cnt = 0;
    }
  }
  if (ma > y - 1)
    cout << "NO" << endl;
  else
    cout << "YES" << endl;
  return 0;
}

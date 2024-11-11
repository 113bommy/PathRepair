#include <bits/stdc++.h>
using namespace std;
int n, c, d;
int maxx = 0xffffff;
int minn = -maxx;
int flag = 0;
bool judge() {
  if (minn <= maxx)
    return true;
  else
    return false;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &c, &d);
    if (d == 1) {
      if (maxx < 1900) {
        printf("Impossible\n");
        return 0;
      }
      minn = max(minn, 1900);
    } else {
      if (minn >= 1900) {
        printf("Impossible\n");
        return 0;
      }
      maxx = min(maxx, 1899);
      flag = 1;
    }
    minn += c;
    maxx += c;
    if (!judge()) {
      printf("Impossible\n");
      return 0;
    }
  }
  if (!flag)
    printf("Infinity\n");
  else
    printf("%d\n", maxx);
  return 0;
}

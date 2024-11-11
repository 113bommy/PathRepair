#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int num;
int ans;
int main(void) {
  scanf("%d", &num);
  int x, y;
  int tot = 0;
  int cnt = 0;
  for (int i = 1; i <= 2 * num; i++) {
    scanf("%d.%d", &x, &y);
    tot += y;
    cnt += (y == 0);
  }
  if (cnt > num) {
    int ret = INF;
    for (int i = 0; i <= cnt; i++) {
      ret = min(ret, abs(tot - 1000 * i));
    }
    ans = ret;
  } else {
    int ret = INF;
    for (int i = num - cnt; i <= cnt; i++) {
      ret = min(ret, abs(tot - 1000 * i));
    }
    ans = ret;
  }
  printf("%.3lf", (double)ans / 1000);
  return 0;
}
